/*
 * Copyright (c) 2018, George Oikonomou - http://www.spd.gr
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
#ifndef CC26XX_CC13XX_BOOTLOADER_CONF_H_
#define CC26XX_CC13XX_BOOTLOADER_CONF_H_
/*---------------------------------------------------------------------------*/
/*
 * Limit the bootloader image to 0x2000 bytes. Needed by the C13xx/CC26xx
 * linker script
 */
#define FLASH_FW_ORIGIN  0x00000000
#define FLASH_FW_LENGTH  0x00002000

/* Total internal flash length */
#define INTERNAL_FLASH_LENGTH 0x00020000

/* Length of OTA metadata */
#define OTA_METADATA_LENGTH   0x00000010

/* Length of the CC13xx/CC26xx CCFG area, high 88 bytes on flash */
#define CCFG_LENGTH           0x00000058

/* Start offset of main firmware on internal flash */
#define MAIN_FW_OFFSET (FLASH_FW_ORIGIN + FLASH_FW_LENGTH)

/* Length of main firmware on internal flash, including CCFG and metadata */
#define MAIN_FW_LENGTH (INTERNAL_FLASH_LENGTH - FLASH_FW_LENGTH)

/*
 * Offset of OTA metadata from the start of any image (including one in
 * external flash
 */
#define OTA_METADATA_OFFSET (MAIN_FW_LENGTH - \
                             (CCFG_LENGTH - OTA_METADATA_LENGTH))

/* Absolute location of OTA metadata for the image on internal flash */
#define OTA_METADATA_LOC (MAIN_FW_OFFSET + OTA_METADATA_OFFSET)
/*---------------------------------------------------------------------------*/
#endif /* CC26XX_CC13XX_BOOTLOADER_CONF_H_ */
/*---------------------------------------------------------------------------*/