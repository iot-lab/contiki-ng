/*
 * This file is part of HiKoB Openlab.
 *
 * HiKoB Openlab is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, version 3.
 *
 * HiKoB Openlab is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with HiKoB Openlab. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2011,2012 HiKoB.
 */

/**
 * \file
 *         Configuration for HiKoB OpenLab platforms
 *
 * \author
 *         Antoine Fraboulet <antoine.fraboulet.at.hikob.com>
 *         Gaëtan Harter <gaetan.harter.at.inria.fr>
 *
 */

#ifndef CONTIKI_CONF_H_
#define CONTIKI_CONF_H_

#include <stdint.h>
/*---------------------------------------------------------------------------*/
/* Include Project Specific conf */
#ifdef PROJECT_CONF_PATH
#include PROJECT_CONF_PATH
#endif /* PROJECT_CONF_PATH */

/* ---------------------------------------- */
/*
 *  Clock module and rtimer support
 *
 */

#define CLOCK_CONF_SECOND 100

typedef unsigned int   clock_time_t;
typedef unsigned short rtimer_clock_t;

/* ---------------------------------------- */
/*
 * Cortex M3 / ARM
 *
 */

typedef uint8_t  u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef int8_t   s8_t;
typedef int16_t  s16_t;
typedef int32_t  s32_t;

#define CC_BYTE_ALIGNED __attribute__ ((packed, aligned(1)))
/* Prefix for relocation sections in ELF files */
#define REL_SECT_PREFIX ".rel"

/* Delay between GO signal and SFD
 * TODO: the current value is only a guess, needs actual measurement */
#define RADIO_DELAY_BEFORE_TX ((unsigned)US_TO_RTIMERTICKS(182))
/* Delay between GO signal and start listening
 * TODO: the current value is only a guess, needs actual measurement */
#define RADIO_DELAY_BEFORE_RX ((unsigned)US_TO_RTIMERTICKS(150))
/* Delay between the SFD finishes arriving and it is detected in software */
#define RADIO_DELAY_BEFORE_DETECT ((unsigned)US_TO_RTIMERTICKS(0))

/* ---------------------------------------- */

/*
 * Networking configuration inpired by cooja/contiki-conf.h
 */

#ifndef SLIP_ARCH_CONF_ENABLE
#define SLIP_ARCH_CONF_ENABLE 0
#endif
#define RF2XX_DEVICE rf231
#define SLIP_ARCH_CONF_UART uart_print

/*
 * Global Configuration networking
 */
typedef unsigned int uip_stats_t;
#define LINKADDR_CONF_SIZE          8

#define NETSTACK_CONF_RADIO         rf2xx_driver
/* Max payload of rf2xx is 125 bytes (128 -1 for length -2 for CRC) */
#define PACKETBUF_CONF_SIZE         125

#endif /* CONTIKI_CONF_H_ */
