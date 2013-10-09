/*
* Based on work by Dave Hansen <dave@sr71.net>
* original licensing:
* This software may be redistributed and/or modified under the terms of
 * the GNU General Public License ("GPL") version 2 as published by the
 * Free Software Foundation.
 */
#ifndef EYEFI_H
#define EYEFI_H

#include <stddef.h>
#include <stdlib.h>
#include "flt.h"

#define EYEFI_BUF_SIZE 16384

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

//big endian
#define host_to_be32(n) (n)

/*
 * The 'o' command has several sub-commands:
 */
enum card_info_subcommand {
	MAC_ADDRESS   = 1,
	FIRMWARE_INFO = 2,
	CARD_KEY      = 3,
	API_URL       = 4,
	UNKNOWN_5     = 5, // Chris says these are 
	UNKNOWN_6     = 6, // checksums
	LOG_LEN	      = 7,
	WLAN_DISABLE  = 10, // 1=disable 0=enable, write is 1 byte, read is var_byte
	UPLOAD_PENDING= 11, // {0x1, STATE}
	HOTSPOT_ENABLE= 12, // {0x1, STATE}
	CONNECTED_TO  = 13, // Currently connected Wifi network
	UPLOAD_STATUS = 14, // current uploading file info
	UNKNOWN_15    = 15, // always returns {0x01, 0x1d} as far as I've seen
	TRANSFER_MODE = 17,
	ENDLESS	      = 27, // 0x1b
	DIRECT_WAIT_FOR_CONNECTION = 0x24, // 0 == "direct mode off"
	DIRECT_WAIT_AFTER_TRANSFER = 0x25, // set to 60 when direct mode off
	UNKNOWN_ff    = 0xff, // The D90 does this, and it looks to
			      // return a 1-byte response length
			      // followed by a number of 8-byte responses
			      // But I've only ever seen a single response
			      // [000]: 01 04 1d 00 18 56 aa d5 42 00 00 00 00 00 00 00
			      // It could be a consolidates info command like "info for
			      // everything" so the camera makes fewer calls.
};

#define WPA_KEY_BYTES 32
struct wpa_key {
	u8 key[WPA_KEY_BYTES];
} __attribute__((packed));

#define WEP_40_KEY_BYTES 5
#define WEP_KEY_BYTES 13
struct wep_key {
	u8 key[WEP_KEY_BYTES];
} __attribute__((packed));

struct network_key {
	u8 len;
	union {
		struct wpa_key wpa;
		struct wep_key wep;
	};
} __attribute__((packed));

#define ESSID_LEN 32
struct scanned_net {
	char essid[ESSID_LEN];
	signed char strength;
	u8 type;
} __attribute__((packed));

typedef struct
{
    base_interface_t    base;

	int (*init)();
	void (*close)();
	int (*getAvailableNetworks)();
	int (*getConfiguredNetworks)();
	int (*getNetworkStatus)();
	int (*deleteNetwork)(char *SSID);
	int (*testNetwork)(char *SSID,char *pwd);
	int (*addNetwork)(char *SSID,char *pwd);
	int (*enableWlan)(int on);
	int (*wlanEnabled)(int *pEnabled);
	unsigned char *(*getBuf)();
} libeyefi_sym;

#define os_memset memset
#define os_memcpy memcpy
#define os_strlen strlen
#define os_strcpy strcpy

#define SHA1_MAC_LEN 20
#define MD5_MAC_LEN 16
void sha1_vector(size_t num_elem, const u8 *addr[], const size_t *len, u8 *mac);
void md5_vector(size_t num_elem, const u8 *addr[], const size_t *len, u8 *mac);
void hmac_md5_vector(const u8 *key, size_t key_len, size_t num_elem,
		     const u8 *addr[], const size_t *len, u8 *mac);
void hmac_md5(const u8 *key, size_t key_len, const u8 *data, size_t data_len,
	      u8 *mac);
void pbkdf2_sha1(const char *passphrase, const char *ssid, size_t ssid_len,
		 int iterations, u8 *buf, size_t buflen);

//-------------------------------------------------------------------

extern libeyefi_sym* libeyefi;

//-------------------------------------------------------------------
#endif
