#ifndef CONVERT_PNG_H
#define CONVERT_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char convert_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 
	0x00, 0x00, 0x00, 0x20, 0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 
	0x7A, 0x7A, 0xF4, 0x00, 0x00, 0x00, 0x04, 0x73, 0x42, 0x49, 
	0x54, 0x08, 0x08, 0x08, 0x08, 0x7C, 0x08, 0x64, 0x88, 0x00, 
	0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x00, 
	0xEC, 0x00, 0x00, 0x00, 0xEC, 0x01, 0x79, 0x28, 0x71, 0xBD, 
	0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 
	0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x77, 0x77, 0x77, 
	0x2E, 0x69, 0x6E, 0x6B, 0x73, 0x63, 0x61, 0x70, 0x65, 0x2E, 
	0x6F, 0x72, 0x67, 0x9B, 0xEE, 0x3C, 0x1A, 0x00, 0x00, 0x01, 
	0xAD, 0x49, 0x44, 0x41, 0x54, 0x58, 0x85, 0xED, 0xD7, 0xBF, 
	0x6B, 0x14, 0x41, 0x14, 0x07, 0xF0, 0x8F, 0x1E, 0xC4, 0x4A, 
	0x72, 0x49, 0xA9, 0x60, 0x4A, 0x51, 0xE2, 0x5F, 0x20, 0xA2, 
	0x20, 0x08, 0xFE, 0x0D, 0x31, 0x20, 0x96, 0x56, 0x36, 0x16, 
	0xDA, 0xA7, 0x48, 0x17, 0xF0, 0x4F, 0x10, 0xFF, 0x08, 0x35, 
	0x56, 0x62, 0x61, 0xED, 0x6F, 0x24, 0x95, 0x85, 0x20, 0xF1, 
	0x34, 0x76, 0x27, 0xC8, 0x5A, 0xCC, 0x0C, 0xBB, 0xB7, 0x66, 
	0xEF, 0x76, 0x6F, 0x56, 0x4E, 0x30, 0x5F, 0x18, 0xD8, 0x1D, 
	0xE6, 0xFB, 0xDE, 0x9B, 0xF7, 0xE6, 0xCD, 0x9B, 0xC7, 0x82, 
	0x71, 0xAC, 0xE3, 0xFA, 0x01, 0xD6, 0x71, 0x16, 0x43, 0xAC, 
	0xC4, 0xF9, 0x6F, 0xF8, 0x8E, 0xF7, 0x78, 0x83, 0x5F, 0x71, 
	0x7E, 0x13, 0x0F, 0xFB, 0x30, 0xE0, 0x3A, 0x6E, 0xE3, 0x12, 
	0x3E, 0x45, 0x45, 0xA3, 0xA8, 0x18, 0x4E, 0x62, 0x35, 0x1A, 
	0x77, 0x0A, 0x2F, 0xB0, 0x83, 0x67, 0x1D, 0x74, 0x34, 0x62, 
	0x1B, 0xEF, 0x70, 0x13, 0xCB, 0x2D, 0xD6, 0x2F, 0x0B, 0x3B, 
	0xFF, 0x80, 0x22, 0x57, 0x39, 0xC1, 0xA5, 0x6D, 0x14, 0x27, 
	0x6C, 0x44, 0xC5, 0x05, 0xF6, 0xFB, 0x30, 0xE0, 0xFF, 0xC0, 
	0x1A, 0x76, 0x31, 0x56, 0xBA, 0xAF, 0x3E, 0x0E, 0x70, 0xE5, 
	0x2F, 0xF1, 0xED, 0xE2, 0x1E, 0x96, 0xA6, 0x18, 0x59, 0xE0, 
	0x4B, 0x83, 0x90, 0x5C, 0xBE, 0xF1, 0x0C, 0x72, 0x5A, 0x73, 
	0xAD, 0x41, 0x48, 0x2E, 0xBF, 0x55, 0xBA, 0x3C, 0xC5, 0xFD, 
	0x06, 0x21, 0xB9, 0xFC, 0x09, 0x01, 0x7B, 0xF1, 0xFF, 0x63, 
	0x4D, 0xC0, 0x1A, 0x9E, 0x28, 0xE3, 0x7C, 0xD0, 0xD1, 0x80, 
	0x69, 0xFC, 0xB9, 0x2E, 0x8C, 0xA2, 0xE1, 0xBB, 0x13, 0xFF, 
	0xF8, 0x1C, 0xC4, 0x5E, 0x71, 0x98, 0x01, 0x7B, 0x4A, 0xF7, 
	0xA7, 0x70, 0xA4, 0x51, 0x0F, 0x4B, 0x36, 0x52, 0xA1, 0x28, 
	0x74, 0x2F, 0x1A, 0x55, 0x4E, 0x9D, 0x7F, 0xA1, 0x81, 0xF3, 
	0xAA, 0xCE, 0x5F, 0x78, 0x08, 0x12, 0x0E, 0xCB, 0x82, 0xBA, 
	0xDB, 0xAB, 0xA1, 0xA9, 0x73, 0x72, 0x0F, 0xF1, 0x51, 0x16, 
	0x4C, 0xA0, 0x7E, 0x11, 0x55, 0x43, 0xD2, 0x7B, 0x16, 0x24, 
	0x2C, 0x3C, 0x04, 0x3F, 0xCD, 0x2E, 0x26, 0x55, 0x9C, 0x10, 
	0xAE, 0xD4, 0x84, 0xB9, 0xF9, 0x83, 0x38, 0x71, 0x59, 0x78, 
	0x4C, 0xBE, 0x54, 0xBE, 0x68, 0x9B, 0xB0, 0x84, 0xBB, 0x42, 
	0xDE, 0xA7, 0x17, 0x6F, 0x2E, 0xFF, 0x8F, 0x42, 0x31, 0x6D, 
	0x8C, 0xF1, 0x18, 0x67, 0x2A, 0x42, 0x73, 0xF9, 0x47, 0x98, 
	0x8A, 0xAF, 0x4A, 0xF7, 0xDD, 0xE8, 0xC0, 0x1B, 0xE2, 0x75, 
	0x1F, 0x06, 0x14, 0x42, 0x93, 0xB1, 0xA9, 0x5D, 0x7F, 0x30, 
	0xC4, 0xAD, 0xC8, 0xD9, 0x9A, 0xB5, 0xB8, 0x4D, 0x05, 0x2C, 
	0x70, 0x15, 0x77, 0x70, 0x11, 0x9F, 0x85, 0x9D, 0x8D, 0xF0, 
	0x23, 0xCA, 0x58, 0x11, 0x5A, 0xB3, 0x73, 0x38, 0x8D, 0xE7, 
	0x78, 0x20, 0x1C, 0xCC, 0x6C, 0x03, 0x36, 0xF0, 0x28, 0x7E, 
	0x0F, 0x70, 0x5E, 0x68, 0x4E, 0x57, 0x4D, 0x36, 0xA7, 0x23, 
	0x61, 0xD7, 0x6F, 0xCD, 0x4E, 0xC5, 0x7F, 0x07, 0xBF, 0x01, 
	0x05, 0x0C, 0xA8, 0x8E, 0x48, 0xC1, 0x62, 0xF1, 0x00, 0x00, 
	0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};

wxBitmap& convert_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( convert_png, sizeof( convert_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //CONVERT_PNG_H
