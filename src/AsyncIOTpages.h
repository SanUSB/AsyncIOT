#define start_html_gz_len 245
const uint8_t start_html_gz[] PROGMEM = {
0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x6d,0x90,0x4f,0x4b,0xc4,0x30,0x10,0xc5,0xbf,0x4a,0xcc,0x49,0x0f,0x36,0x50,0x61,0x11,0xc9,0xe6,0xa0,0xee,0x82,0xa7,0x2d,0xd4,0x45,0x3c,0x4e,0xdb,0x69,0x1b,0xcc,0x3f,0x26,0x59,0x75,0xbf,0xbd,0xb1,0x29,0xa8,0xe0,0xe5,0xcd,0xf0,0x78,0xbf,0xe1,0x31,0xf2,0xe2,0xf1,0xf0,0xf0,0xfc,0xda,0xec,0xd8,0x9c,0xac,0x51,0x72,0x55,0x84,0x41,0x49,0xa3,0xdd,0x1b,0x23,0x34,0x5b,0xae,0x7b,0xef,0x38,0x4b,0xe7,0x80,0x79,0xb7,0x30,0xa1,0xf8,0xbc,0x2e,0xde,0x4c,0x38,0x6e,0xf9,0x9c,0x52,0xb8,0x13,0x22,0x82,0x3b,0xc5,0xae,0xea,0x8c,0x9f,0x62,0xf0,0xa9,0xea,0xbd,0xad,0x3a,0x12,0x23,0xbc,0x7f,0x87,0xab,0x2c,0x5c,0xc9,0xa4,0x93,0x41,0xd5,0x82,0x3b,0xb6,0xf7,0x95,0xa7,0x89,0x05,0x20,0xb0,0x98,0x90,0x22,0x0b,0xe4,0x7b,0x8c,0x51,0xbb,0x89,0x5d,0xee,0xda,0xe6,0xa6,0x66,0xe0,0x06,0x96,0xb7,0xdb,0x7a,0xb3,0xb9,0x92,0xa2,0xb0,0x52,0x94,0x7e,0x9d,0x1f,0xce,0xb9,0x6b,0xbd,0x1e,0xfb,0xff,0x50,0x0e,0xd7,0x4a,0x8e,0x9e,0x6c,0xe6,0xca,0xe8,0x48,0x49,0x58,0x9b,0x8b,0x05,0xe2,0xea,0x49,0x1c,0x58,0xf3,0xc3,0x37,0xbf,0x78,0x28,0xc4,0x1f,0xea,0x14,0x06,0x48,0xc8,0xd5,0x8b,0xde,0x6b,0xb6,0xd7,0x64,0x3f,0x80,0x90,0x1d,0x17,0x77,0x21,0x44,0x29,0x27,0x96,0x7f,0x7e,0x01,0xb6,0x8c,0x17,0xbb,0x65,0x01,0x00,0x00
}; //HTML Minification. More informations in: https://www.youtube.com/watch?v=HwZVmrcntKo and https://www.youtube.com/watch?v=oc0Ox725sG .

#define main_html_gz_len 280
const uint8_t main_html_gz[] PROGMEM = {
0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x5d,0x50,0x4d,0x4b,0xc4,0x30,0x10,0xfd,0x2b,0x63,0x4e,0x7a,0xb0,0x81,0x0a,0x8b,0x2c,0x69,0x0e,0xea,0x1e,0xbc,0x68,0xa1,0x7a,0xf0,0x38,0xe9,0xa6,0xdd,0x60,0x3e,0x4a,0x32,0x5d,0x76,0xff,0xbd,0x69,0x53,0x44,0xbc,0x0c,0x33,0xc3,0x7b,0x8f,0xf7,0x9e,0xb8,0x79,0x79,0x7f,0xfe,0xf8,0x6a,0x0f,0x70,0x22,0x67,0xa5,0xd8,0xa6,0xc6,0xa3,0x14,0xd6,0xf8,0x6f,0x88,0xda,0x36,0xcc,0xf4,0xc1,0x33,0xa0,0xeb,0xa4,0xf3,0xee,0x70,0xd4,0xfc,0x72,0x5f,0x7e,0xa7,0xa8,0x87,0x86,0x9d,0x88,0xa6,0x3d,0xe7,0x09,0xfd,0x9c,0x54,0xa5,0x6c,0x18,0xd3,0x14,0xa8,0xea,0x83,0xab,0x54,0xe4,0x03,0x9e,0x17,0x70,0x95,0x07,0x93,0x82,0x0c,0x59,0x2d,0x3b,0xf4,0x9f,0xdd,0x53,0x15,0xe2,0x08,0x13,0x46,0x74,0x9a,0x74,0x4c,0x30,0xc5,0xd0,0xeb,0x94,0x8c,0x1f,0xe1,0xf6,0xd0,0xb5,0x0f,0x35,0xa0,0x3f,0x42,0xde,0x1e,0xeb,0xdd,0xee,0x4e,0xf0,0xc2,0x15,0xbc,0xf8,0x53,0xe1,0x78,0xcd,0x5e,0x6b,0xf9,0xea,0xa7,0x99,0xfe,0xe8,0x64,0x40,0x2d,0xc5,0x10,0xa2,0x03,0xec,0xc9,0x04,0xdf,0x30,0xde,0xa3,0xed,0x99,0x7c,0x9b,0x9d,0xd2,0x11,0xc2,0x00,0x2b,0x27,0xed,0x85,0x8a,0x52,0x98,0x95,0x5f,0xe2,0x91,0xbe,0x10,0x03,0x9f,0x95,0x1a,0xb6,0x29,0xc6,0x90,0x18,0x9c,0xd1,0xce,0xf9,0x95,0x03,0x2c,0x8c,0xff,0xac,0x34,0x2b,0x67,0xe8,0x17,0xd5,0x95,0x33,0x3b,0x5d,0x4c,0x14,0x38,0x6e,0x5d,0x71,0x26,0x3b,0xc2,0x48,0xd0,0xe6,0x1e,0x05,0xc7,0x0c,0x2a,0x41,0xf8,0xda,0xfd,0x0f,0xd4,0x08,0x1c,0x6c,0x91,0x01,0x00,0x00
};

#define grava_html_gz_len 311
const uint8_t grava_html_gz[] PROGMEM = {
0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x6d,0x91,0x41,0x4f,0xc4,0x20,0x10,0x85,0xff,0xca,0xc8,0x49,0x0f,0x5b,0x92,0x9a,0x6c,0x8c,0xa1,0x1c,0x56,0xd7,0xc4,0xd3,0x36,0xe9,0x6e,0x8c,0x47,0xda,0xd2,0x96,0x48,0x81,0xc0,0x74,0xe3,0xfe,0x7b,0x67,0xdb,0x46,0x63,0xf4,0xc0,0x64,0x80,0xef,0xc1,0xe3,0x21,0x6e,0x9e,0x0f,0x4f,0xc7,0xf7,0x72,0x0f,0x03,0x8e,0x56,0x8a,0xb5,0x6a,0xd5,0x4a,0x61,0x8d,0xfb,0x80,0xa8,0x6d,0xc1,0x4c,0xe3,0x1d,0x03,0xbc,0x04,0x4d,0xfd,0xa8,0x7a,0xcd,0x3f,0x37,0xcb,0xda,0x10,0x75,0x57,0xb0,0x01,0x31,0x3c,0x72,0x9e,0x94,0x9b,0x52,0x9d,0xd5,0xd6,0xf7,0x29,0x78,0xcc,0x1a,0x3f,0x66,0x75,0xe4,0x9d,0x3a,0x5f,0xe1,0x8c,0x0a,0x93,0x02,0x0d,0x5a,0x2d,0x2b,0xe5,0x4e,0xd5,0x2e,0xf3,0xb1,0x87,0xa0,0xa2,0x1a,0x35,0xea,0x98,0x20,0x44,0xdf,0xe8,0x94,0x8c,0xeb,0xe1,0x76,0x5f,0x95,0xf7,0x39,0x28,0xd7,0x02,0x75,0x0f,0xf9,0x76,0x7b,0x27,0xf8,0xa2,0x15,0x7c,0xf1,0x57,0xfb,0xf6,0x42,0x5e,0x73,0xf9,0x07,0x85,0x37,0xf3,0x62,0xe0,0x14,0x5a,0x85,0x9a,0xe8,0x5c,0x8a,0xce,0xc7,0x11,0xe8,0x96,0xc1,0xb7,0x05,0x2b,0x0f,0xd5,0x91,0x81,0x6a,0xd0,0x78,0x57,0x30,0x3e,0xcd,0x1c,0x03,0xed,0x9a,0xe5,0x89,0xe3,0x64,0xd1,0x90,0x2d,0xe4,0x57,0xd9,0x86,0x76,0x15,0x19,0x37,0x2e,0x4c,0xb8,0x86,0xd0,0x19,0x4b,0x02,0x47,0xbe,0x0b,0xb6,0xca,0x25,0xfc,0x22,0xd2,0x54,0x8f,0x06,0x19,0x9c,0x95,0x9d,0x68,0x7a,0x5a,0x21,0x31,0x1f,0x49,0xde,0xe3,0x32,0xd4,0x9a,0x20,0x9f,0x53,0x60,0xf2,0x95,0x1f,0xa0,0xfc,0x09,0xa4,0xfc,0x0e,0x44,0x70,0xf5,0x8f,0x8a,0xc9,0x0a,0xc9,0x27,0x65,0xd8,0xeb,0x99,0xe0,0x4b,0x28,0x7c,0xfe,0xc7,0x2f,0x79,0x92,0x55,0x69,0xdd,0x01,0x00,0x00
};
