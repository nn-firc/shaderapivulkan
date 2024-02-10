#pragma once

#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#elif defined( LINUX )
#define VK_USE_PLATFORM_XLIB_KHR
#endif
#include <vulkan/vulkan.hpp>

extern VkAllocationCallbacks* g_pAllocCallbacks;

extern const char* const* GetValidationLayers();
extern uint32_t GetValidationLayerCount();

void InitValidationLayers();

static void vkCheck(VkResult result)
{
	if (result != VK_SUCCESS)
		*(int*)0 = 0;
}

#include "bitmap/imageformat.h"

static ImageFormat vkfmt2imgfmt(VkFormat format)
{
	static ImageFormat conversions[] =
	{
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
		IMAGE_FORMAT_UNKNOWN,
	};
	return conversions[(size_t)format];
}

static VkFormat imgfmt2vkfmt(ImageFormat format)
{
	static VkFormat conversions[] =
	{
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_R8G8B8A8_UNORM,
		VK_FORMAT_UNDEFINED, // non existent
		VK_FORMAT_R8G8B8_UNORM,
		VK_FORMAT_B8G8R8_UNORM,
		VK_FORMAT_R5G6B5_UNORM_PACK16,
		VK_FORMAT_R8_UNORM,
		VK_FORMAT_R8G8_UNORM,
		VK_FORMAT_R8_UNORM,
		VK_FORMAT_R8_UNORM,
		VK_FORMAT_R8G8B8A8_UNORM,
		VK_FORMAT_B8G8R8_UNORM,
		VK_FORMAT_R8G8B8A8_UNORM,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_B8G8R8A8_UNORM,
		VK_FORMAT_B5G6R5_UNORM_PACK16,
		VK_FORMAT_B5G5R5A1_UNORM_PACK16,
		VK_FORMAT_B4G4R4A4_UNORM_PACK16,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_B5G5R5A1_UNORM_PACK16,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_R16G16B16A16_SFLOAT,
		VK_FORMAT_R16G16B16A16_UNORM,
		VK_FORMAT_UNDEFINED,
		VK_FORMAT_R32_SFLOAT,
		VK_FORMAT_R32G32B32_SFLOAT,
		VK_FORMAT_R32G32B32A32_SFLOAT,

		// todo: depth formats
	};

	return conversions[(size_t)format];
}
