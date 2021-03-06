/***************************************************************************//**
 *   @file   ad4110.h
 *   @brief  Implementation of AD4110 Driver.
 *   @author SPopa (stefan.popa@analog.com)
********************************************************************************
 * Copyright 2016(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef AD4110_H_
#define AD4110_H_

/******************************************************************************/
/********************** Macros and Constants Definitions **********************/
/******************************************************************************/

#define AD4110_CMD_WR_COM_REG(x)	(0x00 | ((x) & 0xF)) // Write to Register x 
#define AD4110_CMD_READ_COM_REG(x)	(0x40 | ((x) & 0xF)) // Read from Register x 

/* Register map */ 
#define A4110_ADC 0x00
#define A4110_AFE 0x01

/*************************** AFE Register Map *****************************/

#define AD4110_REG_AFE_TOP_STATUS 				0x0
#define AD4110_REG_AFE_CNTRL1					0x1
#define AD4110_REG_AFE_CLK_CTRL					0x3
#define AD4110_REG_AFE_CNTRL2 					0x4
#define AD4110_REG_PGA_RTD_CTRL					0x5
#define AD4110_REG_AFE_ERR_DISABLE				0x6
#define AD4110_REG_AFE_DETAIL_STATUS			0x7 
#define AD4110_REG_AFE_CAL_DATA					0xC
#define AD4110_REG_AFE_RSENSE_DATA				0xD
#define AD4110_REG_AFE_NO_PWR_DEFAULT_SEL		0xE
#define AD4110_REG_AFE_NO_PWR_DEFAULT_STATUS	0xF


/*************************** ADC Register Map *****************************/

#define AD4110_REG_ADC_STATUS 					0x0
#define AD4110_REG_ADC_MODE						0x1
#define AD4110_REG_ADC_INTERFACE				0x2
#define AD4110_REG_ADC_CONFIG					0x3
#define AD4110_REG_DATA							0x4
#define AD4110_REG_FILTER						0x5
#define AD4110_REG_ADC_GPIO_CONFIG				0x6
#define AD4110_REG_ID							0x7
#define AD4110_ADC_OFFSET0						0x8
#define AD4110_ADC_OFFSET1						0x9
#define AD4110_ADC_OFFSET2						0xA
#define AD4110_ADC_OFFSET3						0xB
#define AD4110_ADC_GAIN0						0xC
#define AD4110_ADC_GAIN1						0xD
#define AD4110_ADC_GAIN2						0xE
#define AD4110_ADC_GAIN3						0xF

/* AFE_CNTRL1 Register */
#define AD4110_REG_AFE_CNTRL1_CRC_EN			(1 << 14)
#define AD4110_REG_AFE_CNTRL1_DISRTD			(1 << 9)

/* AFE_CLK_CTRL Register */
#define AD4110_REG_AFE_CLK_CTRL_CFG(x)			(((x) & 0x3) << 3)

/* AFE_CNTRL2 Register */
#define AD4110_REG_AFE_CNTRL2_IMODE_MSK 		(1 << 1)
#define AD4110_REG_AFE_CNTRL2_EXT_R_SEL_MSK 	(1 << 2)
#define AD4110_REG_AFE_CNTRL2_EN_FLD_PWR_MSK 	(1 << 3)
#define AD4110_AFE_VBIAS(x) 					(((x) & 0x3) << 6)
#define AD4110_AFE_VBIAS_ON 					0x1
#define AD4110_AFE_VBIAS_DEFAULT_OFF			0x2
#define AD4110_AFE_VBIAS_OFF		 			0x3
#define AD4110_REG_AFE_CNTRL2_AINP_UP1			(1 << 8)
#define AD4110_REG_AFE_CNTRL2_AINP_UP100		(1 << 9)
#define AD4110_REG_AFE_CNTRL2_AINP_DN1			(1 << 10)
#define AD4110_REG_AFE_CNTRL2_AINP_DN100		(1 << 11)
#define AD4110_REG_AFE_CNTRL2_AINN_UP1			(1 << 12)
#define AD4110_REG_AFE_CNTRL2_AINN_UP100		(1 << 13)
#define AD4110_REG_AFE_CNTRL2_AINN_DN1			(1 << 14)
#define AD4110_REG_AFE_CNTRL2_AINN_DN100		(1 << 15)

/* PGA_RTD_CTRL Register */
#define AD4110_REG_PGA_RTD_CTRL_23W_EN_MSK		(1 << 15)
#define AD4110_REG_PGA_RTD_CTRL_I_COM_SEL(x)	(((x) & 0x7) << 12)
#define AD4110_REG_PGA_RTD_CTRL_I_EXC_SEL(x)	(((x) & 0x7) << 9)
#define AD4110_REG_PGA_RTD_CTRL_EXT_RTD			(1 << 8)
#define AD4110_REG_PGA_RTD_CTRL_GAIN_CH(x)		(((x) & 0xF) << 4)
#define AD4110_REG_PGA_RTD_CTRL_GAIN_CH_MSK     0xF0

/* AFE_ERR_DISABLE Register */
#define AD4110_REG_AFE_ERR_DIS_AIN_OC			(1 << 1)
#define AD4110_REG_AFE_ERR_DIS_FLD_PWR_OC		(1 << 2)
#define AD4110_REG_AFE_ERR_DIS_I_COM			(1 << 6)
#define AD4110_REG_AFE_ERR_DIS_I_EXC			(1 << 7)
#define AD4110_REG_AFE_ERR_DIS_AINP_OV			(1 << 8)
#define AD4110_REG_AFE_ERR_DIS_AINN_OV			(1 << 9)
#define AD4110_REG_AFE_ERR_DIS_AINP_UV			(1 << 10)
#define AD4110_REG_AFE_ERR_DIS_AINN_UV			(1 << 11)

/* NO_PWR_DEFAULT_SEL Register */
#define AD4110_REG_NO_PWR_DEFAULT_SEL_MSK		0xFF

/* ADC_MODE Register */
#define AD4110_REG_ADC_MODE_MSK					0x70
#define AD4110_ADC_MODE(x)						(((x) & 0x7) << 4)
#define AD4110_REG_ADC_MODE_REF_EN				(1 << 15)
#define AD4110_REG_ADC_DELAY					(((x) & 0x7) << 8)
#define AD4110_REG_ADC_CLK_SEL					(((x) & 0x3) << 3)

/* ADC_INTERFACE Register */
#define AD4110_REG_ADC_INTERFACE_CRC_EN_MSK		0x0C
#define AD4110_ADC_CRC_EN(x)					(((x) & 0x3) << 2)
#define AD4110_REG_ADC_INTERFACE_WL16_MSK		0x01
#define AD4110_REG_ADC_INTERFACE_DS_MSK			0x40
#define AD4110_DATA_STAT_EN						(1 << 6)

/* ADC_CONFIG Register */
#define AD4110_REG_ADC_CONFIG_CHAN_EN_MSK		0xF
#define AD4110_REG_ADC_CONFIG_CHAN_EN_0			(1 << 0)
#define AD4110_REG_ADC_CONFIG_CHAN_EN_1			(1 << 1)
#define AD4110_REG_ADC_CONFIG_CHAN_EN_2			(1 << 2)
#define AD4110_REG_ADC_CONFIG_CHAN_EN_3			(1 << 3)
#define AD4110_REG_ADC_CONFIG_REF_SEL(x)		((((x) & 0x3) << 4)
#define AD4110_REG_ADC_CONFIG_BIT_6				(1 << 6)
#define AD4110_REG_ADC_CONFIG_AIN_BUFF(x)		((((x) & 0x3) << 10)
#define AD4110_REG_ADC_CONFIG_BI_UNIPOLAR		(1 << 12)

/* ADC_FILTER Register */
#define AD4110_REG_ADC_FILTER_ODR(x)			(((x) & 0x1F) << 0)
#define AD4110_REG_ADC_FILTER_ORDER(x)			(((x) & 0x3) << 5)
#define AD4110_REG_ADC_FILTER_SEL_ENH(x)		(((x) & 0x7) << 8)
#define AD4110_REG_ADC_FILTER_EN_ENH			(1 << 11)

/* ADC_GPIO_CONFIG Register */
#define AD4110_REG_GPIO_CONFIG_ERR_EN(x)		((((x) & 0x3) << 9)
#define AD4110_REG_GPIO_CONFIG_SYNC_EN			(1 << 11)

/* 8-bits wide checksum generated using the polynomial */
#define AD4110_CRC8_POLY	0x07 // x^8 + x^2 + x^1 + x^0

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

typedef enum {
	AD4110_DISABLE,
	AD4110_ENABLE
} ad4110_state;

typedef enum {
	AD4110_DATA_WL24,
	AD4110_DATA_WL16,
} ad4110_data_word_length;

typedef enum {
	AD4110_CONTINOUS_CONV_MODE,
	AD4110_SINGLE_CONV_MODE,
	AD4110_STANDBY_MODE,
	AD4110_PW_DOWN_MODE,
	AD4110_SYS_OFFSET_CAL = 6,
	AD4110_SYS_GAIN_CAL
} ad4110_adc_mode;

typedef enum {
	AD4110_VOLTAGE_MODE,
	AD4110_CURRENT_MODE,
	AD4110_CURRENT_MODE_EXT_R_SEL,
	AD4110_THERMOCOUPLE,
	AD4110_FLD_POWER_MODE,
	AD4110_RTD_2W_MODE,
	AD4110_RTD_3W_MODE,
	AD4110_RTD_4W_MODE	
} ad4110_op_mode;

typedef enum {
	AD4110_ADC_CRC_DISABLE,
	AD4110_ADC_XOR_CRC,  // 8-bit XOR checksum on reads, 8-bit CRC on writes	
	AD4110_ADC_CRC_CRC // 8-bit CRC on reads and writes.
}ad4110_adc_crc_mode;

typedef enum {
	AD4110_AFE_CRC_DISABLE,
	AD4110_AFE_CRC 	// 8-bit CRC on reads and writes.
}ad4110_afe_crc_mode;

typedef enum{
	AD4110_GAIN_0_2,
	AD4110_GAIN_0_25,
	AD4110_GAIN_0_3,
	AD4110_GAIN_0_375,
	AD4110_GAIN_0_5,
	AD4110_GAIN_0_75,
	AD4110_GAIN_1,
	AD4110_GAIN_1_5,
	AD4110_GAIN_2,
	AD4110_GAIN_3,
	AD4110_GAIN_4,
	AD4110_GAIN_6,
	AD4110_GAIN_8,
	AD4110_GAIN_12,
	AD4110_GAIN_16,
	AD4110_GAIN_24
}ad4110_gain;

typedef struct {
	/* SPI */
	spi_device					spi_dev;
	/* GPIO */
	gpio_device					gpio_dev;
	int8_t						gpio_reset;
	/* Device Settings */
	ad4110_state				data_stat;
	ad4110_data_word_length 	data_length;
	ad4110_adc_crc_mode 		adc_crc_en;
	ad4110_afe_crc_mode			afe_crc_en;
	ad4110_op_mode 				op_mode;
	ad4110_gain 				gain;
} ad4110_dev;

typedef struct {
	/* SPI */
	uint8_t						spi_chip_select;
	spi_mode					spi_mode;
	spi_type					spi_type;
	uint32_t					spi_device_id;
	/* GPIO */
	gpio_type					gpio_type;
	uint32_t					gpio_device_id;
	int8_t						gpio_reset;
	/* Device Settings */
	ad4110_state				data_stat;
	ad4110_data_word_length 	data_length;
	ad4110_afe_crc_mode			afe_crc_en;
	ad4110_adc_crc_mode			adc_crc_en;
	ad4110_op_mode 				op_mode;
	ad4110_gain 				gain;
} ad4110_init_param;

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/
/* Compute CRC8 checksum. */								 
uint8_t ad4110_compute_crc8(uint8_t *data,
							uint8_t data_size);	
/* Compute XOR checksum. */
uint8_t ad4110_compute_xor(uint8_t *data,
						   uint8_t data_size);

/* Set the mode of the ADC. */
int32_t ad4110_set_adc_mode(ad4110_dev *dev, ad4110_adc_mode mode);

/* Set the gain. */
int32_t ad4110_set_gain(ad4110_dev *dev, ad4110_gain gain);

/* Set the operation mode. */
int32_t ad4110_set_op_mode(ad4110_dev *dev, ad4110_op_mode mode);

/* Do a SPI software reset. */
int32_t ad4110_spi_do_soft_reset(ad4110_dev *dev);

/* Get the data size of a specified register. */
uint8_t ad4110_get_data_size(ad4110_dev *dev,
							 uint8_t reg_map,
							 uint8_t reg_addr);

/* SPI write to device using a mask. */
int32_t ad4110_spi_reg_write_msk(ad4110_dev *dev,
									 uint8_t reg_map,
								 	 uint8_t reg_addr,
								 	 uint32_t data,
									 uint16_t mask);

/* SPI internal register write to device. */
int32_t ad4110_spi_reg_write(ad4110_dev *dev,
								 uint8_t reg_map,
								 uint8_t reg_addr,
								 uint32_t reg_data);

/* SPI internal register read from device. */
int32_t ad4110_spi_reg_read(ad4110_dev *dev,
								uint8_t reg_map,
								uint8_t reg_addr,
								uint32_t *reg_data);

/* Initialize the device. */
int32_t ad4110_setup(ad4110_dev **device,
					 ad4110_init_param init_param);

#endif // AD4110_H_