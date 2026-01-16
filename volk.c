/* This file is part of volk library; see volk.h for version/license details */
/* clang-format off */
#include "volk.h"

#ifdef _WIN32
	typedef const char* LPCSTR;
	typedef struct HINSTANCE__* HINSTANCE;
	typedef HINSTANCE HMODULE;
	#if defined(_MINWINDEF_)
		/* minwindef.h defines FARPROC, and attempting to redefine it may conflict with -Wstrict-prototypes */
	#elif defined(_WIN64)
		typedef __int64 (__stdcall* FARPROC)(void);
	#else
		typedef int (__stdcall* FARPROC)(void);
	#endif
#else
#	include <dlfcn.h>
#endif

#ifdef __APPLE__
#	include <stdlib.h>
#endif

#if defined(VOLK_IN_LOADERS_CLOTH)
#include <pthread.h>
#endif

#include <string.h>

#ifdef _WIN32
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR);
__declspec(dllimport) FARPROC __stdcall GetProcAddress(HMODULE, LPCSTR);
__declspec(dllimport) int __stdcall FreeLibrary(HMODULE);
#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
#ifdef VOLK_NAMESPACE
namespace volk {
#else
extern "C" {
#endif
#endif

#if defined(__GNUC__)
#    define VOLK_DISABLE_GCC_PEDANTIC_WARNINGS \
		_Pragma("GCC diagnostic push") \
		_Pragma("GCC diagnostic ignored \"-Wpedantic\"")
#    define VOLK_RESTORE_GCC_PEDANTIC_WARNINGS \
		_Pragma("GCC diagnostic pop")
#else
#    define VOLK_DISABLE_GCC_PEDANTIC_WARNINGS
#    define VOLK_RESTORE_GCC_PEDANTIC_WARNINGS
#endif

static void* loadedModule = NULL;
static VkInstance loadedInstance = VK_NULL_HANDLE;
static VkDevice loadedDevice = VK_NULL_HANDLE;

static void volkGenLoadLoader(void* context, PFN_vkVoidFunction (*load)(void*, const char*));
static void volkGenLoadInstance(void* context, PFN_vkVoidFunction (*load)(void*, const char*));
static void volkGenLoadInstanceTable(struct VolkInstanceTable* table, void* context, PFN_vkVoidFunction (*load)(void*, const char*));
static void volkGenLoadDevice(void* context, PFN_vkVoidFunction (*load)(void*, const char*));
static void volkGenLoadDeviceTable(struct VolkDeviceTable* table, void* context, PFN_vkVoidFunction (*load)(void*, const char*));


#if defined(VOLK_IN_LOADERS_CLOTH)
	/* VOLK_GENERATE_DECLODATION_C_VILC */
#if defined(VK_VERSION_1_0)
static PFN_vkAllocateCommandBuffers vilc_vkAllocateCommandBuffers = NULL;
static PFN_vkAllocateDescriptorSets vilc_vkAllocateDescriptorSets = NULL;
static PFN_vkAllocateMemory vilc_vkAllocateMemory = NULL;
static PFN_vkBeginCommandBuffer vilc_vkBeginCommandBuffer = NULL;
static PFN_vkBindBufferMemory vilc_vkBindBufferMemory = NULL;
static PFN_vkBindImageMemory vilc_vkBindImageMemory = NULL;
static PFN_vkCmdBeginQuery vilc_vkCmdBeginQuery = NULL;
static PFN_vkCmdBeginRenderPass vilc_vkCmdBeginRenderPass = NULL;
static PFN_vkCmdBindDescriptorSets vilc_vkCmdBindDescriptorSets = NULL;
static PFN_vkCmdBindIndexBuffer vilc_vkCmdBindIndexBuffer = NULL;
static PFN_vkCmdBindPipeline vilc_vkCmdBindPipeline = NULL;
static PFN_vkCmdBindVertexBuffers vilc_vkCmdBindVertexBuffers = NULL;
static PFN_vkCmdBlitImage vilc_vkCmdBlitImage = NULL;
static PFN_vkCmdClearAttachments vilc_vkCmdClearAttachments = NULL;
static PFN_vkCmdClearColorImage vilc_vkCmdClearColorImage = NULL;
static PFN_vkCmdClearDepthStencilImage vilc_vkCmdClearDepthStencilImage = NULL;
static PFN_vkCmdCopyBuffer vilc_vkCmdCopyBuffer = NULL;
static PFN_vkCmdCopyBufferToImage vilc_vkCmdCopyBufferToImage = NULL;
static PFN_vkCmdCopyImage vilc_vkCmdCopyImage = NULL;
static PFN_vkCmdCopyImageToBuffer vilc_vkCmdCopyImageToBuffer = NULL;
static PFN_vkCmdCopyQueryPoolResults vilc_vkCmdCopyQueryPoolResults = NULL;
static PFN_vkCmdDispatch vilc_vkCmdDispatch = NULL;
static PFN_vkCmdDispatchIndirect vilc_vkCmdDispatchIndirect = NULL;
static PFN_vkCmdDraw vilc_vkCmdDraw = NULL;
static PFN_vkCmdDrawIndexed vilc_vkCmdDrawIndexed = NULL;
static PFN_vkCmdDrawIndexedIndirect vilc_vkCmdDrawIndexedIndirect = NULL;
static PFN_vkCmdDrawIndirect vilc_vkCmdDrawIndirect = NULL;
static PFN_vkCmdEndQuery vilc_vkCmdEndQuery = NULL;
static PFN_vkCmdEndRenderPass vilc_vkCmdEndRenderPass = NULL;
static PFN_vkCmdExecuteCommands vilc_vkCmdExecuteCommands = NULL;
static PFN_vkCmdFillBuffer vilc_vkCmdFillBuffer = NULL;
static PFN_vkCmdNextSubpass vilc_vkCmdNextSubpass = NULL;
static PFN_vkCmdPipelineBarrier vilc_vkCmdPipelineBarrier = NULL;
static PFN_vkCmdPushConstants vilc_vkCmdPushConstants = NULL;
static PFN_vkCmdResetEvent vilc_vkCmdResetEvent = NULL;
static PFN_vkCmdResetQueryPool vilc_vkCmdResetQueryPool = NULL;
static PFN_vkCmdResolveImage vilc_vkCmdResolveImage = NULL;
static PFN_vkCmdSetBlendConstants vilc_vkCmdSetBlendConstants = NULL;
static PFN_vkCmdSetDepthBias vilc_vkCmdSetDepthBias = NULL;
static PFN_vkCmdSetDepthBounds vilc_vkCmdSetDepthBounds = NULL;
static PFN_vkCmdSetEvent vilc_vkCmdSetEvent = NULL;
static PFN_vkCmdSetLineWidth vilc_vkCmdSetLineWidth = NULL;
static PFN_vkCmdSetScissor vilc_vkCmdSetScissor = NULL;
static PFN_vkCmdSetStencilCompareMask vilc_vkCmdSetStencilCompareMask = NULL;
static PFN_vkCmdSetStencilReference vilc_vkCmdSetStencilReference = NULL;
static PFN_vkCmdSetStencilWriteMask vilc_vkCmdSetStencilWriteMask = NULL;
static PFN_vkCmdSetViewport vilc_vkCmdSetViewport = NULL;
static PFN_vkCmdUpdateBuffer vilc_vkCmdUpdateBuffer = NULL;
static PFN_vkCmdWaitEvents vilc_vkCmdWaitEvents = NULL;
static PFN_vkCmdWriteTimestamp vilc_vkCmdWriteTimestamp = NULL;
static PFN_vkCreateBuffer vilc_vkCreateBuffer = NULL;
static PFN_vkCreateBufferView vilc_vkCreateBufferView = NULL;
static PFN_vkCreateCommandPool vilc_vkCreateCommandPool = NULL;
static PFN_vkCreateComputePipelines vilc_vkCreateComputePipelines = NULL;
static PFN_vkCreateDescriptorPool vilc_vkCreateDescriptorPool = NULL;
static PFN_vkCreateDescriptorSetLayout vilc_vkCreateDescriptorSetLayout = NULL;
static PFN_vkCreateDevice vilc_vkCreateDevice = NULL;
static PFN_vkCreateEvent vilc_vkCreateEvent = NULL;
static PFN_vkCreateFence vilc_vkCreateFence = NULL;
static PFN_vkCreateFramebuffer vilc_vkCreateFramebuffer = NULL;
static PFN_vkCreateGraphicsPipelines vilc_vkCreateGraphicsPipelines = NULL;
static PFN_vkCreateImage vilc_vkCreateImage = NULL;
static PFN_vkCreateImageView vilc_vkCreateImageView = NULL;
static PFN_vkCreateInstance vilc_vkCreateInstance = NULL;
static PFN_vkCreatePipelineCache vilc_vkCreatePipelineCache = NULL;
static PFN_vkCreatePipelineLayout vilc_vkCreatePipelineLayout = NULL;
static PFN_vkCreateQueryPool vilc_vkCreateQueryPool = NULL;
static PFN_vkCreateRenderPass vilc_vkCreateRenderPass = NULL;
static PFN_vkCreateSampler vilc_vkCreateSampler = NULL;
static PFN_vkCreateSemaphore vilc_vkCreateSemaphore = NULL;
static PFN_vkCreateShaderModule vilc_vkCreateShaderModule = NULL;
static PFN_vkDestroyBuffer vilc_vkDestroyBuffer = NULL;
static PFN_vkDestroyBufferView vilc_vkDestroyBufferView = NULL;
static PFN_vkDestroyCommandPool vilc_vkDestroyCommandPool = NULL;
static PFN_vkDestroyDescriptorPool vilc_vkDestroyDescriptorPool = NULL;
static PFN_vkDestroyDescriptorSetLayout vilc_vkDestroyDescriptorSetLayout = NULL;
static PFN_vkDestroyDevice vilc_vkDestroyDevice = NULL;
static PFN_vkDestroyEvent vilc_vkDestroyEvent = NULL;
static PFN_vkDestroyFence vilc_vkDestroyFence = NULL;
static PFN_vkDestroyFramebuffer vilc_vkDestroyFramebuffer = NULL;
static PFN_vkDestroyImage vilc_vkDestroyImage = NULL;
static PFN_vkDestroyImageView vilc_vkDestroyImageView = NULL;
static PFN_vkDestroyInstance vilc_vkDestroyInstance = NULL;
static PFN_vkDestroyPipeline vilc_vkDestroyPipeline = NULL;
static PFN_vkDestroyPipelineCache vilc_vkDestroyPipelineCache = NULL;
static PFN_vkDestroyPipelineLayout vilc_vkDestroyPipelineLayout = NULL;
static PFN_vkDestroyQueryPool vilc_vkDestroyQueryPool = NULL;
static PFN_vkDestroyRenderPass vilc_vkDestroyRenderPass = NULL;
static PFN_vkDestroySampler vilc_vkDestroySampler = NULL;
static PFN_vkDestroySemaphore vilc_vkDestroySemaphore = NULL;
static PFN_vkDestroyShaderModule vilc_vkDestroyShaderModule = NULL;
static PFN_vkDeviceWaitIdle vilc_vkDeviceWaitIdle = NULL;
static PFN_vkEndCommandBuffer vilc_vkEndCommandBuffer = NULL;
static PFN_vkEnumerateDeviceExtensionProperties vilc_vkEnumerateDeviceExtensionProperties = NULL;
static PFN_vkEnumerateDeviceLayerProperties vilc_vkEnumerateDeviceLayerProperties = NULL;
static PFN_vkEnumerateInstanceExtensionProperties vilc_vkEnumerateInstanceExtensionProperties = NULL;
static PFN_vkEnumerateInstanceLayerProperties vilc_vkEnumerateInstanceLayerProperties = NULL;
static PFN_vkEnumeratePhysicalDevices vilc_vkEnumeratePhysicalDevices = NULL;
static PFN_vkFlushMappedMemoryRanges vilc_vkFlushMappedMemoryRanges = NULL;
static PFN_vkFreeCommandBuffers vilc_vkFreeCommandBuffers = NULL;
static PFN_vkFreeDescriptorSets vilc_vkFreeDescriptorSets = NULL;
static PFN_vkFreeMemory vilc_vkFreeMemory = NULL;
static PFN_vkGetBufferMemoryRequirements vilc_vkGetBufferMemoryRequirements = NULL;
static PFN_vkGetDeviceMemoryCommitment vilc_vkGetDeviceMemoryCommitment = NULL;
static PFN_vkGetDeviceProcAddr vilc_vkGetDeviceProcAddr = NULL;
static PFN_vkGetDeviceQueue vilc_vkGetDeviceQueue = NULL;
static PFN_vkGetEventStatus vilc_vkGetEventStatus = NULL;
static PFN_vkGetFenceStatus vilc_vkGetFenceStatus = NULL;
static PFN_vkGetImageMemoryRequirements vilc_vkGetImageMemoryRequirements = NULL;
static PFN_vkGetImageSparseMemoryRequirements vilc_vkGetImageSparseMemoryRequirements = NULL;
static PFN_vkGetImageSubresourceLayout vilc_vkGetImageSubresourceLayout = NULL;
static PFN_vkGetInstanceProcAddr vilc_vkGetInstanceProcAddr = NULL;
static PFN_vkGetPhysicalDeviceFeatures vilc_vkGetPhysicalDeviceFeatures = NULL;
static PFN_vkGetPhysicalDeviceFormatProperties vilc_vkGetPhysicalDeviceFormatProperties = NULL;
static PFN_vkGetPhysicalDeviceImageFormatProperties vilc_vkGetPhysicalDeviceImageFormatProperties = NULL;
static PFN_vkGetPhysicalDeviceMemoryProperties vilc_vkGetPhysicalDeviceMemoryProperties = NULL;
static PFN_vkGetPhysicalDeviceProperties vilc_vkGetPhysicalDeviceProperties = NULL;
static PFN_vkGetPhysicalDeviceQueueFamilyProperties vilc_vkGetPhysicalDeviceQueueFamilyProperties = NULL;
static PFN_vkGetPhysicalDeviceSparseImageFormatProperties vilc_vkGetPhysicalDeviceSparseImageFormatProperties = NULL;
static PFN_vkGetPipelineCacheData vilc_vkGetPipelineCacheData = NULL;
static PFN_vkGetQueryPoolResults vilc_vkGetQueryPoolResults = NULL;
static PFN_vkGetRenderAreaGranularity vilc_vkGetRenderAreaGranularity = NULL;
static PFN_vkInvalidateMappedMemoryRanges vilc_vkInvalidateMappedMemoryRanges = NULL;
static PFN_vkMapMemory vilc_vkMapMemory = NULL;
static PFN_vkMergePipelineCaches vilc_vkMergePipelineCaches = NULL;
static PFN_vkQueueBindSparse vilc_vkQueueBindSparse = NULL;
static PFN_vkQueueSubmit vilc_vkQueueSubmit = NULL;
static PFN_vkQueueWaitIdle vilc_vkQueueWaitIdle = NULL;
static PFN_vkResetCommandBuffer vilc_vkResetCommandBuffer = NULL;
static PFN_vkResetCommandPool vilc_vkResetCommandPool = NULL;
static PFN_vkResetDescriptorPool vilc_vkResetDescriptorPool = NULL;
static PFN_vkResetEvent vilc_vkResetEvent = NULL;
static PFN_vkResetFences vilc_vkResetFences = NULL;
static PFN_vkSetEvent vilc_vkSetEvent = NULL;
static PFN_vkUnmapMemory vilc_vkUnmapMemory = NULL;
static PFN_vkUpdateDescriptorSets vilc_vkUpdateDescriptorSets = NULL;
static PFN_vkWaitForFences vilc_vkWaitForFences = NULL;
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
static PFN_vkBindBufferMemory2 vilc_vkBindBufferMemory2 = NULL;
static PFN_vkBindImageMemory2 vilc_vkBindImageMemory2 = NULL;
static PFN_vkCmdDispatchBase vilc_vkCmdDispatchBase = NULL;
static PFN_vkCmdSetDeviceMask vilc_vkCmdSetDeviceMask = NULL;
static PFN_vkCreateDescriptorUpdateTemplate vilc_vkCreateDescriptorUpdateTemplate = NULL;
static PFN_vkCreateSamplerYcbcrConversion vilc_vkCreateSamplerYcbcrConversion = NULL;
static PFN_vkDestroyDescriptorUpdateTemplate vilc_vkDestroyDescriptorUpdateTemplate = NULL;
static PFN_vkDestroySamplerYcbcrConversion vilc_vkDestroySamplerYcbcrConversion = NULL;
static PFN_vkEnumerateInstanceVersion vilc_vkEnumerateInstanceVersion = NULL;
static PFN_vkEnumeratePhysicalDeviceGroups vilc_vkEnumeratePhysicalDeviceGroups = NULL;
static PFN_vkGetBufferMemoryRequirements2 vilc_vkGetBufferMemoryRequirements2 = NULL;
static PFN_vkGetDescriptorSetLayoutSupport vilc_vkGetDescriptorSetLayoutSupport = NULL;
static PFN_vkGetDeviceGroupPeerMemoryFeatures vilc_vkGetDeviceGroupPeerMemoryFeatures = NULL;
static PFN_vkGetDeviceQueue2 vilc_vkGetDeviceQueue2 = NULL;
static PFN_vkGetImageMemoryRequirements2 vilc_vkGetImageMemoryRequirements2 = NULL;
static PFN_vkGetImageSparseMemoryRequirements2 vilc_vkGetImageSparseMemoryRequirements2 = NULL;
static PFN_vkGetPhysicalDeviceExternalBufferProperties vilc_vkGetPhysicalDeviceExternalBufferProperties = NULL;
static PFN_vkGetPhysicalDeviceExternalFenceProperties vilc_vkGetPhysicalDeviceExternalFenceProperties = NULL;
static PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vilc_vkGetPhysicalDeviceExternalSemaphoreProperties = NULL;
static PFN_vkGetPhysicalDeviceFeatures2 vilc_vkGetPhysicalDeviceFeatures2 = NULL;
static PFN_vkGetPhysicalDeviceFormatProperties2 vilc_vkGetPhysicalDeviceFormatProperties2 = NULL;
static PFN_vkGetPhysicalDeviceImageFormatProperties2 vilc_vkGetPhysicalDeviceImageFormatProperties2 = NULL;
static PFN_vkGetPhysicalDeviceMemoryProperties2 vilc_vkGetPhysicalDeviceMemoryProperties2 = NULL;
static PFN_vkGetPhysicalDeviceProperties2 vilc_vkGetPhysicalDeviceProperties2 = NULL;
static PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vilc_vkGetPhysicalDeviceQueueFamilyProperties2 = NULL;
static PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vilc_vkGetPhysicalDeviceSparseImageFormatProperties2 = NULL;
static PFN_vkTrimCommandPool vilc_vkTrimCommandPool = NULL;
static PFN_vkUpdateDescriptorSetWithTemplate vilc_vkUpdateDescriptorSetWithTemplate = NULL;
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_2)
static PFN_vkCmdBeginRenderPass2 vilc_vkCmdBeginRenderPass2 = NULL;
static PFN_vkCmdDrawIndexedIndirectCount vilc_vkCmdDrawIndexedIndirectCount = NULL;
static PFN_vkCmdDrawIndirectCount vilc_vkCmdDrawIndirectCount = NULL;
static PFN_vkCmdEndRenderPass2 vilc_vkCmdEndRenderPass2 = NULL;
static PFN_vkCmdNextSubpass2 vilc_vkCmdNextSubpass2 = NULL;
static PFN_vkCreateRenderPass2 vilc_vkCreateRenderPass2 = NULL;
static PFN_vkGetBufferDeviceAddress vilc_vkGetBufferDeviceAddress = NULL;
static PFN_vkGetBufferOpaqueCaptureAddress vilc_vkGetBufferOpaqueCaptureAddress = NULL;
static PFN_vkGetDeviceMemoryOpaqueCaptureAddress vilc_vkGetDeviceMemoryOpaqueCaptureAddress = NULL;
static PFN_vkGetSemaphoreCounterValue vilc_vkGetSemaphoreCounterValue = NULL;
static PFN_vkResetQueryPool vilc_vkResetQueryPool = NULL;
static PFN_vkSignalSemaphore vilc_vkSignalSemaphore = NULL;
static PFN_vkWaitSemaphores vilc_vkWaitSemaphores = NULL;
#endif /* defined(VK_VERSION_1_2) */
#if defined(VK_VERSION_1_3)
static PFN_vkCmdBeginRendering vilc_vkCmdBeginRendering = NULL;
static PFN_vkCmdBindVertexBuffers2 vilc_vkCmdBindVertexBuffers2 = NULL;
static PFN_vkCmdBlitImage2 vilc_vkCmdBlitImage2 = NULL;
static PFN_vkCmdCopyBuffer2 vilc_vkCmdCopyBuffer2 = NULL;
static PFN_vkCmdCopyBufferToImage2 vilc_vkCmdCopyBufferToImage2 = NULL;
static PFN_vkCmdCopyImage2 vilc_vkCmdCopyImage2 = NULL;
static PFN_vkCmdCopyImageToBuffer2 vilc_vkCmdCopyImageToBuffer2 = NULL;
static PFN_vkCmdEndRendering vilc_vkCmdEndRendering = NULL;
static PFN_vkCmdPipelineBarrier2 vilc_vkCmdPipelineBarrier2 = NULL;
static PFN_vkCmdResetEvent2 vilc_vkCmdResetEvent2 = NULL;
static PFN_vkCmdResolveImage2 vilc_vkCmdResolveImage2 = NULL;
static PFN_vkCmdSetCullMode vilc_vkCmdSetCullMode = NULL;
static PFN_vkCmdSetDepthBiasEnable vilc_vkCmdSetDepthBiasEnable = NULL;
static PFN_vkCmdSetDepthBoundsTestEnable vilc_vkCmdSetDepthBoundsTestEnable = NULL;
static PFN_vkCmdSetDepthCompareOp vilc_vkCmdSetDepthCompareOp = NULL;
static PFN_vkCmdSetDepthTestEnable vilc_vkCmdSetDepthTestEnable = NULL;
static PFN_vkCmdSetDepthWriteEnable vilc_vkCmdSetDepthWriteEnable = NULL;
static PFN_vkCmdSetEvent2 vilc_vkCmdSetEvent2 = NULL;
static PFN_vkCmdSetFrontFace vilc_vkCmdSetFrontFace = NULL;
static PFN_vkCmdSetPrimitiveRestartEnable vilc_vkCmdSetPrimitiveRestartEnable = NULL;
static PFN_vkCmdSetPrimitiveTopology vilc_vkCmdSetPrimitiveTopology = NULL;
static PFN_vkCmdSetRasterizerDiscardEnable vilc_vkCmdSetRasterizerDiscardEnable = NULL;
static PFN_vkCmdSetScissorWithCount vilc_vkCmdSetScissorWithCount = NULL;
static PFN_vkCmdSetStencilOp vilc_vkCmdSetStencilOp = NULL;
static PFN_vkCmdSetStencilTestEnable vilc_vkCmdSetStencilTestEnable = NULL;
static PFN_vkCmdSetViewportWithCount vilc_vkCmdSetViewportWithCount = NULL;
static PFN_vkCmdWaitEvents2 vilc_vkCmdWaitEvents2 = NULL;
static PFN_vkCmdWriteTimestamp2 vilc_vkCmdWriteTimestamp2 = NULL;
static PFN_vkCreatePrivateDataSlot vilc_vkCreatePrivateDataSlot = NULL;
static PFN_vkDestroyPrivateDataSlot vilc_vkDestroyPrivateDataSlot = NULL;
static PFN_vkGetDeviceBufferMemoryRequirements vilc_vkGetDeviceBufferMemoryRequirements = NULL;
static PFN_vkGetDeviceImageMemoryRequirements vilc_vkGetDeviceImageMemoryRequirements = NULL;
static PFN_vkGetDeviceImageSparseMemoryRequirements vilc_vkGetDeviceImageSparseMemoryRequirements = NULL;
static PFN_vkGetPhysicalDeviceToolProperties vilc_vkGetPhysicalDeviceToolProperties = NULL;
static PFN_vkGetPrivateData vilc_vkGetPrivateData = NULL;
static PFN_vkQueueSubmit2 vilc_vkQueueSubmit2 = NULL;
static PFN_vkSetPrivateData vilc_vkSetPrivateData = NULL;
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_VERSION_1_4)
static PFN_vkCmdBindDescriptorSets2 vilc_vkCmdBindDescriptorSets2 = NULL;
static PFN_vkCmdBindIndexBuffer2 vilc_vkCmdBindIndexBuffer2 = NULL;
static PFN_vkCmdPushConstants2 vilc_vkCmdPushConstants2 = NULL;
static PFN_vkCmdPushDescriptorSet vilc_vkCmdPushDescriptorSet = NULL;
static PFN_vkCmdPushDescriptorSet2 vilc_vkCmdPushDescriptorSet2 = NULL;
static PFN_vkCmdPushDescriptorSetWithTemplate vilc_vkCmdPushDescriptorSetWithTemplate = NULL;
static PFN_vkCmdPushDescriptorSetWithTemplate2 vilc_vkCmdPushDescriptorSetWithTemplate2 = NULL;
static PFN_vkCmdSetLineStipple vilc_vkCmdSetLineStipple = NULL;
static PFN_vkCmdSetRenderingAttachmentLocations vilc_vkCmdSetRenderingAttachmentLocations = NULL;
static PFN_vkCmdSetRenderingInputAttachmentIndices vilc_vkCmdSetRenderingInputAttachmentIndices = NULL;
static PFN_vkCopyImageToImage vilc_vkCopyImageToImage = NULL;
static PFN_vkCopyImageToMemory vilc_vkCopyImageToMemory = NULL;
static PFN_vkCopyMemoryToImage vilc_vkCopyMemoryToImage = NULL;
static PFN_vkGetDeviceImageSubresourceLayout vilc_vkGetDeviceImageSubresourceLayout = NULL;
static PFN_vkGetImageSubresourceLayout2 vilc_vkGetImageSubresourceLayout2 = NULL;
static PFN_vkGetRenderingAreaGranularity vilc_vkGetRenderingAreaGranularity = NULL;
static PFN_vkMapMemory2 vilc_vkMapMemory2 = NULL;
static PFN_vkTransitionImageLayout vilc_vkTransitionImageLayout = NULL;
static PFN_vkUnmapMemory2 vilc_vkUnmapMemory2 = NULL;
#endif /* defined(VK_VERSION_1_4) */
#if defined(VK_AMDX_shader_enqueue)
static PFN_vkCmdDispatchGraphAMDX vilc_vkCmdDispatchGraphAMDX = NULL;
static PFN_vkCmdDispatchGraphIndirectAMDX vilc_vkCmdDispatchGraphIndirectAMDX = NULL;
static PFN_vkCmdDispatchGraphIndirectCountAMDX vilc_vkCmdDispatchGraphIndirectCountAMDX = NULL;
static PFN_vkCmdInitializeGraphScratchMemoryAMDX vilc_vkCmdInitializeGraphScratchMemoryAMDX = NULL;
static PFN_vkCreateExecutionGraphPipelinesAMDX vilc_vkCreateExecutionGraphPipelinesAMDX = NULL;
static PFN_vkGetExecutionGraphPipelineNodeIndexAMDX vilc_vkGetExecutionGraphPipelineNodeIndexAMDX = NULL;
static PFN_vkGetExecutionGraphPipelineScratchSizeAMDX vilc_vkGetExecutionGraphPipelineScratchSizeAMDX = NULL;
#endif /* defined(VK_AMDX_shader_enqueue) */
#if defined(VK_AMD_anti_lag)
static PFN_vkAntiLagUpdateAMD vilc_vkAntiLagUpdateAMD = NULL;
#endif /* defined(VK_AMD_anti_lag) */
#if defined(VK_AMD_buffer_marker)
static PFN_vkCmdWriteBufferMarkerAMD vilc_vkCmdWriteBufferMarkerAMD = NULL;
#endif /* defined(VK_AMD_buffer_marker) */
#if defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
static PFN_vkCmdWriteBufferMarker2AMD vilc_vkCmdWriteBufferMarker2AMD = NULL;
#endif /* defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_AMD_display_native_hdr)
static PFN_vkSetLocalDimmingAMD vilc_vkSetLocalDimmingAMD = NULL;
#endif /* defined(VK_AMD_display_native_hdr) */
#if defined(VK_AMD_draw_indirect_count)
static PFN_vkCmdDrawIndexedIndirectCountAMD vilc_vkCmdDrawIndexedIndirectCountAMD = NULL;
static PFN_vkCmdDrawIndirectCountAMD vilc_vkCmdDrawIndirectCountAMD = NULL;
#endif /* defined(VK_AMD_draw_indirect_count) */
#if defined(VK_AMD_shader_info)
static PFN_vkGetShaderInfoAMD vilc_vkGetShaderInfoAMD = NULL;
#endif /* defined(VK_AMD_shader_info) */
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
static PFN_vkGetAndroidHardwareBufferPropertiesANDROID vilc_vkGetAndroidHardwareBufferPropertiesANDROID = NULL;
static PFN_vkGetMemoryAndroidHardwareBufferANDROID vilc_vkGetMemoryAndroidHardwareBufferANDROID = NULL;
#endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
#if defined(VK_ARM_data_graph)
static PFN_vkBindDataGraphPipelineSessionMemoryARM vilc_vkBindDataGraphPipelineSessionMemoryARM = NULL;
static PFN_vkCmdDispatchDataGraphARM vilc_vkCmdDispatchDataGraphARM = NULL;
static PFN_vkCreateDataGraphPipelineSessionARM vilc_vkCreateDataGraphPipelineSessionARM = NULL;
static PFN_vkCreateDataGraphPipelinesARM vilc_vkCreateDataGraphPipelinesARM = NULL;
static PFN_vkDestroyDataGraphPipelineSessionARM vilc_vkDestroyDataGraphPipelineSessionARM = NULL;
static PFN_vkGetDataGraphPipelineAvailablePropertiesARM vilc_vkGetDataGraphPipelineAvailablePropertiesARM = NULL;
static PFN_vkGetDataGraphPipelinePropertiesARM vilc_vkGetDataGraphPipelinePropertiesARM = NULL;
static PFN_vkGetDataGraphPipelineSessionBindPointRequirementsARM vilc_vkGetDataGraphPipelineSessionBindPointRequirementsARM = NULL;
static PFN_vkGetDataGraphPipelineSessionMemoryRequirementsARM vilc_vkGetDataGraphPipelineSessionMemoryRequirementsARM = NULL;
static PFN_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM vilc_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM = NULL;
static PFN_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM vilc_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM = NULL;
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_performance_counters_by_region)
static PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM vilc_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM = NULL;
#endif /* defined(VK_ARM_performance_counters_by_region) */
#if defined(VK_ARM_tensors)
static PFN_vkBindTensorMemoryARM vilc_vkBindTensorMemoryARM = NULL;
static PFN_vkCmdCopyTensorARM vilc_vkCmdCopyTensorARM = NULL;
static PFN_vkCreateTensorARM vilc_vkCreateTensorARM = NULL;
static PFN_vkCreateTensorViewARM vilc_vkCreateTensorViewARM = NULL;
static PFN_vkDestroyTensorARM vilc_vkDestroyTensorARM = NULL;
static PFN_vkDestroyTensorViewARM vilc_vkDestroyTensorViewARM = NULL;
static PFN_vkGetDeviceTensorMemoryRequirementsARM vilc_vkGetDeviceTensorMemoryRequirementsARM = NULL;
static PFN_vkGetPhysicalDeviceExternalTensorPropertiesARM vilc_vkGetPhysicalDeviceExternalTensorPropertiesARM = NULL;
static PFN_vkGetTensorMemoryRequirementsARM vilc_vkGetTensorMemoryRequirementsARM = NULL;
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer)
static PFN_vkGetTensorOpaqueCaptureDescriptorDataARM vilc_vkGetTensorOpaqueCaptureDescriptorDataARM = NULL;
static PFN_vkGetTensorViewOpaqueCaptureDescriptorDataARM vilc_vkGetTensorViewOpaqueCaptureDescriptorDataARM = NULL;
#endif /* defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_acquire_drm_display)
static PFN_vkAcquireDrmDisplayEXT vilc_vkAcquireDrmDisplayEXT = NULL;
static PFN_vkGetDrmDisplayEXT vilc_vkGetDrmDisplayEXT = NULL;
#endif /* defined(VK_EXT_acquire_drm_display) */
#if defined(VK_EXT_acquire_xlib_display)
static PFN_vkAcquireXlibDisplayEXT vilc_vkAcquireXlibDisplayEXT = NULL;
static PFN_vkGetRandROutputDisplayEXT vilc_vkGetRandROutputDisplayEXT = NULL;
#endif /* defined(VK_EXT_acquire_xlib_display) */
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
static PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT vilc_vkCmdSetAttachmentFeedbackLoopEnableEXT = NULL;
#endif /* defined(VK_EXT_attachment_feedback_loop_dynamic_state) */
#if defined(VK_EXT_buffer_device_address)
static PFN_vkGetBufferDeviceAddressEXT vilc_vkGetBufferDeviceAddressEXT = NULL;
#endif /* defined(VK_EXT_buffer_device_address) */
#if defined(VK_EXT_calibrated_timestamps)
static PFN_vkGetCalibratedTimestampsEXT vilc_vkGetCalibratedTimestampsEXT = NULL;
static PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vilc_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = NULL;
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_color_write_enable)
static PFN_vkCmdSetColorWriteEnableEXT vilc_vkCmdSetColorWriteEnableEXT = NULL;
#endif /* defined(VK_EXT_color_write_enable) */
#if defined(VK_EXT_conditional_rendering)
static PFN_vkCmdBeginConditionalRenderingEXT vilc_vkCmdBeginConditionalRenderingEXT = NULL;
static PFN_vkCmdEndConditionalRenderingEXT vilc_vkCmdEndConditionalRenderingEXT = NULL;
#endif /* defined(VK_EXT_conditional_rendering) */
#if defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3))
static PFN_vkCmdBeginCustomResolveEXT vilc_vkCmdBeginCustomResolveEXT = NULL;
#endif /* defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3)) */
#if defined(VK_EXT_debug_marker)
static PFN_vkCmdDebugMarkerBeginEXT vilc_vkCmdDebugMarkerBeginEXT = NULL;
static PFN_vkCmdDebugMarkerEndEXT vilc_vkCmdDebugMarkerEndEXT = NULL;
static PFN_vkCmdDebugMarkerInsertEXT vilc_vkCmdDebugMarkerInsertEXT = NULL;
static PFN_vkDebugMarkerSetObjectNameEXT vilc_vkDebugMarkerSetObjectNameEXT = NULL;
static PFN_vkDebugMarkerSetObjectTagEXT vilc_vkDebugMarkerSetObjectTagEXT = NULL;
#endif /* defined(VK_EXT_debug_marker) */
#if defined(VK_EXT_debug_report)
static PFN_vkCreateDebugReportCallbackEXT vilc_vkCreateDebugReportCallbackEXT = NULL;
static PFN_vkDebugReportMessageEXT vilc_vkDebugReportMessageEXT = NULL;
static PFN_vkDestroyDebugReportCallbackEXT vilc_vkDestroyDebugReportCallbackEXT = NULL;
#endif /* defined(VK_EXT_debug_report) */
#if defined(VK_EXT_debug_utils)
static PFN_vkCmdBeginDebugUtilsLabelEXT vilc_vkCmdBeginDebugUtilsLabelEXT = NULL;
static PFN_vkCmdEndDebugUtilsLabelEXT vilc_vkCmdEndDebugUtilsLabelEXT = NULL;
static PFN_vkCmdInsertDebugUtilsLabelEXT vilc_vkCmdInsertDebugUtilsLabelEXT = NULL;
static PFN_vkCreateDebugUtilsMessengerEXT vilc_vkCreateDebugUtilsMessengerEXT = NULL;
static PFN_vkDestroyDebugUtilsMessengerEXT vilc_vkDestroyDebugUtilsMessengerEXT = NULL;
static PFN_vkQueueBeginDebugUtilsLabelEXT vilc_vkQueueBeginDebugUtilsLabelEXT = NULL;
static PFN_vkQueueEndDebugUtilsLabelEXT vilc_vkQueueEndDebugUtilsLabelEXT = NULL;
static PFN_vkQueueInsertDebugUtilsLabelEXT vilc_vkQueueInsertDebugUtilsLabelEXT = NULL;
static PFN_vkSetDebugUtilsObjectNameEXT vilc_vkSetDebugUtilsObjectNameEXT = NULL;
static PFN_vkSetDebugUtilsObjectTagEXT vilc_vkSetDebugUtilsObjectTagEXT = NULL;
static PFN_vkSubmitDebugUtilsMessageEXT vilc_vkSubmitDebugUtilsMessageEXT = NULL;
#endif /* defined(VK_EXT_debug_utils) */
#if defined(VK_EXT_depth_bias_control)
static PFN_vkCmdSetDepthBias2EXT vilc_vkCmdSetDepthBias2EXT = NULL;
#endif /* defined(VK_EXT_depth_bias_control) */
#if defined(VK_EXT_descriptor_buffer)
static PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT vilc_vkCmdBindDescriptorBufferEmbeddedSamplersEXT = NULL;
static PFN_vkCmdBindDescriptorBuffersEXT vilc_vkCmdBindDescriptorBuffersEXT = NULL;
static PFN_vkCmdSetDescriptorBufferOffsetsEXT vilc_vkCmdSetDescriptorBufferOffsetsEXT = NULL;
static PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT vilc_vkGetBufferOpaqueCaptureDescriptorDataEXT = NULL;
static PFN_vkGetDescriptorEXT vilc_vkGetDescriptorEXT = NULL;
static PFN_vkGetDescriptorSetLayoutBindingOffsetEXT vilc_vkGetDescriptorSetLayoutBindingOffsetEXT = NULL;
static PFN_vkGetDescriptorSetLayoutSizeEXT vilc_vkGetDescriptorSetLayoutSizeEXT = NULL;
static PFN_vkGetImageOpaqueCaptureDescriptorDataEXT vilc_vkGetImageOpaqueCaptureDescriptorDataEXT = NULL;
static PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT vilc_vkGetImageViewOpaqueCaptureDescriptorDataEXT = NULL;
static PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT vilc_vkGetSamplerOpaqueCaptureDescriptorDataEXT = NULL;
#endif /* defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing))
static PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT vilc_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = NULL;
#endif /* defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing)) */
#if defined(VK_EXT_device_fault)
static PFN_vkGetDeviceFaultInfoEXT vilc_vkGetDeviceFaultInfoEXT = NULL;
#endif /* defined(VK_EXT_device_fault) */
#if defined(VK_EXT_device_generated_commands)
static PFN_vkCmdExecuteGeneratedCommandsEXT vilc_vkCmdExecuteGeneratedCommandsEXT = NULL;
static PFN_vkCmdPreprocessGeneratedCommandsEXT vilc_vkCmdPreprocessGeneratedCommandsEXT = NULL;
static PFN_vkCreateIndirectCommandsLayoutEXT vilc_vkCreateIndirectCommandsLayoutEXT = NULL;
static PFN_vkCreateIndirectExecutionSetEXT vilc_vkCreateIndirectExecutionSetEXT = NULL;
static PFN_vkDestroyIndirectCommandsLayoutEXT vilc_vkDestroyIndirectCommandsLayoutEXT = NULL;
static PFN_vkDestroyIndirectExecutionSetEXT vilc_vkDestroyIndirectExecutionSetEXT = NULL;
static PFN_vkGetGeneratedCommandsMemoryRequirementsEXT vilc_vkGetGeneratedCommandsMemoryRequirementsEXT = NULL;
static PFN_vkUpdateIndirectExecutionSetPipelineEXT vilc_vkUpdateIndirectExecutionSetPipelineEXT = NULL;
static PFN_vkUpdateIndirectExecutionSetShaderEXT vilc_vkUpdateIndirectExecutionSetShaderEXT = NULL;
#endif /* defined(VK_EXT_device_generated_commands) */
#if defined(VK_EXT_direct_mode_display)
static PFN_vkReleaseDisplayEXT vilc_vkReleaseDisplayEXT = NULL;
#endif /* defined(VK_EXT_direct_mode_display) */
#if defined(VK_EXT_directfb_surface)
static PFN_vkCreateDirectFBSurfaceEXT vilc_vkCreateDirectFBSurfaceEXT = NULL;
static PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT vilc_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = NULL;
#endif /* defined(VK_EXT_directfb_surface) */
#if defined(VK_EXT_discard_rectangles)
static PFN_vkCmdSetDiscardRectangleEXT vilc_vkCmdSetDiscardRectangleEXT = NULL;
#endif /* defined(VK_EXT_discard_rectangles) */
#if defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2
static PFN_vkCmdSetDiscardRectangleEnableEXT vilc_vkCmdSetDiscardRectangleEnableEXT = NULL;
static PFN_vkCmdSetDiscardRectangleModeEXT vilc_vkCmdSetDiscardRectangleModeEXT = NULL;
#endif /* defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2 */
#if defined(VK_EXT_display_control)
static PFN_vkDisplayPowerControlEXT vilc_vkDisplayPowerControlEXT = NULL;
static PFN_vkGetSwapchainCounterEXT vilc_vkGetSwapchainCounterEXT = NULL;
static PFN_vkRegisterDeviceEventEXT vilc_vkRegisterDeviceEventEXT = NULL;
static PFN_vkRegisterDisplayEventEXT vilc_vkRegisterDisplayEventEXT = NULL;
#endif /* defined(VK_EXT_display_control) */
#if defined(VK_EXT_display_surface_counter)
static PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vilc_vkGetPhysicalDeviceSurfaceCapabilities2EXT = NULL;
#endif /* defined(VK_EXT_display_surface_counter) */
#if defined(VK_EXT_external_memory_host)
static PFN_vkGetMemoryHostPointerPropertiesEXT vilc_vkGetMemoryHostPointerPropertiesEXT = NULL;
#endif /* defined(VK_EXT_external_memory_host) */
#if defined(VK_EXT_external_memory_metal)
static PFN_vkGetMemoryMetalHandleEXT vilc_vkGetMemoryMetalHandleEXT = NULL;
static PFN_vkGetMemoryMetalHandlePropertiesEXT vilc_vkGetMemoryMetalHandlePropertiesEXT = NULL;
#endif /* defined(VK_EXT_external_memory_metal) */
#if defined(VK_EXT_fragment_density_map_offset)
static PFN_vkCmdEndRendering2EXT vilc_vkCmdEndRendering2EXT = NULL;
#endif /* defined(VK_EXT_fragment_density_map_offset) */
#if defined(VK_EXT_full_screen_exclusive)
static PFN_vkAcquireFullScreenExclusiveModeEXT vilc_vkAcquireFullScreenExclusiveModeEXT = NULL;
static PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vilc_vkGetPhysicalDeviceSurfacePresentModes2EXT = NULL;
static PFN_vkReleaseFullScreenExclusiveModeEXT vilc_vkReleaseFullScreenExclusiveModeEXT = NULL;
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1))
static PFN_vkGetDeviceGroupSurfacePresentModes2EXT vilc_vkGetDeviceGroupSurfacePresentModes2EXT = NULL;
#endif /* defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1)) */
#if defined(VK_EXT_hdr_metadata)
static PFN_vkSetHdrMetadataEXT vilc_vkSetHdrMetadataEXT = NULL;
#endif /* defined(VK_EXT_hdr_metadata) */
#if defined(VK_EXT_headless_surface)
static PFN_vkCreateHeadlessSurfaceEXT vilc_vkCreateHeadlessSurfaceEXT = NULL;
#endif /* defined(VK_EXT_headless_surface) */
#if defined(VK_EXT_host_image_copy)
static PFN_vkCopyImageToImageEXT vilc_vkCopyImageToImageEXT = NULL;
static PFN_vkCopyImageToMemoryEXT vilc_vkCopyImageToMemoryEXT = NULL;
static PFN_vkCopyMemoryToImageEXT vilc_vkCopyMemoryToImageEXT = NULL;
static PFN_vkTransitionImageLayoutEXT vilc_vkTransitionImageLayoutEXT = NULL;
#endif /* defined(VK_EXT_host_image_copy) */
#if defined(VK_EXT_host_query_reset)
static PFN_vkResetQueryPoolEXT vilc_vkResetQueryPoolEXT = NULL;
#endif /* defined(VK_EXT_host_query_reset) */
#if defined(VK_EXT_image_drm_format_modifier)
static PFN_vkGetImageDrmFormatModifierPropertiesEXT vilc_vkGetImageDrmFormatModifierPropertiesEXT = NULL;
#endif /* defined(VK_EXT_image_drm_format_modifier) */
#if defined(VK_EXT_line_rasterization)
static PFN_vkCmdSetLineStippleEXT vilc_vkCmdSetLineStippleEXT = NULL;
#endif /* defined(VK_EXT_line_rasterization) */
#if defined(VK_EXT_memory_decompression)
static PFN_vkCmdDecompressMemoryEXT vilc_vkCmdDecompressMemoryEXT = NULL;
static PFN_vkCmdDecompressMemoryIndirectCountEXT vilc_vkCmdDecompressMemoryIndirectCountEXT = NULL;
#endif /* defined(VK_EXT_memory_decompression) */
#if defined(VK_EXT_mesh_shader)
static PFN_vkCmdDrawMeshTasksEXT vilc_vkCmdDrawMeshTasksEXT = NULL;
static PFN_vkCmdDrawMeshTasksIndirectEXT vilc_vkCmdDrawMeshTasksIndirectEXT = NULL;
#endif /* defined(VK_EXT_mesh_shader) */
#if defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
static PFN_vkCmdDrawMeshTasksIndirectCountEXT vilc_vkCmdDrawMeshTasksIndirectCountEXT = NULL;
#endif /* defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_EXT_metal_objects)
static PFN_vkExportMetalObjectsEXT vilc_vkExportMetalObjectsEXT = NULL;
#endif /* defined(VK_EXT_metal_objects) */
#if defined(VK_EXT_metal_surface)
static PFN_vkCreateMetalSurfaceEXT vilc_vkCreateMetalSurfaceEXT = NULL;
#endif /* defined(VK_EXT_metal_surface) */
#if defined(VK_EXT_multi_draw)
static PFN_vkCmdDrawMultiEXT vilc_vkCmdDrawMultiEXT = NULL;
static PFN_vkCmdDrawMultiIndexedEXT vilc_vkCmdDrawMultiIndexedEXT = NULL;
#endif /* defined(VK_EXT_multi_draw) */
#if defined(VK_EXT_opacity_micromap)
static PFN_vkBuildMicromapsEXT vilc_vkBuildMicromapsEXT = NULL;
static PFN_vkCmdBuildMicromapsEXT vilc_vkCmdBuildMicromapsEXT = NULL;
static PFN_vkCmdCopyMemoryToMicromapEXT vilc_vkCmdCopyMemoryToMicromapEXT = NULL;
static PFN_vkCmdCopyMicromapEXT vilc_vkCmdCopyMicromapEXT = NULL;
static PFN_vkCmdCopyMicromapToMemoryEXT vilc_vkCmdCopyMicromapToMemoryEXT = NULL;
static PFN_vkCmdWriteMicromapsPropertiesEXT vilc_vkCmdWriteMicromapsPropertiesEXT = NULL;
static PFN_vkCopyMemoryToMicromapEXT vilc_vkCopyMemoryToMicromapEXT = NULL;
static PFN_vkCopyMicromapEXT vilc_vkCopyMicromapEXT = NULL;
static PFN_vkCopyMicromapToMemoryEXT vilc_vkCopyMicromapToMemoryEXT = NULL;
static PFN_vkCreateMicromapEXT vilc_vkCreateMicromapEXT = NULL;
static PFN_vkDestroyMicromapEXT vilc_vkDestroyMicromapEXT = NULL;
static PFN_vkGetDeviceMicromapCompatibilityEXT vilc_vkGetDeviceMicromapCompatibilityEXT = NULL;
static PFN_vkGetMicromapBuildSizesEXT vilc_vkGetMicromapBuildSizesEXT = NULL;
static PFN_vkWriteMicromapsPropertiesEXT vilc_vkWriteMicromapsPropertiesEXT = NULL;
#endif /* defined(VK_EXT_opacity_micromap) */
#if defined(VK_EXT_pageable_device_local_memory)
static PFN_vkSetDeviceMemoryPriorityEXT vilc_vkSetDeviceMemoryPriorityEXT = NULL;
#endif /* defined(VK_EXT_pageable_device_local_memory) */
#if defined(VK_EXT_pipeline_properties)
static PFN_vkGetPipelinePropertiesEXT vilc_vkGetPipelinePropertiesEXT = NULL;
#endif /* defined(VK_EXT_pipeline_properties) */
#if defined(VK_EXT_present_timing)
static PFN_vkGetPastPresentationTimingEXT vilc_vkGetPastPresentationTimingEXT = NULL;
static PFN_vkGetSwapchainTimeDomainPropertiesEXT vilc_vkGetSwapchainTimeDomainPropertiesEXT = NULL;
static PFN_vkGetSwapchainTimingPropertiesEXT vilc_vkGetSwapchainTimingPropertiesEXT = NULL;
static PFN_vkSetSwapchainPresentTimingQueueSizeEXT vilc_vkSetSwapchainPresentTimingQueueSizeEXT = NULL;
#endif /* defined(VK_EXT_present_timing) */
#if defined(VK_EXT_private_data)
static PFN_vkCreatePrivateDataSlotEXT vilc_vkCreatePrivateDataSlotEXT = NULL;
static PFN_vkDestroyPrivateDataSlotEXT vilc_vkDestroyPrivateDataSlotEXT = NULL;
static PFN_vkGetPrivateDataEXT vilc_vkGetPrivateDataEXT = NULL;
static PFN_vkSetPrivateDataEXT vilc_vkSetPrivateDataEXT = NULL;
#endif /* defined(VK_EXT_private_data) */
#if defined(VK_EXT_sample_locations)
static PFN_vkCmdSetSampleLocationsEXT vilc_vkCmdSetSampleLocationsEXT = NULL;
static PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vilc_vkGetPhysicalDeviceMultisamplePropertiesEXT = NULL;
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_shader_module_identifier)
static PFN_vkGetShaderModuleCreateInfoIdentifierEXT vilc_vkGetShaderModuleCreateInfoIdentifierEXT = NULL;
static PFN_vkGetShaderModuleIdentifierEXT vilc_vkGetShaderModuleIdentifierEXT = NULL;
#endif /* defined(VK_EXT_shader_module_identifier) */
#if defined(VK_EXT_shader_object)
static PFN_vkCmdBindShadersEXT vilc_vkCmdBindShadersEXT = NULL;
static PFN_vkCreateShadersEXT vilc_vkCreateShadersEXT = NULL;
static PFN_vkDestroyShaderEXT vilc_vkDestroyShaderEXT = NULL;
static PFN_vkGetShaderBinaryDataEXT vilc_vkGetShaderBinaryDataEXT = NULL;
#endif /* defined(VK_EXT_shader_object) */
#if defined(VK_EXT_swapchain_maintenance1)
static PFN_vkReleaseSwapchainImagesEXT vilc_vkReleaseSwapchainImagesEXT = NULL;
#endif /* defined(VK_EXT_swapchain_maintenance1) */
#if defined(VK_EXT_tooling_info)
static PFN_vkGetPhysicalDeviceToolPropertiesEXT vilc_vkGetPhysicalDeviceToolPropertiesEXT = NULL;
#endif /* defined(VK_EXT_tooling_info) */
#if defined(VK_EXT_transform_feedback)
static PFN_vkCmdBeginQueryIndexedEXT vilc_vkCmdBeginQueryIndexedEXT = NULL;
static PFN_vkCmdBeginTransformFeedbackEXT vilc_vkCmdBeginTransformFeedbackEXT = NULL;
static PFN_vkCmdBindTransformFeedbackBuffersEXT vilc_vkCmdBindTransformFeedbackBuffersEXT = NULL;
static PFN_vkCmdDrawIndirectByteCountEXT vilc_vkCmdDrawIndirectByteCountEXT = NULL;
static PFN_vkCmdEndQueryIndexedEXT vilc_vkCmdEndQueryIndexedEXT = NULL;
static PFN_vkCmdEndTransformFeedbackEXT vilc_vkCmdEndTransformFeedbackEXT = NULL;
#endif /* defined(VK_EXT_transform_feedback) */
#if defined(VK_EXT_validation_cache)
static PFN_vkCreateValidationCacheEXT vilc_vkCreateValidationCacheEXT = NULL;
static PFN_vkDestroyValidationCacheEXT vilc_vkDestroyValidationCacheEXT = NULL;
static PFN_vkGetValidationCacheDataEXT vilc_vkGetValidationCacheDataEXT = NULL;
static PFN_vkMergeValidationCachesEXT vilc_vkMergeValidationCachesEXT = NULL;
#endif /* defined(VK_EXT_validation_cache) */
#if defined(VK_FUCHSIA_buffer_collection)
static PFN_vkCreateBufferCollectionFUCHSIA vilc_vkCreateBufferCollectionFUCHSIA = NULL;
static PFN_vkDestroyBufferCollectionFUCHSIA vilc_vkDestroyBufferCollectionFUCHSIA = NULL;
static PFN_vkGetBufferCollectionPropertiesFUCHSIA vilc_vkGetBufferCollectionPropertiesFUCHSIA = NULL;
static PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA vilc_vkSetBufferCollectionBufferConstraintsFUCHSIA = NULL;
static PFN_vkSetBufferCollectionImageConstraintsFUCHSIA vilc_vkSetBufferCollectionImageConstraintsFUCHSIA = NULL;
#endif /* defined(VK_FUCHSIA_buffer_collection) */
#if defined(VK_FUCHSIA_external_memory)
static PFN_vkGetMemoryZirconHandleFUCHSIA vilc_vkGetMemoryZirconHandleFUCHSIA = NULL;
static PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA vilc_vkGetMemoryZirconHandlePropertiesFUCHSIA = NULL;
#endif /* defined(VK_FUCHSIA_external_memory) */
#if defined(VK_FUCHSIA_external_semaphore)
static PFN_vkGetSemaphoreZirconHandleFUCHSIA vilc_vkGetSemaphoreZirconHandleFUCHSIA = NULL;
static PFN_vkImportSemaphoreZirconHandleFUCHSIA vilc_vkImportSemaphoreZirconHandleFUCHSIA = NULL;
#endif /* defined(VK_FUCHSIA_external_semaphore) */
#if defined(VK_FUCHSIA_imagepipe_surface)
static PFN_vkCreateImagePipeSurfaceFUCHSIA vilc_vkCreateImagePipeSurfaceFUCHSIA = NULL;
#endif /* defined(VK_FUCHSIA_imagepipe_surface) */
#if defined(VK_GGP_stream_descriptor_surface)
static PFN_vkCreateStreamDescriptorSurfaceGGP vilc_vkCreateStreamDescriptorSurfaceGGP = NULL;
#endif /* defined(VK_GGP_stream_descriptor_surface) */
#if defined(VK_GOOGLE_display_timing)
static PFN_vkGetPastPresentationTimingGOOGLE vilc_vkGetPastPresentationTimingGOOGLE = NULL;
static PFN_vkGetRefreshCycleDurationGOOGLE vilc_vkGetRefreshCycleDurationGOOGLE = NULL;
#endif /* defined(VK_GOOGLE_display_timing) */
#if defined(VK_HUAWEI_cluster_culling_shader)
static PFN_vkCmdDrawClusterHUAWEI vilc_vkCmdDrawClusterHUAWEI = NULL;
static PFN_vkCmdDrawClusterIndirectHUAWEI vilc_vkCmdDrawClusterIndirectHUAWEI = NULL;
#endif /* defined(VK_HUAWEI_cluster_culling_shader) */
#if defined(VK_HUAWEI_invocation_mask)
static PFN_vkCmdBindInvocationMaskHUAWEI vilc_vkCmdBindInvocationMaskHUAWEI = NULL;
#endif /* defined(VK_HUAWEI_invocation_mask) */
#if defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2
static PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI vilc_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = NULL;
#endif /* defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2 */
#if defined(VK_HUAWEI_subpass_shading)
static PFN_vkCmdSubpassShadingHUAWEI vilc_vkCmdSubpassShadingHUAWEI = NULL;
#endif /* defined(VK_HUAWEI_subpass_shading) */
#if defined(VK_INTEL_performance_query)
static PFN_vkAcquirePerformanceConfigurationINTEL vilc_vkAcquirePerformanceConfigurationINTEL = NULL;
static PFN_vkCmdSetPerformanceMarkerINTEL vilc_vkCmdSetPerformanceMarkerINTEL = NULL;
static PFN_vkCmdSetPerformanceOverrideINTEL vilc_vkCmdSetPerformanceOverrideINTEL = NULL;
static PFN_vkCmdSetPerformanceStreamMarkerINTEL vilc_vkCmdSetPerformanceStreamMarkerINTEL = NULL;
static PFN_vkGetPerformanceParameterINTEL vilc_vkGetPerformanceParameterINTEL = NULL;
static PFN_vkInitializePerformanceApiINTEL vilc_vkInitializePerformanceApiINTEL = NULL;
static PFN_vkQueueSetPerformanceConfigurationINTEL vilc_vkQueueSetPerformanceConfigurationINTEL = NULL;
static PFN_vkReleasePerformanceConfigurationINTEL vilc_vkReleasePerformanceConfigurationINTEL = NULL;
static PFN_vkUninitializePerformanceApiINTEL vilc_vkUninitializePerformanceApiINTEL = NULL;
#endif /* defined(VK_INTEL_performance_query) */
#if defined(VK_KHR_acceleration_structure)
static PFN_vkBuildAccelerationStructuresKHR vilc_vkBuildAccelerationStructuresKHR = NULL;
static PFN_vkCmdBuildAccelerationStructuresIndirectKHR vilc_vkCmdBuildAccelerationStructuresIndirectKHR = NULL;
static PFN_vkCmdBuildAccelerationStructuresKHR vilc_vkCmdBuildAccelerationStructuresKHR = NULL;
static PFN_vkCmdCopyAccelerationStructureKHR vilc_vkCmdCopyAccelerationStructureKHR = NULL;
static PFN_vkCmdCopyAccelerationStructureToMemoryKHR vilc_vkCmdCopyAccelerationStructureToMemoryKHR = NULL;
static PFN_vkCmdCopyMemoryToAccelerationStructureKHR vilc_vkCmdCopyMemoryToAccelerationStructureKHR = NULL;
static PFN_vkCmdWriteAccelerationStructuresPropertiesKHR vilc_vkCmdWriteAccelerationStructuresPropertiesKHR = NULL;
static PFN_vkCopyAccelerationStructureKHR vilc_vkCopyAccelerationStructureKHR = NULL;
static PFN_vkCopyAccelerationStructureToMemoryKHR vilc_vkCopyAccelerationStructureToMemoryKHR = NULL;
static PFN_vkCopyMemoryToAccelerationStructureKHR vilc_vkCopyMemoryToAccelerationStructureKHR = NULL;
static PFN_vkCreateAccelerationStructureKHR vilc_vkCreateAccelerationStructureKHR = NULL;
static PFN_vkDestroyAccelerationStructureKHR vilc_vkDestroyAccelerationStructureKHR = NULL;
static PFN_vkGetAccelerationStructureBuildSizesKHR vilc_vkGetAccelerationStructureBuildSizesKHR = NULL;
static PFN_vkGetAccelerationStructureDeviceAddressKHR vilc_vkGetAccelerationStructureDeviceAddressKHR = NULL;
static PFN_vkGetDeviceAccelerationStructureCompatibilityKHR vilc_vkGetDeviceAccelerationStructureCompatibilityKHR = NULL;
static PFN_vkWriteAccelerationStructuresPropertiesKHR vilc_vkWriteAccelerationStructuresPropertiesKHR = NULL;
#endif /* defined(VK_KHR_acceleration_structure) */
#if defined(VK_KHR_android_surface)
static PFN_vkCreateAndroidSurfaceKHR vilc_vkCreateAndroidSurfaceKHR = NULL;
#endif /* defined(VK_KHR_android_surface) */
#if defined(VK_KHR_bind_memory2)
static PFN_vkBindBufferMemory2KHR vilc_vkBindBufferMemory2KHR = NULL;
static PFN_vkBindImageMemory2KHR vilc_vkBindImageMemory2KHR = NULL;
#endif /* defined(VK_KHR_bind_memory2) */
#if defined(VK_KHR_buffer_device_address)
static PFN_vkGetBufferDeviceAddressKHR vilc_vkGetBufferDeviceAddressKHR = NULL;
static PFN_vkGetBufferOpaqueCaptureAddressKHR vilc_vkGetBufferOpaqueCaptureAddressKHR = NULL;
static PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vilc_vkGetDeviceMemoryOpaqueCaptureAddressKHR = NULL;
#endif /* defined(VK_KHR_buffer_device_address) */
#if defined(VK_KHR_calibrated_timestamps)
static PFN_vkGetCalibratedTimestampsKHR vilc_vkGetCalibratedTimestampsKHR = NULL;
static PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR vilc_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = NULL;
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_cooperative_matrix)
static PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR vilc_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR = NULL;
#endif /* defined(VK_KHR_cooperative_matrix) */
#if defined(VK_KHR_copy_commands2)
static PFN_vkCmdBlitImage2KHR vilc_vkCmdBlitImage2KHR = NULL;
static PFN_vkCmdCopyBuffer2KHR vilc_vkCmdCopyBuffer2KHR = NULL;
static PFN_vkCmdCopyBufferToImage2KHR vilc_vkCmdCopyBufferToImage2KHR = NULL;
static PFN_vkCmdCopyImage2KHR vilc_vkCmdCopyImage2KHR = NULL;
static PFN_vkCmdCopyImageToBuffer2KHR vilc_vkCmdCopyImageToBuffer2KHR = NULL;
static PFN_vkCmdResolveImage2KHR vilc_vkCmdResolveImage2KHR = NULL;
#endif /* defined(VK_KHR_copy_commands2) */
#if defined(VK_KHR_copy_memory_indirect)
static PFN_vkCmdCopyMemoryIndirectKHR vilc_vkCmdCopyMemoryIndirectKHR = NULL;
static PFN_vkCmdCopyMemoryToImageIndirectKHR vilc_vkCmdCopyMemoryToImageIndirectKHR = NULL;
#endif /* defined(VK_KHR_copy_memory_indirect) */
#if defined(VK_KHR_create_renderpass2)
static PFN_vkCmdBeginRenderPass2KHR vilc_vkCmdBeginRenderPass2KHR = NULL;
static PFN_vkCmdEndRenderPass2KHR vilc_vkCmdEndRenderPass2KHR = NULL;
static PFN_vkCmdNextSubpass2KHR vilc_vkCmdNextSubpass2KHR = NULL;
static PFN_vkCreateRenderPass2KHR vilc_vkCreateRenderPass2KHR = NULL;
#endif /* defined(VK_KHR_create_renderpass2) */
#if defined(VK_KHR_deferred_host_operations)
static PFN_vkCreateDeferredOperationKHR vilc_vkCreateDeferredOperationKHR = NULL;
static PFN_vkDeferredOperationJoinKHR vilc_vkDeferredOperationJoinKHR = NULL;
static PFN_vkDestroyDeferredOperationKHR vilc_vkDestroyDeferredOperationKHR = NULL;
static PFN_vkGetDeferredOperationMaxConcurrencyKHR vilc_vkGetDeferredOperationMaxConcurrencyKHR = NULL;
static PFN_vkGetDeferredOperationResultKHR vilc_vkGetDeferredOperationResultKHR = NULL;
#endif /* defined(VK_KHR_deferred_host_operations) */
#if defined(VK_KHR_descriptor_update_template)
static PFN_vkCreateDescriptorUpdateTemplateKHR vilc_vkCreateDescriptorUpdateTemplateKHR = NULL;
static PFN_vkDestroyDescriptorUpdateTemplateKHR vilc_vkDestroyDescriptorUpdateTemplateKHR = NULL;
static PFN_vkUpdateDescriptorSetWithTemplateKHR vilc_vkUpdateDescriptorSetWithTemplateKHR = NULL;
#endif /* defined(VK_KHR_descriptor_update_template) */
#if defined(VK_KHR_device_group)
static PFN_vkCmdDispatchBaseKHR vilc_vkCmdDispatchBaseKHR = NULL;
static PFN_vkCmdSetDeviceMaskKHR vilc_vkCmdSetDeviceMaskKHR = NULL;
static PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vilc_vkGetDeviceGroupPeerMemoryFeaturesKHR = NULL;
#endif /* defined(VK_KHR_device_group) */
#if defined(VK_KHR_device_group_creation)
static PFN_vkEnumeratePhysicalDeviceGroupsKHR vilc_vkEnumeratePhysicalDeviceGroupsKHR = NULL;
#endif /* defined(VK_KHR_device_group_creation) */
#if defined(VK_KHR_display)
static PFN_vkCreateDisplayModeKHR vilc_vkCreateDisplayModeKHR = NULL;
static PFN_vkCreateDisplayPlaneSurfaceKHR vilc_vkCreateDisplayPlaneSurfaceKHR = NULL;
static PFN_vkGetDisplayModePropertiesKHR vilc_vkGetDisplayModePropertiesKHR = NULL;
static PFN_vkGetDisplayPlaneCapabilitiesKHR vilc_vkGetDisplayPlaneCapabilitiesKHR = NULL;
static PFN_vkGetDisplayPlaneSupportedDisplaysKHR vilc_vkGetDisplayPlaneSupportedDisplaysKHR = NULL;
static PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vilc_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = NULL;
static PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vilc_vkGetPhysicalDeviceDisplayPropertiesKHR = NULL;
#endif /* defined(VK_KHR_display) */
#if defined(VK_KHR_display_swapchain)
static PFN_vkCreateSharedSwapchainsKHR vilc_vkCreateSharedSwapchainsKHR = NULL;
#endif /* defined(VK_KHR_display_swapchain) */
#if defined(VK_KHR_draw_indirect_count)
static PFN_vkCmdDrawIndexedIndirectCountKHR vilc_vkCmdDrawIndexedIndirectCountKHR = NULL;
static PFN_vkCmdDrawIndirectCountKHR vilc_vkCmdDrawIndirectCountKHR = NULL;
#endif /* defined(VK_KHR_draw_indirect_count) */
#if defined(VK_KHR_dynamic_rendering)
static PFN_vkCmdBeginRenderingKHR vilc_vkCmdBeginRenderingKHR = NULL;
static PFN_vkCmdEndRenderingKHR vilc_vkCmdEndRenderingKHR = NULL;
#endif /* defined(VK_KHR_dynamic_rendering) */
#if defined(VK_KHR_dynamic_rendering_local_read)
static PFN_vkCmdSetRenderingAttachmentLocationsKHR vilc_vkCmdSetRenderingAttachmentLocationsKHR = NULL;
static PFN_vkCmdSetRenderingInputAttachmentIndicesKHR vilc_vkCmdSetRenderingInputAttachmentIndicesKHR = NULL;
#endif /* defined(VK_KHR_dynamic_rendering_local_read) */
#if defined(VK_KHR_external_fence_capabilities)
static PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vilc_vkGetPhysicalDeviceExternalFencePropertiesKHR = NULL;
#endif /* defined(VK_KHR_external_fence_capabilities) */
#if defined(VK_KHR_external_fence_fd)
static PFN_vkGetFenceFdKHR vilc_vkGetFenceFdKHR = NULL;
static PFN_vkImportFenceFdKHR vilc_vkImportFenceFdKHR = NULL;
#endif /* defined(VK_KHR_external_fence_fd) */
#if defined(VK_KHR_external_fence_win32)
static PFN_vkGetFenceWin32HandleKHR vilc_vkGetFenceWin32HandleKHR = NULL;
static PFN_vkImportFenceWin32HandleKHR vilc_vkImportFenceWin32HandleKHR = NULL;
#endif /* defined(VK_KHR_external_fence_win32) */
#if defined(VK_KHR_external_memory_capabilities)
static PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vilc_vkGetPhysicalDeviceExternalBufferPropertiesKHR = NULL;
#endif /* defined(VK_KHR_external_memory_capabilities) */
#if defined(VK_KHR_external_memory_fd)
static PFN_vkGetMemoryFdKHR vilc_vkGetMemoryFdKHR = NULL;
static PFN_vkGetMemoryFdPropertiesKHR vilc_vkGetMemoryFdPropertiesKHR = NULL;
#endif /* defined(VK_KHR_external_memory_fd) */
#if defined(VK_KHR_external_memory_win32)
static PFN_vkGetMemoryWin32HandleKHR vilc_vkGetMemoryWin32HandleKHR = NULL;
static PFN_vkGetMemoryWin32HandlePropertiesKHR vilc_vkGetMemoryWin32HandlePropertiesKHR = NULL;
#endif /* defined(VK_KHR_external_memory_win32) */
#if defined(VK_KHR_external_semaphore_capabilities)
static PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vilc_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = NULL;
#endif /* defined(VK_KHR_external_semaphore_capabilities) */
#if defined(VK_KHR_external_semaphore_fd)
static PFN_vkGetSemaphoreFdKHR vilc_vkGetSemaphoreFdKHR = NULL;
static PFN_vkImportSemaphoreFdKHR vilc_vkImportSemaphoreFdKHR = NULL;
#endif /* defined(VK_KHR_external_semaphore_fd) */
#if defined(VK_KHR_external_semaphore_win32)
static PFN_vkGetSemaphoreWin32HandleKHR vilc_vkGetSemaphoreWin32HandleKHR = NULL;
static PFN_vkImportSemaphoreWin32HandleKHR vilc_vkImportSemaphoreWin32HandleKHR = NULL;
#endif /* defined(VK_KHR_external_semaphore_win32) */
#if defined(VK_KHR_fragment_shading_rate)
static PFN_vkCmdSetFragmentShadingRateKHR vilc_vkCmdSetFragmentShadingRateKHR = NULL;
static PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR vilc_vkGetPhysicalDeviceFragmentShadingRatesKHR = NULL;
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_display_properties2)
static PFN_vkGetDisplayModeProperties2KHR vilc_vkGetDisplayModeProperties2KHR = NULL;
static PFN_vkGetDisplayPlaneCapabilities2KHR vilc_vkGetDisplayPlaneCapabilities2KHR = NULL;
static PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vilc_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = NULL;
static PFN_vkGetPhysicalDeviceDisplayProperties2KHR vilc_vkGetPhysicalDeviceDisplayProperties2KHR = NULL;
#endif /* defined(VK_KHR_get_display_properties2) */
#if defined(VK_KHR_get_memory_requirements2)
static PFN_vkGetBufferMemoryRequirements2KHR vilc_vkGetBufferMemoryRequirements2KHR = NULL;
static PFN_vkGetImageMemoryRequirements2KHR vilc_vkGetImageMemoryRequirements2KHR = NULL;
static PFN_vkGetImageSparseMemoryRequirements2KHR vilc_vkGetImageSparseMemoryRequirements2KHR = NULL;
#endif /* defined(VK_KHR_get_memory_requirements2) */
#if defined(VK_KHR_get_physical_device_properties2)
static PFN_vkGetPhysicalDeviceFeatures2KHR vilc_vkGetPhysicalDeviceFeatures2KHR = NULL;
static PFN_vkGetPhysicalDeviceFormatProperties2KHR vilc_vkGetPhysicalDeviceFormatProperties2KHR = NULL;
static PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vilc_vkGetPhysicalDeviceImageFormatProperties2KHR = NULL;
static PFN_vkGetPhysicalDeviceMemoryProperties2KHR vilc_vkGetPhysicalDeviceMemoryProperties2KHR = NULL;
static PFN_vkGetPhysicalDeviceProperties2KHR vilc_vkGetPhysicalDeviceProperties2KHR = NULL;
static PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vilc_vkGetPhysicalDeviceQueueFamilyProperties2KHR = NULL;
static PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vilc_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = NULL;
#endif /* defined(VK_KHR_get_physical_device_properties2) */
#if defined(VK_KHR_get_surface_capabilities2)
static PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vilc_vkGetPhysicalDeviceSurfaceCapabilities2KHR = NULL;
static PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vilc_vkGetPhysicalDeviceSurfaceFormats2KHR = NULL;
#endif /* defined(VK_KHR_get_surface_capabilities2) */
#if defined(VK_KHR_line_rasterization)
static PFN_vkCmdSetLineStippleKHR vilc_vkCmdSetLineStippleKHR = NULL;
#endif /* defined(VK_KHR_line_rasterization) */
#if defined(VK_KHR_maintenance1)
static PFN_vkTrimCommandPoolKHR vilc_vkTrimCommandPoolKHR = NULL;
#endif /* defined(VK_KHR_maintenance1) */
#if defined(VK_KHR_maintenance10)
static PFN_vkCmdEndRendering2KHR vilc_vkCmdEndRendering2KHR = NULL;
#endif /* defined(VK_KHR_maintenance10) */
#if defined(VK_KHR_maintenance3)
static PFN_vkGetDescriptorSetLayoutSupportKHR vilc_vkGetDescriptorSetLayoutSupportKHR = NULL;
#endif /* defined(VK_KHR_maintenance3) */
#if defined(VK_KHR_maintenance4)
static PFN_vkGetDeviceBufferMemoryRequirementsKHR vilc_vkGetDeviceBufferMemoryRequirementsKHR = NULL;
static PFN_vkGetDeviceImageMemoryRequirementsKHR vilc_vkGetDeviceImageMemoryRequirementsKHR = NULL;
static PFN_vkGetDeviceImageSparseMemoryRequirementsKHR vilc_vkGetDeviceImageSparseMemoryRequirementsKHR = NULL;
#endif /* defined(VK_KHR_maintenance4) */
#if defined(VK_KHR_maintenance5)
static PFN_vkCmdBindIndexBuffer2KHR vilc_vkCmdBindIndexBuffer2KHR = NULL;
static PFN_vkGetDeviceImageSubresourceLayoutKHR vilc_vkGetDeviceImageSubresourceLayoutKHR = NULL;
static PFN_vkGetImageSubresourceLayout2KHR vilc_vkGetImageSubresourceLayout2KHR = NULL;
static PFN_vkGetRenderingAreaGranularityKHR vilc_vkGetRenderingAreaGranularityKHR = NULL;
#endif /* defined(VK_KHR_maintenance5) */
#if defined(VK_KHR_maintenance6)
static PFN_vkCmdBindDescriptorSets2KHR vilc_vkCmdBindDescriptorSets2KHR = NULL;
static PFN_vkCmdPushConstants2KHR vilc_vkCmdPushConstants2KHR = NULL;
#endif /* defined(VK_KHR_maintenance6) */
#if defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor)
static PFN_vkCmdPushDescriptorSet2KHR vilc_vkCmdPushDescriptorSet2KHR = NULL;
static PFN_vkCmdPushDescriptorSetWithTemplate2KHR vilc_vkCmdPushDescriptorSetWithTemplate2KHR = NULL;
#endif /* defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer)
static PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT vilc_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT = NULL;
static PFN_vkCmdSetDescriptorBufferOffsets2EXT vilc_vkCmdSetDescriptorBufferOffsets2EXT = NULL;
#endif /* defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_KHR_map_memory2)
static PFN_vkMapMemory2KHR vilc_vkMapMemory2KHR = NULL;
static PFN_vkUnmapMemory2KHR vilc_vkUnmapMemory2KHR = NULL;
#endif /* defined(VK_KHR_map_memory2) */
#if defined(VK_KHR_performance_query)
static PFN_vkAcquireProfilingLockKHR vilc_vkAcquireProfilingLockKHR = NULL;
static PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vilc_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = NULL;
static PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR vilc_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = NULL;
static PFN_vkReleaseProfilingLockKHR vilc_vkReleaseProfilingLockKHR = NULL;
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_pipeline_binary)
static PFN_vkCreatePipelineBinariesKHR vilc_vkCreatePipelineBinariesKHR = NULL;
static PFN_vkDestroyPipelineBinaryKHR vilc_vkDestroyPipelineBinaryKHR = NULL;
static PFN_vkGetPipelineBinaryDataKHR vilc_vkGetPipelineBinaryDataKHR = NULL;
static PFN_vkGetPipelineKeyKHR vilc_vkGetPipelineKeyKHR = NULL;
static PFN_vkReleaseCapturedPipelineDataKHR vilc_vkReleaseCapturedPipelineDataKHR = NULL;
#endif /* defined(VK_KHR_pipeline_binary) */
#if defined(VK_KHR_pipeline_executable_properties)
static PFN_vkGetPipelineExecutableInternalRepresentationsKHR vilc_vkGetPipelineExecutableInternalRepresentationsKHR = NULL;
static PFN_vkGetPipelineExecutablePropertiesKHR vilc_vkGetPipelineExecutablePropertiesKHR = NULL;
static PFN_vkGetPipelineExecutableStatisticsKHR vilc_vkGetPipelineExecutableStatisticsKHR = NULL;
#endif /* defined(VK_KHR_pipeline_executable_properties) */
#if defined(VK_KHR_present_wait)
static PFN_vkWaitForPresentKHR vilc_vkWaitForPresentKHR = NULL;
#endif /* defined(VK_KHR_present_wait) */
#if defined(VK_KHR_present_wait2)
static PFN_vkWaitForPresent2KHR vilc_vkWaitForPresent2KHR = NULL;
#endif /* defined(VK_KHR_present_wait2) */
#if defined(VK_KHR_push_descriptor)
static PFN_vkCmdPushDescriptorSetKHR vilc_vkCmdPushDescriptorSetKHR = NULL;
#endif /* defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
static PFN_vkCmdTraceRaysIndirect2KHR vilc_vkCmdTraceRaysIndirect2KHR = NULL;
#endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_ray_tracing_pipeline)
static PFN_vkCmdSetRayTracingPipelineStackSizeKHR vilc_vkCmdSetRayTracingPipelineStackSizeKHR = NULL;
static PFN_vkCmdTraceRaysIndirectKHR vilc_vkCmdTraceRaysIndirectKHR = NULL;
static PFN_vkCmdTraceRaysKHR vilc_vkCmdTraceRaysKHR = NULL;
static PFN_vkCreateRayTracingPipelinesKHR vilc_vkCreateRayTracingPipelinesKHR = NULL;
static PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vilc_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = NULL;
static PFN_vkGetRayTracingShaderGroupHandlesKHR vilc_vkGetRayTracingShaderGroupHandlesKHR = NULL;
static PFN_vkGetRayTracingShaderGroupStackSizeKHR vilc_vkGetRayTracingShaderGroupStackSizeKHR = NULL;
#endif /* defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_sampler_ycbcr_conversion)
static PFN_vkCreateSamplerYcbcrConversionKHR vilc_vkCreateSamplerYcbcrConversionKHR = NULL;
static PFN_vkDestroySamplerYcbcrConversionKHR vilc_vkDestroySamplerYcbcrConversionKHR = NULL;
#endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
#if defined(VK_KHR_shared_presentable_image)
static PFN_vkGetSwapchainStatusKHR vilc_vkGetSwapchainStatusKHR = NULL;
#endif /* defined(VK_KHR_shared_presentable_image) */
#if defined(VK_KHR_surface)
static PFN_vkDestroySurfaceKHR vilc_vkDestroySurfaceKHR = NULL;
static PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vilc_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = NULL;
static PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vilc_vkGetPhysicalDeviceSurfaceFormatsKHR = NULL;
static PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vilc_vkGetPhysicalDeviceSurfacePresentModesKHR = NULL;
static PFN_vkGetPhysicalDeviceSurfaceSupportKHR vilc_vkGetPhysicalDeviceSurfaceSupportKHR = NULL;
#endif /* defined(VK_KHR_surface) */
#if defined(VK_KHR_swapchain)
static PFN_vkAcquireNextImageKHR vilc_vkAcquireNextImageKHR = NULL;
static PFN_vkCreateSwapchainKHR vilc_vkCreateSwapchainKHR = NULL;
static PFN_vkDestroySwapchainKHR vilc_vkDestroySwapchainKHR = NULL;
static PFN_vkGetSwapchainImagesKHR vilc_vkGetSwapchainImagesKHR = NULL;
static PFN_vkQueuePresentKHR vilc_vkQueuePresentKHR = NULL;
#endif /* defined(VK_KHR_swapchain) */
#if defined(VK_KHR_swapchain_maintenance1)
static PFN_vkReleaseSwapchainImagesKHR vilc_vkReleaseSwapchainImagesKHR = NULL;
#endif /* defined(VK_KHR_swapchain_maintenance1) */
#if defined(VK_KHR_synchronization2)
static PFN_vkCmdPipelineBarrier2KHR vilc_vkCmdPipelineBarrier2KHR = NULL;
static PFN_vkCmdResetEvent2KHR vilc_vkCmdResetEvent2KHR = NULL;
static PFN_vkCmdSetEvent2KHR vilc_vkCmdSetEvent2KHR = NULL;
static PFN_vkCmdWaitEvents2KHR vilc_vkCmdWaitEvents2KHR = NULL;
static PFN_vkCmdWriteTimestamp2KHR vilc_vkCmdWriteTimestamp2KHR = NULL;
static PFN_vkQueueSubmit2KHR vilc_vkQueueSubmit2KHR = NULL;
#endif /* defined(VK_KHR_synchronization2) */
#if defined(VK_KHR_timeline_semaphore)
static PFN_vkGetSemaphoreCounterValueKHR vilc_vkGetSemaphoreCounterValueKHR = NULL;
static PFN_vkSignalSemaphoreKHR vilc_vkSignalSemaphoreKHR = NULL;
static PFN_vkWaitSemaphoresKHR vilc_vkWaitSemaphoresKHR = NULL;
#endif /* defined(VK_KHR_timeline_semaphore) */
#if defined(VK_KHR_video_decode_queue)
static PFN_vkCmdDecodeVideoKHR vilc_vkCmdDecodeVideoKHR = NULL;
#endif /* defined(VK_KHR_video_decode_queue) */
#if defined(VK_KHR_video_encode_queue)
static PFN_vkCmdEncodeVideoKHR vilc_vkCmdEncodeVideoKHR = NULL;
static PFN_vkGetEncodedVideoSessionParametersKHR vilc_vkGetEncodedVideoSessionParametersKHR = NULL;
static PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR vilc_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = NULL;
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
static PFN_vkBindVideoSessionMemoryKHR vilc_vkBindVideoSessionMemoryKHR = NULL;
static PFN_vkCmdBeginVideoCodingKHR vilc_vkCmdBeginVideoCodingKHR = NULL;
static PFN_vkCmdControlVideoCodingKHR vilc_vkCmdControlVideoCodingKHR = NULL;
static PFN_vkCmdEndVideoCodingKHR vilc_vkCmdEndVideoCodingKHR = NULL;
static PFN_vkCreateVideoSessionKHR vilc_vkCreateVideoSessionKHR = NULL;
static PFN_vkCreateVideoSessionParametersKHR vilc_vkCreateVideoSessionParametersKHR = NULL;
static PFN_vkDestroyVideoSessionKHR vilc_vkDestroyVideoSessionKHR = NULL;
static PFN_vkDestroyVideoSessionParametersKHR vilc_vkDestroyVideoSessionParametersKHR = NULL;
static PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR vilc_vkGetPhysicalDeviceVideoCapabilitiesKHR = NULL;
static PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR vilc_vkGetPhysicalDeviceVideoFormatPropertiesKHR = NULL;
static PFN_vkGetVideoSessionMemoryRequirementsKHR vilc_vkGetVideoSessionMemoryRequirementsKHR = NULL;
static PFN_vkUpdateVideoSessionParametersKHR vilc_vkUpdateVideoSessionParametersKHR = NULL;
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_KHR_wayland_surface)
static PFN_vkCreateWaylandSurfaceKHR vilc_vkCreateWaylandSurfaceKHR = NULL;
static PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vilc_vkGetPhysicalDeviceWaylandPresentationSupportKHR = NULL;
#endif /* defined(VK_KHR_wayland_surface) */
#if defined(VK_KHR_win32_surface)
static PFN_vkCreateWin32SurfaceKHR vilc_vkCreateWin32SurfaceKHR = NULL;
static PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vilc_vkGetPhysicalDeviceWin32PresentationSupportKHR = NULL;
#endif /* defined(VK_KHR_win32_surface) */
#if defined(VK_KHR_xcb_surface)
static PFN_vkCreateXcbSurfaceKHR vilc_vkCreateXcbSurfaceKHR = NULL;
static PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vilc_vkGetPhysicalDeviceXcbPresentationSupportKHR = NULL;
#endif /* defined(VK_KHR_xcb_surface) */
#if defined(VK_KHR_xlib_surface)
static PFN_vkCreateXlibSurfaceKHR vilc_vkCreateXlibSurfaceKHR = NULL;
static PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vilc_vkGetPhysicalDeviceXlibPresentationSupportKHR = NULL;
#endif /* defined(VK_KHR_xlib_surface) */
#if defined(VK_MVK_ios_surface)
static PFN_vkCreateIOSSurfaceMVK vilc_vkCreateIOSSurfaceMVK = NULL;
#endif /* defined(VK_MVK_ios_surface) */
#if defined(VK_MVK_macos_surface)
static PFN_vkCreateMacOSSurfaceMVK vilc_vkCreateMacOSSurfaceMVK = NULL;
#endif /* defined(VK_MVK_macos_surface) */
#if defined(VK_NN_vi_surface)
static PFN_vkCreateViSurfaceNN vilc_vkCreateViSurfaceNN = NULL;
#endif /* defined(VK_NN_vi_surface) */
#if defined(VK_NVX_binary_import)
static PFN_vkCmdCuLaunchKernelNVX vilc_vkCmdCuLaunchKernelNVX = NULL;
static PFN_vkCreateCuFunctionNVX vilc_vkCreateCuFunctionNVX = NULL;
static PFN_vkCreateCuModuleNVX vilc_vkCreateCuModuleNVX = NULL;
static PFN_vkDestroyCuFunctionNVX vilc_vkDestroyCuFunctionNVX = NULL;
static PFN_vkDestroyCuModuleNVX vilc_vkDestroyCuModuleNVX = NULL;
#endif /* defined(VK_NVX_binary_import) */
#if defined(VK_NVX_image_view_handle)
static PFN_vkGetImageViewHandleNVX vilc_vkGetImageViewHandleNVX = NULL;
#endif /* defined(VK_NVX_image_view_handle) */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3
static PFN_vkGetImageViewHandle64NVX vilc_vkGetImageViewHandle64NVX = NULL;
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3 */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2
static PFN_vkGetImageViewAddressNVX vilc_vkGetImageViewAddressNVX = NULL;
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2 */
#if defined(VK_NV_acquire_winrt_display)
static PFN_vkAcquireWinrtDisplayNV vilc_vkAcquireWinrtDisplayNV = NULL;
static PFN_vkGetWinrtDisplayNV vilc_vkGetWinrtDisplayNV = NULL;
#endif /* defined(VK_NV_acquire_winrt_display) */
#if defined(VK_NV_clip_space_w_scaling)
static PFN_vkCmdSetViewportWScalingNV vilc_vkCmdSetViewportWScalingNV = NULL;
#endif /* defined(VK_NV_clip_space_w_scaling) */
#if defined(VK_NV_cluster_acceleration_structure)
static PFN_vkCmdBuildClusterAccelerationStructureIndirectNV vilc_vkCmdBuildClusterAccelerationStructureIndirectNV = NULL;
static PFN_vkGetClusterAccelerationStructureBuildSizesNV vilc_vkGetClusterAccelerationStructureBuildSizesNV = NULL;
#endif /* defined(VK_NV_cluster_acceleration_structure) */
#if defined(VK_NV_compute_occupancy_priority)
static PFN_vkCmdSetComputeOccupancyPriorityNV vilc_vkCmdSetComputeOccupancyPriorityNV = NULL;
#endif /* defined(VK_NV_compute_occupancy_priority) */
#if defined(VK_NV_cooperative_matrix)
static PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vilc_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = NULL;
#endif /* defined(VK_NV_cooperative_matrix) */
#if defined(VK_NV_cooperative_matrix2)
static PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV vilc_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV = NULL;
#endif /* defined(VK_NV_cooperative_matrix2) */
#if defined(VK_NV_cooperative_vector)
static PFN_vkCmdConvertCooperativeVectorMatrixNV vilc_vkCmdConvertCooperativeVectorMatrixNV = NULL;
static PFN_vkConvertCooperativeVectorMatrixNV vilc_vkConvertCooperativeVectorMatrixNV = NULL;
static PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV vilc_vkGetPhysicalDeviceCooperativeVectorPropertiesNV = NULL;
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_copy_memory_indirect)
static PFN_vkCmdCopyMemoryIndirectNV vilc_vkCmdCopyMemoryIndirectNV = NULL;
static PFN_vkCmdCopyMemoryToImageIndirectNV vilc_vkCmdCopyMemoryToImageIndirectNV = NULL;
#endif /* defined(VK_NV_copy_memory_indirect) */
#if defined(VK_NV_coverage_reduction_mode)
static PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vilc_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = NULL;
#endif /* defined(VK_NV_coverage_reduction_mode) */
#if defined(VK_NV_cuda_kernel_launch)
static PFN_vkCmdCudaLaunchKernelNV vilc_vkCmdCudaLaunchKernelNV = NULL;
static PFN_vkCreateCudaFunctionNV vilc_vkCreateCudaFunctionNV = NULL;
static PFN_vkCreateCudaModuleNV vilc_vkCreateCudaModuleNV = NULL;
static PFN_vkDestroyCudaFunctionNV vilc_vkDestroyCudaFunctionNV = NULL;
static PFN_vkDestroyCudaModuleNV vilc_vkDestroyCudaModuleNV = NULL;
static PFN_vkGetCudaModuleCacheNV vilc_vkGetCudaModuleCacheNV = NULL;
#endif /* defined(VK_NV_cuda_kernel_launch) */
#if defined(VK_NV_device_diagnostic_checkpoints)
static PFN_vkCmdSetCheckpointNV vilc_vkCmdSetCheckpointNV = NULL;
static PFN_vkGetQueueCheckpointDataNV vilc_vkGetQueueCheckpointDataNV = NULL;
#endif /* defined(VK_NV_device_diagnostic_checkpoints) */
#if defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
static PFN_vkGetQueueCheckpointData2NV vilc_vkGetQueueCheckpointData2NV = NULL;
#endif /* defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_NV_device_generated_commands)
static PFN_vkCmdBindPipelineShaderGroupNV vilc_vkCmdBindPipelineShaderGroupNV = NULL;
static PFN_vkCmdExecuteGeneratedCommandsNV vilc_vkCmdExecuteGeneratedCommandsNV = NULL;
static PFN_vkCmdPreprocessGeneratedCommandsNV vilc_vkCmdPreprocessGeneratedCommandsNV = NULL;
static PFN_vkCreateIndirectCommandsLayoutNV vilc_vkCreateIndirectCommandsLayoutNV = NULL;
static PFN_vkDestroyIndirectCommandsLayoutNV vilc_vkDestroyIndirectCommandsLayoutNV = NULL;
static PFN_vkGetGeneratedCommandsMemoryRequirementsNV vilc_vkGetGeneratedCommandsMemoryRequirementsNV = NULL;
#endif /* defined(VK_NV_device_generated_commands) */
#if defined(VK_NV_device_generated_commands_compute)
static PFN_vkCmdUpdatePipelineIndirectBufferNV vilc_vkCmdUpdatePipelineIndirectBufferNV = NULL;
static PFN_vkGetPipelineIndirectDeviceAddressNV vilc_vkGetPipelineIndirectDeviceAddressNV = NULL;
static PFN_vkGetPipelineIndirectMemoryRequirementsNV vilc_vkGetPipelineIndirectMemoryRequirementsNV = NULL;
#endif /* defined(VK_NV_device_generated_commands_compute) */
#if defined(VK_NV_external_compute_queue)
static PFN_vkCreateExternalComputeQueueNV vilc_vkCreateExternalComputeQueueNV = NULL;
static PFN_vkDestroyExternalComputeQueueNV vilc_vkDestroyExternalComputeQueueNV = NULL;
static PFN_vkGetExternalComputeQueueDataNV vilc_vkGetExternalComputeQueueDataNV = NULL;
#endif /* defined(VK_NV_external_compute_queue) */
#if defined(VK_NV_external_memory_capabilities)
static PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vilc_vkGetPhysicalDeviceExternalImageFormatPropertiesNV = NULL;
#endif /* defined(VK_NV_external_memory_capabilities) */
#if defined(VK_NV_external_memory_rdma)
static PFN_vkGetMemoryRemoteAddressNV vilc_vkGetMemoryRemoteAddressNV = NULL;
#endif /* defined(VK_NV_external_memory_rdma) */
#if defined(VK_NV_external_memory_win32)
static PFN_vkGetMemoryWin32HandleNV vilc_vkGetMemoryWin32HandleNV = NULL;
#endif /* defined(VK_NV_external_memory_win32) */
#if defined(VK_NV_fragment_shading_rate_enums)
static PFN_vkCmdSetFragmentShadingRateEnumNV vilc_vkCmdSetFragmentShadingRateEnumNV = NULL;
#endif /* defined(VK_NV_fragment_shading_rate_enums) */
#if defined(VK_NV_low_latency2)
static PFN_vkGetLatencyTimingsNV vilc_vkGetLatencyTimingsNV = NULL;
static PFN_vkLatencySleepNV vilc_vkLatencySleepNV = NULL;
static PFN_vkQueueNotifyOutOfBandNV vilc_vkQueueNotifyOutOfBandNV = NULL;
static PFN_vkSetLatencyMarkerNV vilc_vkSetLatencyMarkerNV = NULL;
static PFN_vkSetLatencySleepModeNV vilc_vkSetLatencySleepModeNV = NULL;
#endif /* defined(VK_NV_low_latency2) */
#if defined(VK_NV_memory_decompression)
static PFN_vkCmdDecompressMemoryIndirectCountNV vilc_vkCmdDecompressMemoryIndirectCountNV = NULL;
static PFN_vkCmdDecompressMemoryNV vilc_vkCmdDecompressMemoryNV = NULL;
#endif /* defined(VK_NV_memory_decompression) */
#if defined(VK_NV_mesh_shader)
static PFN_vkCmdDrawMeshTasksIndirectNV vilc_vkCmdDrawMeshTasksIndirectNV = NULL;
static PFN_vkCmdDrawMeshTasksNV vilc_vkCmdDrawMeshTasksNV = NULL;
#endif /* defined(VK_NV_mesh_shader) */
#if defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
static PFN_vkCmdDrawMeshTasksIndirectCountNV vilc_vkCmdDrawMeshTasksIndirectCountNV = NULL;
#endif /* defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_NV_optical_flow)
static PFN_vkBindOpticalFlowSessionImageNV vilc_vkBindOpticalFlowSessionImageNV = NULL;
static PFN_vkCmdOpticalFlowExecuteNV vilc_vkCmdOpticalFlowExecuteNV = NULL;
static PFN_vkCreateOpticalFlowSessionNV vilc_vkCreateOpticalFlowSessionNV = NULL;
static PFN_vkDestroyOpticalFlowSessionNV vilc_vkDestroyOpticalFlowSessionNV = NULL;
static PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV vilc_vkGetPhysicalDeviceOpticalFlowImageFormatsNV = NULL;
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_NV_partitioned_acceleration_structure)
static PFN_vkCmdBuildPartitionedAccelerationStructuresNV vilc_vkCmdBuildPartitionedAccelerationStructuresNV = NULL;
static PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV vilc_vkGetPartitionedAccelerationStructuresBuildSizesNV = NULL;
#endif /* defined(VK_NV_partitioned_acceleration_structure) */
#if defined(VK_NV_ray_tracing)
static PFN_vkBindAccelerationStructureMemoryNV vilc_vkBindAccelerationStructureMemoryNV = NULL;
static PFN_vkCmdBuildAccelerationStructureNV vilc_vkCmdBuildAccelerationStructureNV = NULL;
static PFN_vkCmdCopyAccelerationStructureNV vilc_vkCmdCopyAccelerationStructureNV = NULL;
static PFN_vkCmdTraceRaysNV vilc_vkCmdTraceRaysNV = NULL;
static PFN_vkCmdWriteAccelerationStructuresPropertiesNV vilc_vkCmdWriteAccelerationStructuresPropertiesNV = NULL;
static PFN_vkCompileDeferredNV vilc_vkCompileDeferredNV = NULL;
static PFN_vkCreateAccelerationStructureNV vilc_vkCreateAccelerationStructureNV = NULL;
static PFN_vkCreateRayTracingPipelinesNV vilc_vkCreateRayTracingPipelinesNV = NULL;
static PFN_vkDestroyAccelerationStructureNV vilc_vkDestroyAccelerationStructureNV = NULL;
static PFN_vkGetAccelerationStructureHandleNV vilc_vkGetAccelerationStructureHandleNV = NULL;
static PFN_vkGetAccelerationStructureMemoryRequirementsNV vilc_vkGetAccelerationStructureMemoryRequirementsNV = NULL;
static PFN_vkGetRayTracingShaderGroupHandlesNV vilc_vkGetRayTracingShaderGroupHandlesNV = NULL;
#endif /* defined(VK_NV_ray_tracing) */
#if defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2
static PFN_vkCmdSetExclusiveScissorEnableNV vilc_vkCmdSetExclusiveScissorEnableNV = NULL;
#endif /* defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2 */
#if defined(VK_NV_scissor_exclusive)
static PFN_vkCmdSetExclusiveScissorNV vilc_vkCmdSetExclusiveScissorNV = NULL;
#endif /* defined(VK_NV_scissor_exclusive) */
#if defined(VK_NV_shading_rate_image)
static PFN_vkCmdBindShadingRateImageNV vilc_vkCmdBindShadingRateImageNV = NULL;
static PFN_vkCmdSetCoarseSampleOrderNV vilc_vkCmdSetCoarseSampleOrderNV = NULL;
static PFN_vkCmdSetViewportShadingRatePaletteNV vilc_vkCmdSetViewportShadingRatePaletteNV = NULL;
#endif /* defined(VK_NV_shading_rate_image) */
#if defined(VK_OHOS_external_memory)
static PFN_vkGetMemoryNativeBufferOHOS vilc_vkGetMemoryNativeBufferOHOS = NULL;
static PFN_vkGetNativeBufferPropertiesOHOS vilc_vkGetNativeBufferPropertiesOHOS = NULL;
#endif /* defined(VK_OHOS_external_memory) */
#if defined(VK_OHOS_surface)
static PFN_vkCreateSurfaceOHOS vilc_vkCreateSurfaceOHOS = NULL;
#endif /* defined(VK_OHOS_surface) */
#if defined(VK_QCOM_tile_memory_heap)
static PFN_vkCmdBindTileMemoryQCOM vilc_vkCmdBindTileMemoryQCOM = NULL;
#endif /* defined(VK_QCOM_tile_memory_heap) */
#if defined(VK_QCOM_tile_properties)
static PFN_vkGetDynamicRenderingTilePropertiesQCOM vilc_vkGetDynamicRenderingTilePropertiesQCOM = NULL;
static PFN_vkGetFramebufferTilePropertiesQCOM vilc_vkGetFramebufferTilePropertiesQCOM = NULL;
#endif /* defined(VK_QCOM_tile_properties) */
#if defined(VK_QCOM_tile_shading)
static PFN_vkCmdBeginPerTileExecutionQCOM vilc_vkCmdBeginPerTileExecutionQCOM = NULL;
static PFN_vkCmdDispatchTileQCOM vilc_vkCmdDispatchTileQCOM = NULL;
static PFN_vkCmdEndPerTileExecutionQCOM vilc_vkCmdEndPerTileExecutionQCOM = NULL;
#endif /* defined(VK_QCOM_tile_shading) */
#if defined(VK_QNX_external_memory_screen_buffer)
static PFN_vkGetScreenBufferPropertiesQNX vilc_vkGetScreenBufferPropertiesQNX = NULL;
#endif /* defined(VK_QNX_external_memory_screen_buffer) */
#if defined(VK_QNX_screen_surface)
static PFN_vkCreateScreenSurfaceQNX vilc_vkCreateScreenSurfaceQNX = NULL;
static PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX vilc_vkGetPhysicalDeviceScreenPresentationSupportQNX = NULL;
#endif /* defined(VK_QNX_screen_surface) */
#if defined(VK_VALVE_descriptor_set_host_mapping)
static PFN_vkGetDescriptorSetHostMappingVALVE vilc_vkGetDescriptorSetHostMappingVALVE = NULL;
static PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vilc_vkGetDescriptorSetLayoutHostMappingInfoVALVE = NULL;
#endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
#if (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control))
static PFN_vkCmdSetDepthClampRangeEXT vilc_vkCmdSetDepthClampRangeEXT = NULL;
#endif /* (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control)) */
#if (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object))
static PFN_vkCmdBindVertexBuffers2EXT vilc_vkCmdBindVertexBuffers2EXT = NULL;
static PFN_vkCmdSetCullModeEXT vilc_vkCmdSetCullModeEXT = NULL;
static PFN_vkCmdSetDepthBoundsTestEnableEXT vilc_vkCmdSetDepthBoundsTestEnableEXT = NULL;
static PFN_vkCmdSetDepthCompareOpEXT vilc_vkCmdSetDepthCompareOpEXT = NULL;
static PFN_vkCmdSetDepthTestEnableEXT vilc_vkCmdSetDepthTestEnableEXT = NULL;
static PFN_vkCmdSetDepthWriteEnableEXT vilc_vkCmdSetDepthWriteEnableEXT = NULL;
static PFN_vkCmdSetFrontFaceEXT vilc_vkCmdSetFrontFaceEXT = NULL;
static PFN_vkCmdSetPrimitiveTopologyEXT vilc_vkCmdSetPrimitiveTopologyEXT = NULL;
static PFN_vkCmdSetScissorWithCountEXT vilc_vkCmdSetScissorWithCountEXT = NULL;
static PFN_vkCmdSetStencilOpEXT vilc_vkCmdSetStencilOpEXT = NULL;
static PFN_vkCmdSetStencilTestEnableEXT vilc_vkCmdSetStencilTestEnableEXT = NULL;
static PFN_vkCmdSetViewportWithCountEXT vilc_vkCmdSetViewportWithCountEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object))
static PFN_vkCmdSetDepthBiasEnableEXT vilc_vkCmdSetDepthBiasEnableEXT = NULL;
static PFN_vkCmdSetLogicOpEXT vilc_vkCmdSetLogicOpEXT = NULL;
static PFN_vkCmdSetPatchControlPointsEXT vilc_vkCmdSetPatchControlPointsEXT = NULL;
static PFN_vkCmdSetPrimitiveRestartEnableEXT vilc_vkCmdSetPrimitiveRestartEnableEXT = NULL;
static PFN_vkCmdSetRasterizerDiscardEnableEXT vilc_vkCmdSetRasterizerDiscardEnableEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object))
static PFN_vkCmdSetAlphaToCoverageEnableEXT vilc_vkCmdSetAlphaToCoverageEnableEXT = NULL;
static PFN_vkCmdSetAlphaToOneEnableEXT vilc_vkCmdSetAlphaToOneEnableEXT = NULL;
static PFN_vkCmdSetColorBlendEnableEXT vilc_vkCmdSetColorBlendEnableEXT = NULL;
static PFN_vkCmdSetColorBlendEquationEXT vilc_vkCmdSetColorBlendEquationEXT = NULL;
static PFN_vkCmdSetColorWriteMaskEXT vilc_vkCmdSetColorWriteMaskEXT = NULL;
static PFN_vkCmdSetDepthClampEnableEXT vilc_vkCmdSetDepthClampEnableEXT = NULL;
static PFN_vkCmdSetLogicOpEnableEXT vilc_vkCmdSetLogicOpEnableEXT = NULL;
static PFN_vkCmdSetPolygonModeEXT vilc_vkCmdSetPolygonModeEXT = NULL;
static PFN_vkCmdSetRasterizationSamplesEXT vilc_vkCmdSetRasterizationSamplesEXT = NULL;
static PFN_vkCmdSetSampleMaskEXT vilc_vkCmdSetSampleMaskEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object))
static PFN_vkCmdSetTessellationDomainOriginEXT vilc_vkCmdSetTessellationDomainOriginEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback))
static PFN_vkCmdSetRasterizationStreamEXT vilc_vkCmdSetRasterizationStreamEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization))
static PFN_vkCmdSetConservativeRasterizationModeEXT vilc_vkCmdSetConservativeRasterizationModeEXT = NULL;
static PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT vilc_vkCmdSetExtraPrimitiveOverestimationSizeEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable))
static PFN_vkCmdSetDepthClipEnableEXT vilc_vkCmdSetDepthClipEnableEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations))
static PFN_vkCmdSetSampleLocationsEnableEXT vilc_vkCmdSetSampleLocationsEnableEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced))
static PFN_vkCmdSetColorBlendAdvancedEXT vilc_vkCmdSetColorBlendAdvancedEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex))
static PFN_vkCmdSetProvokingVertexModeEXT vilc_vkCmdSetProvokingVertexModeEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization))
static PFN_vkCmdSetLineRasterizationModeEXT vilc_vkCmdSetLineRasterizationModeEXT = NULL;
static PFN_vkCmdSetLineStippleEnableEXT vilc_vkCmdSetLineStippleEnableEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control))
static PFN_vkCmdSetDepthClipNegativeOneToOneEXT vilc_vkCmdSetDepthClipNegativeOneToOneEXT = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling))
static PFN_vkCmdSetViewportWScalingEnableNV vilc_vkCmdSetViewportWScalingEnableNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle))
static PFN_vkCmdSetViewportSwizzleNV vilc_vkCmdSetViewportSwizzleNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color))
static PFN_vkCmdSetCoverageToColorEnableNV vilc_vkCmdSetCoverageToColorEnableNV = NULL;
static PFN_vkCmdSetCoverageToColorLocationNV vilc_vkCmdSetCoverageToColorLocationNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples))
static PFN_vkCmdSetCoverageModulationModeNV vilc_vkCmdSetCoverageModulationModeNV = NULL;
static PFN_vkCmdSetCoverageModulationTableEnableNV vilc_vkCmdSetCoverageModulationTableEnableNV = NULL;
static PFN_vkCmdSetCoverageModulationTableNV vilc_vkCmdSetCoverageModulationTableNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image))
static PFN_vkCmdSetShadingRateImageEnableNV vilc_vkCmdSetShadingRateImageEnableNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test))
static PFN_vkCmdSetRepresentativeFragmentTestEnableNV vilc_vkCmdSetRepresentativeFragmentTestEnableNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode))
static PFN_vkCmdSetCoverageReductionModeNV vilc_vkCmdSetCoverageReductionModeNV = NULL;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode)) */
#if (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control))
static PFN_vkGetImageSubresourceLayout2EXT vilc_vkGetImageSubresourceLayout2EXT = NULL;
#endif /* (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control)) */
#if (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state))
static PFN_vkCmdSetVertexInputEXT vilc_vkCmdSetVertexInputEXT = NULL;
#endif /* (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state)) */
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)))
static PFN_vkCmdPushDescriptorSetWithTemplateKHR vilc_vkCmdPushDescriptorSetWithTemplateKHR = NULL;
#endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template))) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
static PFN_vkGetDeviceGroupPresentCapabilitiesKHR vilc_vkGetDeviceGroupPresentCapabilitiesKHR = NULL;
static PFN_vkGetDeviceGroupSurfacePresentModesKHR vilc_vkGetDeviceGroupSurfacePresentModesKHR = NULL;
static PFN_vkGetPhysicalDevicePresentRectanglesKHR vilc_vkGetPhysicalDevicePresentRectanglesKHR = NULL;
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
static PFN_vkAcquireNextImage2KHR vilc_vkAcquireNextImage2KHR = NULL;
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_DECLODATION_C_VILC */
#endif

#if defined(VOLK_IN_LOADERS_CLOTH)
PFN_vkVoidFunction vk_icdGetInstanceProcAddr(
    VkInstance                                  instance,
    const char*                                 pName
);
static PFN_vkVoidFunction vkGetInstanceProcAddrStub(void* context, const char* name)
{
	return vilc_vkGetInstanceProcAddr((VkInstance)context, name);
}
static PFN_vkVoidFunction vkGetDeviceProcAddrStub(void* context, const char* name)
{
	return vilc_vkGetDeviceProcAddr((VkDevice)context, name);
}

static void vilc_init() {
	vilc_vkGetInstanceProcAddr = vk_icdGetInstanceProcAddr;
	volkGenLoadLoader(NULL, vkGetInstanceProcAddrStub);
}

static pthread_once_t vilc_init_once_control = PTHREAD_ONCE_INIT;

static void vilc_initOnce() {
	pthread_once(&vilc_init_once_control, vilc_init);
}
#endif

#if !defined(VOLK_IN_LOADERS_CLOTH)
static PFN_vkVoidFunction vkGetInstanceProcAddrStub(void* context, const char* name)
{
	return vkGetInstanceProcAddr((VkInstance)context, name);
}

static PFN_vkVoidFunction vkGetDeviceProcAddrStub(void* context, const char* name)
{
	return vkGetDeviceProcAddr((VkDevice)context, name);
}

static PFN_vkVoidFunction nullProcAddrStub(void* context, const char* name)
{
	(void)context;
	(void)name;
	return NULL;
}

VkResult volkInitialize(void)
{
#if defined(_WIN32)
	HMODULE module = LoadLibraryA("vulkan-1.dll");
	if (!module)
		return VK_ERROR_INITIALIZATION_FAILED;

	// note: function pointer is cast through void function pointer to silence cast-function-type warning on gcc8
	vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)(void(*)(void))GetProcAddress(module, "vkGetInstanceProcAddr");
#elif defined(__APPLE__)
	void* module = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
	if (!module)
		module = dlopen("libvulkan.1.dylib", RTLD_NOW | RTLD_LOCAL);
	// modern versions of macOS don't search /usr/local/lib automatically contrary to what man dlopen says
	// Vulkan SDK uses this as the system-wide installation location, so we're going to fallback to this if all else fails
	if (!module && getenv("DYLD_FALLBACK_LIBRARY_PATH") == NULL)
		module = dlopen("/usr/local/lib/libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
	if (!module)
		module = dlopen("libMoltenVK.dylib", RTLD_NOW | RTLD_LOCAL);
	// Add support for using Vulkan and MoltenVK in a Framework. App store rules for iOS
	// strictly enforce no .dylib's. If they aren't found it just falls through
	if (!module)
		module = dlopen("vulkan.framework/vulkan", RTLD_NOW | RTLD_LOCAL);
	if (!module)
		module = dlopen("MoltenVK.framework/MoltenVK", RTLD_NOW | RTLD_LOCAL);
	if (!module)
		return VK_ERROR_INITIALIZATION_FAILED;

	vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(module, "vkGetInstanceProcAddr");
#else
	void* module = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
	if (!module)
		module = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
	if (!module)
		return VK_ERROR_INITIALIZATION_FAILED;
	VOLK_DISABLE_GCC_PEDANTIC_WARNINGS
	vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(module, "vkGetInstanceProcAddr");
	VOLK_RESTORE_GCC_PEDANTIC_WARNINGS
#endif

	loadedModule = module;
	volkGenLoadLoader(NULL, vkGetInstanceProcAddrStub);

	return VK_SUCCESS;
}

void volkInitializeCustom(PFN_vkGetInstanceProcAddr handler)
{
	vkGetInstanceProcAddr = handler;

	loadedModule = NULL;
	volkGenLoadLoader(NULL, vkGetInstanceProcAddrStub);
}

void volkFinalize(void)
{
	if (loadedModule)
	{
#if defined(_WIN32)
		FreeLibrary((HMODULE)loadedModule);
#else
		dlclose(loadedModule);
#endif
	}

	vkGetInstanceProcAddr = NULL;
	volkGenLoadLoader(NULL, nullProcAddrStub);
	volkGenLoadInstance(NULL, nullProcAddrStub);
	volkGenLoadDevice(NULL, nullProcAddrStub);

	loadedModule = NULL;
	loadedInstance = VK_NULL_HANDLE;
	loadedDevice = VK_NULL_HANDLE;
}

uint32_t volkGetInstanceVersion(void)
{
#if defined(VK_VERSION_1_1)
	uint32_t apiVersion = 0;
	if (vkEnumerateInstanceVersion && vkEnumerateInstanceVersion(&apiVersion) == VK_SUCCESS)
		return apiVersion;
#endif

	if (vkCreateInstance)
		return VK_API_VERSION_1_0;

	return 0;
}

void volkLoadInstance(VkInstance instance)
{
	loadedInstance = instance;
	volkGenLoadInstance(instance, vkGetInstanceProcAddrStub);
	volkGenLoadDevice(instance, vkGetInstanceProcAddrStub);
}

void volkLoadInstanceOnly(VkInstance instance)
{
	loadedInstance = instance;
	volkGenLoadInstance(instance, vkGetInstanceProcAddrStub);
}

VkInstance volkGetLoadedInstance(void)
{
	return loadedInstance;
}

void volkLoadDevice(VkDevice device)
{
	loadedDevice = device;
	volkGenLoadDevice(device, vkGetDeviceProcAddrStub);
}

VkDevice volkGetLoadedDevice(void)
{
	return loadedDevice;
}

void volkLoadInstanceTable(struct VolkInstanceTable* table, VkInstance instance)
{
	/* vkGetDeviceProcAddr is used by volkLoadDeviceTable; for now we load this global pointer even though it might be instance-specific */
	vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr");

	memset(table, 0, sizeof(*table));
	volkGenLoadInstanceTable(table, instance, vkGetInstanceProcAddrStub);
}

void volkLoadDeviceTable(struct VolkDeviceTable* table, VkDevice device)
{
	memset(table, 0, sizeof(*table));
	volkGenLoadDeviceTable(table, device, vkGetDeviceProcAddrStub);
}
#endif

static void volkGenLoadLoader(void* context, PFN_vkVoidFunction (*load)(void*, const char*))
{
#if defined(VOLK_IN_LOADERS_CLOTH)
	/* VOLK_GENERATE_LOAD_LOADER_VILC */
#if defined(VK_VERSION_1_0)
	vilc_vkCreateInstance = (PFN_vkCreateInstance)load(context, "vkCreateInstance");
	vilc_vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)load(context, "vkEnumerateInstanceExtensionProperties");
	vilc_vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)load(context, "vkEnumerateInstanceLayerProperties");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	vilc_vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)load(context, "vkEnumerateInstanceVersion");
#endif /* defined(VK_VERSION_1_1) */
	/* VOLK_GENERATE_LOAD_LOADER_VILC */
#else /* VOLK_IN_LOADERS_CLOTH */
	/* VOLK_GENERATE_LOAD_LOADER */
#if defined(VK_VERSION_1_0)
	vkCreateInstance = (PFN_vkCreateInstance)load(context, "vkCreateInstance");
	vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)load(context, "vkEnumerateInstanceExtensionProperties");
	vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)load(context, "vkEnumerateInstanceLayerProperties");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)load(context, "vkEnumerateInstanceVersion");
#endif /* defined(VK_VERSION_1_1) */
	/* VOLK_GENERATE_LOAD_LOADER */
#endif /* VOLK_IN_LOADERS_CLOTH */
}

static void volkGenLoadInstance(void* context, PFN_vkVoidFunction (*load)(void*, const char*))
{
#if defined(VOLK_IN_LOADERS_CLOTH)
	/* VOLK_GENERATE_LOAD_INSTANCE_VILC */
#if defined(VK_VERSION_1_0)
	vilc_vkCreateDevice = (PFN_vkCreateDevice)load(context, "vkCreateDevice");
	vilc_vkDestroyInstance = (PFN_vkDestroyInstance)load(context, "vkDestroyInstance");
	vilc_vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)load(context, "vkEnumerateDeviceExtensionProperties");
	vilc_vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)load(context, "vkEnumerateDeviceLayerProperties");
	vilc_vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)load(context, "vkEnumeratePhysicalDevices");
	vilc_vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)load(context, "vkGetDeviceProcAddr");
	vilc_vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)load(context, "vkGetPhysicalDeviceFeatures");
	vilc_vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)load(context, "vkGetPhysicalDeviceFormatProperties");
	vilc_vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)load(context, "vkGetPhysicalDeviceImageFormatProperties");
	vilc_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)load(context, "vkGetPhysicalDeviceMemoryProperties");
	vilc_vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)load(context, "vkGetPhysicalDeviceProperties");
	vilc_vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)load(context, "vkGetPhysicalDeviceQueueFamilyProperties");
	vilc_vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	vilc_vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)load(context, "vkEnumeratePhysicalDeviceGroups");
	vilc_vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)load(context, "vkGetPhysicalDeviceExternalBufferProperties");
	vilc_vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)load(context, "vkGetPhysicalDeviceExternalFenceProperties");
	vilc_vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)load(context, "vkGetPhysicalDeviceExternalSemaphoreProperties");
	vilc_vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)load(context, "vkGetPhysicalDeviceFeatures2");
	vilc_vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)load(context, "vkGetPhysicalDeviceFormatProperties2");
	vilc_vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)load(context, "vkGetPhysicalDeviceImageFormatProperties2");
	vilc_vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)load(context, "vkGetPhysicalDeviceMemoryProperties2");
	vilc_vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)load(context, "vkGetPhysicalDeviceProperties2");
	vilc_vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)load(context, "vkGetPhysicalDeviceQueueFamilyProperties2");
	vilc_vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties2");
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_3)
	vilc_vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties)load(context, "vkGetPhysicalDeviceToolProperties");
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_ARM_data_graph)
	vilc_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM = (PFN_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM)load(context, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM");
	vilc_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM = (PFN_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM)load(context, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM");
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_performance_counters_by_region)
	vilc_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM)load(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM");
#endif /* defined(VK_ARM_performance_counters_by_region) */
#if defined(VK_ARM_tensors)
	vilc_vkGetPhysicalDeviceExternalTensorPropertiesARM = (PFN_vkGetPhysicalDeviceExternalTensorPropertiesARM)load(context, "vkGetPhysicalDeviceExternalTensorPropertiesARM");
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_EXT_acquire_drm_display)
	vilc_vkAcquireDrmDisplayEXT = (PFN_vkAcquireDrmDisplayEXT)load(context, "vkAcquireDrmDisplayEXT");
	vilc_vkGetDrmDisplayEXT = (PFN_vkGetDrmDisplayEXT)load(context, "vkGetDrmDisplayEXT");
#endif /* defined(VK_EXT_acquire_drm_display) */
#if defined(VK_EXT_acquire_xlib_display)
	vilc_vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)load(context, "vkAcquireXlibDisplayEXT");
	vilc_vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)load(context, "vkGetRandROutputDisplayEXT");
#endif /* defined(VK_EXT_acquire_xlib_display) */
#if defined(VK_EXT_calibrated_timestamps)
	vilc_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)load(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_debug_report)
	vilc_vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)load(context, "vkCreateDebugReportCallbackEXT");
	vilc_vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)load(context, "vkDebugReportMessageEXT");
	vilc_vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)load(context, "vkDestroyDebugReportCallbackEXT");
#endif /* defined(VK_EXT_debug_report) */
#if defined(VK_EXT_debug_utils)
	vilc_vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)load(context, "vkCmdBeginDebugUtilsLabelEXT");
	vilc_vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)load(context, "vkCmdEndDebugUtilsLabelEXT");
	vilc_vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)load(context, "vkCmdInsertDebugUtilsLabelEXT");
	vilc_vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)load(context, "vkCreateDebugUtilsMessengerEXT");
	vilc_vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)load(context, "vkDestroyDebugUtilsMessengerEXT");
	vilc_vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)load(context, "vkQueueBeginDebugUtilsLabelEXT");
	vilc_vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)load(context, "vkQueueEndDebugUtilsLabelEXT");
	vilc_vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)load(context, "vkQueueInsertDebugUtilsLabelEXT");
	vilc_vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)load(context, "vkSetDebugUtilsObjectNameEXT");
	vilc_vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)load(context, "vkSetDebugUtilsObjectTagEXT");
	vilc_vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)load(context, "vkSubmitDebugUtilsMessageEXT");
#endif /* defined(VK_EXT_debug_utils) */
#if defined(VK_EXT_direct_mode_display)
	vilc_vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)load(context, "vkReleaseDisplayEXT");
#endif /* defined(VK_EXT_direct_mode_display) */
#if defined(VK_EXT_directfb_surface)
	vilc_vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT)load(context, "vkCreateDirectFBSurfaceEXT");
	vilc_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)load(context, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif /* defined(VK_EXT_directfb_surface) */
#if defined(VK_EXT_display_surface_counter)
	vilc_vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)load(context, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif /* defined(VK_EXT_display_surface_counter) */
#if defined(VK_EXT_full_screen_exclusive)
	vilc_vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)load(context, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_headless_surface)
	vilc_vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)load(context, "vkCreateHeadlessSurfaceEXT");
#endif /* defined(VK_EXT_headless_surface) */
#if defined(VK_EXT_metal_surface)
	vilc_vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)load(context, "vkCreateMetalSurfaceEXT");
#endif /* defined(VK_EXT_metal_surface) */
#if defined(VK_EXT_sample_locations)
	vilc_vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)load(context, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_tooling_info)
	vilc_vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)load(context, "vkGetPhysicalDeviceToolPropertiesEXT");
#endif /* defined(VK_EXT_tooling_info) */
#if defined(VK_FUCHSIA_imagepipe_surface)
	vilc_vkCreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA)load(context, "vkCreateImagePipeSurfaceFUCHSIA");
#endif /* defined(VK_FUCHSIA_imagepipe_surface) */
#if defined(VK_GGP_stream_descriptor_surface)
	vilc_vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)load(context, "vkCreateStreamDescriptorSurfaceGGP");
#endif /* defined(VK_GGP_stream_descriptor_surface) */
#if defined(VK_KHR_android_surface)
	vilc_vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)load(context, "vkCreateAndroidSurfaceKHR");
#endif /* defined(VK_KHR_android_surface) */
#if defined(VK_KHR_calibrated_timestamps)
	vilc_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR)load(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_cooperative_matrix)
	vilc_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR)load(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
#endif /* defined(VK_KHR_cooperative_matrix) */
#if defined(VK_KHR_device_group_creation)
	vilc_vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)load(context, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif /* defined(VK_KHR_device_group_creation) */
#if defined(VK_KHR_display)
	vilc_vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)load(context, "vkCreateDisplayModeKHR");
	vilc_vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)load(context, "vkCreateDisplayPlaneSurfaceKHR");
	vilc_vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)load(context, "vkGetDisplayModePropertiesKHR");
	vilc_vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)load(context, "vkGetDisplayPlaneCapabilitiesKHR");
	vilc_vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)load(context, "vkGetDisplayPlaneSupportedDisplaysKHR");
	vilc_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)load(context, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
	vilc_vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)load(context, "vkGetPhysicalDeviceDisplayPropertiesKHR");
#endif /* defined(VK_KHR_display) */
#if defined(VK_KHR_external_fence_capabilities)
	vilc_vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)load(context, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif /* defined(VK_KHR_external_fence_capabilities) */
#if defined(VK_KHR_external_memory_capabilities)
	vilc_vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)load(context, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif /* defined(VK_KHR_external_memory_capabilities) */
#if defined(VK_KHR_external_semaphore_capabilities)
	vilc_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)load(context, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif /* defined(VK_KHR_external_semaphore_capabilities) */
#if defined(VK_KHR_fragment_shading_rate)
	vilc_vkGetPhysicalDeviceFragmentShadingRatesKHR = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR)load(context, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_display_properties2)
	vilc_vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)load(context, "vkGetDisplayModeProperties2KHR");
	vilc_vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)load(context, "vkGetDisplayPlaneCapabilities2KHR");
	vilc_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)load(context, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
	vilc_vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)load(context, "vkGetPhysicalDeviceDisplayProperties2KHR");
#endif /* defined(VK_KHR_get_display_properties2) */
#if defined(VK_KHR_get_physical_device_properties2)
	vilc_vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)load(context, "vkGetPhysicalDeviceFeatures2KHR");
	vilc_vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)load(context, "vkGetPhysicalDeviceFormatProperties2KHR");
	vilc_vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)load(context, "vkGetPhysicalDeviceImageFormatProperties2KHR");
	vilc_vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)load(context, "vkGetPhysicalDeviceMemoryProperties2KHR");
	vilc_vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)load(context, "vkGetPhysicalDeviceProperties2KHR");
	vilc_vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)load(context, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
	vilc_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif /* defined(VK_KHR_get_physical_device_properties2) */
#if defined(VK_KHR_get_surface_capabilities2)
	vilc_vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)load(context, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
	vilc_vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)load(context, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif /* defined(VK_KHR_get_surface_capabilities2) */
#if defined(VK_KHR_performance_query)
	vilc_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)load(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
	vilc_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)load(context, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_surface)
	vilc_vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)load(context, "vkDestroySurfaceKHR");
	vilc_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)load(context, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
	vilc_vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)load(context, "vkGetPhysicalDeviceSurfaceFormatsKHR");
	vilc_vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)load(context, "vkGetPhysicalDeviceSurfacePresentModesKHR");
	vilc_vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)load(context, "vkGetPhysicalDeviceSurfaceSupportKHR");
#endif /* defined(VK_KHR_surface) */
#if defined(VK_KHR_video_encode_queue)
	vilc_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR)load(context, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
	vilc_vkGetPhysicalDeviceVideoCapabilitiesKHR = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR)load(context, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
	vilc_vkGetPhysicalDeviceVideoFormatPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR)load(context, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_KHR_wayland_surface)
	vilc_vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)load(context, "vkCreateWaylandSurfaceKHR");
	vilc_vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)load(context, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif /* defined(VK_KHR_wayland_surface) */
#if defined(VK_KHR_win32_surface)
	vilc_vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)load(context, "vkCreateWin32SurfaceKHR");
	vilc_vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)load(context, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif /* defined(VK_KHR_win32_surface) */
#if defined(VK_KHR_xcb_surface)
	vilc_vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)load(context, "vkCreateXcbSurfaceKHR");
	vilc_vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)load(context, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif /* defined(VK_KHR_xcb_surface) */
#if defined(VK_KHR_xlib_surface)
	vilc_vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)load(context, "vkCreateXlibSurfaceKHR");
	vilc_vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)load(context, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif /* defined(VK_KHR_xlib_surface) */
#if defined(VK_MVK_ios_surface)
	vilc_vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)load(context, "vkCreateIOSSurfaceMVK");
#endif /* defined(VK_MVK_ios_surface) */
#if defined(VK_MVK_macos_surface)
	vilc_vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)load(context, "vkCreateMacOSSurfaceMVK");
#endif /* defined(VK_MVK_macos_surface) */
#if defined(VK_NN_vi_surface)
	vilc_vkCreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)load(context, "vkCreateViSurfaceNN");
#endif /* defined(VK_NN_vi_surface) */
#if defined(VK_NV_acquire_winrt_display)
	vilc_vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)load(context, "vkAcquireWinrtDisplayNV");
	vilc_vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)load(context, "vkGetWinrtDisplayNV");
#endif /* defined(VK_NV_acquire_winrt_display) */
#if defined(VK_NV_cooperative_matrix)
	vilc_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif /* defined(VK_NV_cooperative_matrix) */
#if defined(VK_NV_cooperative_matrix2)
	vilc_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV");
#endif /* defined(VK_NV_cooperative_matrix2) */
#if defined(VK_NV_cooperative_vector)
	vilc_vkGetPhysicalDeviceCooperativeVectorPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV");
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_coverage_reduction_mode)
	vilc_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)load(context, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif /* defined(VK_NV_coverage_reduction_mode) */
#if defined(VK_NV_external_memory_capabilities)
	vilc_vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)load(context, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif /* defined(VK_NV_external_memory_capabilities) */
#if defined(VK_NV_optical_flow)
	vilc_vkGetPhysicalDeviceOpticalFlowImageFormatsNV = (PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV)load(context, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_OHOS_surface)
	vilc_vkCreateSurfaceOHOS = (PFN_vkCreateSurfaceOHOS)load(context, "vkCreateSurfaceOHOS");
#endif /* defined(VK_OHOS_surface) */
#if defined(VK_QNX_screen_surface)
	vilc_vkCreateScreenSurfaceQNX = (PFN_vkCreateScreenSurfaceQNX)load(context, "vkCreateScreenSurfaceQNX");
	vilc_vkGetPhysicalDeviceScreenPresentationSupportQNX = (PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)load(context, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
#endif /* defined(VK_QNX_screen_surface) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	vilc_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)load(context, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_LOAD_INSTANCE_VILC */
#else /* VOLK_IN_LOADERS_CLOTH */
	/* VOLK_GENERATE_LOAD_INSTANCE */
#if defined(VK_VERSION_1_0)
	vkCreateDevice = (PFN_vkCreateDevice)load(context, "vkCreateDevice");
	vkDestroyInstance = (PFN_vkDestroyInstance)load(context, "vkDestroyInstance");
	vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)load(context, "vkEnumerateDeviceExtensionProperties");
	vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)load(context, "vkEnumerateDeviceLayerProperties");
	vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)load(context, "vkEnumeratePhysicalDevices");
	vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)load(context, "vkGetDeviceProcAddr");
	vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)load(context, "vkGetPhysicalDeviceFeatures");
	vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)load(context, "vkGetPhysicalDeviceFormatProperties");
	vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)load(context, "vkGetPhysicalDeviceImageFormatProperties");
	vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)load(context, "vkGetPhysicalDeviceMemoryProperties");
	vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)load(context, "vkGetPhysicalDeviceProperties");
	vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)load(context, "vkGetPhysicalDeviceQueueFamilyProperties");
	vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)load(context, "vkEnumeratePhysicalDeviceGroups");
	vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)load(context, "vkGetPhysicalDeviceExternalBufferProperties");
	vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)load(context, "vkGetPhysicalDeviceExternalFenceProperties");
	vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)load(context, "vkGetPhysicalDeviceExternalSemaphoreProperties");
	vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)load(context, "vkGetPhysicalDeviceFeatures2");
	vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)load(context, "vkGetPhysicalDeviceFormatProperties2");
	vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)load(context, "vkGetPhysicalDeviceImageFormatProperties2");
	vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)load(context, "vkGetPhysicalDeviceMemoryProperties2");
	vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)load(context, "vkGetPhysicalDeviceProperties2");
	vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)load(context, "vkGetPhysicalDeviceQueueFamilyProperties2");
	vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties2");
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_3)
	vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties)load(context, "vkGetPhysicalDeviceToolProperties");
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_ARM_data_graph)
	vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM = (PFN_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM)load(context, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM");
	vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM = (PFN_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM)load(context, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM");
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_performance_counters_by_region)
	vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM)load(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM");
#endif /* defined(VK_ARM_performance_counters_by_region) */
#if defined(VK_ARM_tensors)
	vkGetPhysicalDeviceExternalTensorPropertiesARM = (PFN_vkGetPhysicalDeviceExternalTensorPropertiesARM)load(context, "vkGetPhysicalDeviceExternalTensorPropertiesARM");
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_EXT_acquire_drm_display)
	vkAcquireDrmDisplayEXT = (PFN_vkAcquireDrmDisplayEXT)load(context, "vkAcquireDrmDisplayEXT");
	vkGetDrmDisplayEXT = (PFN_vkGetDrmDisplayEXT)load(context, "vkGetDrmDisplayEXT");
#endif /* defined(VK_EXT_acquire_drm_display) */
#if defined(VK_EXT_acquire_xlib_display)
	vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)load(context, "vkAcquireXlibDisplayEXT");
	vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)load(context, "vkGetRandROutputDisplayEXT");
#endif /* defined(VK_EXT_acquire_xlib_display) */
#if defined(VK_EXT_calibrated_timestamps)
	vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)load(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_debug_report)
	vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)load(context, "vkCreateDebugReportCallbackEXT");
	vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)load(context, "vkDebugReportMessageEXT");
	vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)load(context, "vkDestroyDebugReportCallbackEXT");
#endif /* defined(VK_EXT_debug_report) */
#if defined(VK_EXT_debug_utils)
	vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)load(context, "vkCmdBeginDebugUtilsLabelEXT");
	vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)load(context, "vkCmdEndDebugUtilsLabelEXT");
	vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)load(context, "vkCmdInsertDebugUtilsLabelEXT");
	vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)load(context, "vkCreateDebugUtilsMessengerEXT");
	vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)load(context, "vkDestroyDebugUtilsMessengerEXT");
	vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)load(context, "vkQueueBeginDebugUtilsLabelEXT");
	vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)load(context, "vkQueueEndDebugUtilsLabelEXT");
	vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)load(context, "vkQueueInsertDebugUtilsLabelEXT");
	vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)load(context, "vkSetDebugUtilsObjectNameEXT");
	vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)load(context, "vkSetDebugUtilsObjectTagEXT");
	vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)load(context, "vkSubmitDebugUtilsMessageEXT");
#endif /* defined(VK_EXT_debug_utils) */
#if defined(VK_EXT_direct_mode_display)
	vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)load(context, "vkReleaseDisplayEXT");
#endif /* defined(VK_EXT_direct_mode_display) */
#if defined(VK_EXT_directfb_surface)
	vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT)load(context, "vkCreateDirectFBSurfaceEXT");
	vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)load(context, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif /* defined(VK_EXT_directfb_surface) */
#if defined(VK_EXT_display_surface_counter)
	vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)load(context, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif /* defined(VK_EXT_display_surface_counter) */
#if defined(VK_EXT_full_screen_exclusive)
	vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)load(context, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_headless_surface)
	vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)load(context, "vkCreateHeadlessSurfaceEXT");
#endif /* defined(VK_EXT_headless_surface) */
#if defined(VK_EXT_metal_surface)
	vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)load(context, "vkCreateMetalSurfaceEXT");
#endif /* defined(VK_EXT_metal_surface) */
#if defined(VK_EXT_sample_locations)
	vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)load(context, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_tooling_info)
	vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)load(context, "vkGetPhysicalDeviceToolPropertiesEXT");
#endif /* defined(VK_EXT_tooling_info) */
#if defined(VK_FUCHSIA_imagepipe_surface)
	vkCreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA)load(context, "vkCreateImagePipeSurfaceFUCHSIA");
#endif /* defined(VK_FUCHSIA_imagepipe_surface) */
#if defined(VK_GGP_stream_descriptor_surface)
	vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)load(context, "vkCreateStreamDescriptorSurfaceGGP");
#endif /* defined(VK_GGP_stream_descriptor_surface) */
#if defined(VK_KHR_android_surface)
	vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)load(context, "vkCreateAndroidSurfaceKHR");
#endif /* defined(VK_KHR_android_surface) */
#if defined(VK_KHR_calibrated_timestamps)
	vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR)load(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_cooperative_matrix)
	vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR)load(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
#endif /* defined(VK_KHR_cooperative_matrix) */
#if defined(VK_KHR_device_group_creation)
	vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)load(context, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif /* defined(VK_KHR_device_group_creation) */
#if defined(VK_KHR_display)
	vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)load(context, "vkCreateDisplayModeKHR");
	vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)load(context, "vkCreateDisplayPlaneSurfaceKHR");
	vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)load(context, "vkGetDisplayModePropertiesKHR");
	vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)load(context, "vkGetDisplayPlaneCapabilitiesKHR");
	vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)load(context, "vkGetDisplayPlaneSupportedDisplaysKHR");
	vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)load(context, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
	vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)load(context, "vkGetPhysicalDeviceDisplayPropertiesKHR");
#endif /* defined(VK_KHR_display) */
#if defined(VK_KHR_external_fence_capabilities)
	vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)load(context, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif /* defined(VK_KHR_external_fence_capabilities) */
#if defined(VK_KHR_external_memory_capabilities)
	vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)load(context, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif /* defined(VK_KHR_external_memory_capabilities) */
#if defined(VK_KHR_external_semaphore_capabilities)
	vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)load(context, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif /* defined(VK_KHR_external_semaphore_capabilities) */
#if defined(VK_KHR_fragment_shading_rate)
	vkGetPhysicalDeviceFragmentShadingRatesKHR = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR)load(context, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_display_properties2)
	vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)load(context, "vkGetDisplayModeProperties2KHR");
	vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)load(context, "vkGetDisplayPlaneCapabilities2KHR");
	vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)load(context, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
	vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)load(context, "vkGetPhysicalDeviceDisplayProperties2KHR");
#endif /* defined(VK_KHR_get_display_properties2) */
#if defined(VK_KHR_get_physical_device_properties2)
	vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)load(context, "vkGetPhysicalDeviceFeatures2KHR");
	vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)load(context, "vkGetPhysicalDeviceFormatProperties2KHR");
	vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)load(context, "vkGetPhysicalDeviceImageFormatProperties2KHR");
	vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)load(context, "vkGetPhysicalDeviceMemoryProperties2KHR");
	vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)load(context, "vkGetPhysicalDeviceProperties2KHR");
	vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)load(context, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
	vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif /* defined(VK_KHR_get_physical_device_properties2) */
#if defined(VK_KHR_get_surface_capabilities2)
	vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)load(context, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
	vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)load(context, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif /* defined(VK_KHR_get_surface_capabilities2) */
#if defined(VK_KHR_performance_query)
	vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)load(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
	vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)load(context, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_surface)
	vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)load(context, "vkDestroySurfaceKHR");
	vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)load(context, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
	vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)load(context, "vkGetPhysicalDeviceSurfaceFormatsKHR");
	vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)load(context, "vkGetPhysicalDeviceSurfacePresentModesKHR");
	vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)load(context, "vkGetPhysicalDeviceSurfaceSupportKHR");
#endif /* defined(VK_KHR_surface) */
#if defined(VK_KHR_video_encode_queue)
	vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR)load(context, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
	vkGetPhysicalDeviceVideoCapabilitiesKHR = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR)load(context, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
	vkGetPhysicalDeviceVideoFormatPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR)load(context, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_KHR_wayland_surface)
	vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)load(context, "vkCreateWaylandSurfaceKHR");
	vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)load(context, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif /* defined(VK_KHR_wayland_surface) */
#if defined(VK_KHR_win32_surface)
	vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)load(context, "vkCreateWin32SurfaceKHR");
	vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)load(context, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif /* defined(VK_KHR_win32_surface) */
#if defined(VK_KHR_xcb_surface)
	vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)load(context, "vkCreateXcbSurfaceKHR");
	vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)load(context, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif /* defined(VK_KHR_xcb_surface) */
#if defined(VK_KHR_xlib_surface)
	vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)load(context, "vkCreateXlibSurfaceKHR");
	vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)load(context, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif /* defined(VK_KHR_xlib_surface) */
#if defined(VK_MVK_ios_surface)
	vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)load(context, "vkCreateIOSSurfaceMVK");
#endif /* defined(VK_MVK_ios_surface) */
#if defined(VK_MVK_macos_surface)
	vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)load(context, "vkCreateMacOSSurfaceMVK");
#endif /* defined(VK_MVK_macos_surface) */
#if defined(VK_NN_vi_surface)
	vkCreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)load(context, "vkCreateViSurfaceNN");
#endif /* defined(VK_NN_vi_surface) */
#if defined(VK_NV_acquire_winrt_display)
	vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)load(context, "vkAcquireWinrtDisplayNV");
	vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)load(context, "vkGetWinrtDisplayNV");
#endif /* defined(VK_NV_acquire_winrt_display) */
#if defined(VK_NV_cooperative_matrix)
	vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif /* defined(VK_NV_cooperative_matrix) */
#if defined(VK_NV_cooperative_matrix2)
	vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV");
#endif /* defined(VK_NV_cooperative_matrix2) */
#if defined(VK_NV_cooperative_vector)
	vkGetPhysicalDeviceCooperativeVectorPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV");
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_coverage_reduction_mode)
	vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)load(context, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif /* defined(VK_NV_coverage_reduction_mode) */
#if defined(VK_NV_external_memory_capabilities)
	vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)load(context, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif /* defined(VK_NV_external_memory_capabilities) */
#if defined(VK_NV_optical_flow)
	vkGetPhysicalDeviceOpticalFlowImageFormatsNV = (PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV)load(context, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_OHOS_surface)
	vkCreateSurfaceOHOS = (PFN_vkCreateSurfaceOHOS)load(context, "vkCreateSurfaceOHOS");
#endif /* defined(VK_OHOS_surface) */
#if defined(VK_QNX_screen_surface)
	vkCreateScreenSurfaceQNX = (PFN_vkCreateScreenSurfaceQNX)load(context, "vkCreateScreenSurfaceQNX");
	vkGetPhysicalDeviceScreenPresentationSupportQNX = (PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)load(context, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
#endif /* defined(VK_QNX_screen_surface) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)load(context, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_LOAD_INSTANCE */
#endif /* VOLK_IN_LOADERS_CLOTH */
}

static void volkGenLoadDevice(void* context, PFN_vkVoidFunction (*load)(void*, const char*))
{
#if defined(VOLK_IN_LOADERS_CLOTH)
	/* VOLK_GENERATE_LOAD_DEVICE_VILC */
#if defined(VK_VERSION_1_0)
	vilc_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)load(context, "vkAllocateCommandBuffers");
	vilc_vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)load(context, "vkAllocateDescriptorSets");
	vilc_vkAllocateMemory = (PFN_vkAllocateMemory)load(context, "vkAllocateMemory");
	vilc_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)load(context, "vkBeginCommandBuffer");
	vilc_vkBindBufferMemory = (PFN_vkBindBufferMemory)load(context, "vkBindBufferMemory");
	vilc_vkBindImageMemory = (PFN_vkBindImageMemory)load(context, "vkBindImageMemory");
	vilc_vkCmdBeginQuery = (PFN_vkCmdBeginQuery)load(context, "vkCmdBeginQuery");
	vilc_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)load(context, "vkCmdBeginRenderPass");
	vilc_vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)load(context, "vkCmdBindDescriptorSets");
	vilc_vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)load(context, "vkCmdBindIndexBuffer");
	vilc_vkCmdBindPipeline = (PFN_vkCmdBindPipeline)load(context, "vkCmdBindPipeline");
	vilc_vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)load(context, "vkCmdBindVertexBuffers");
	vilc_vkCmdBlitImage = (PFN_vkCmdBlitImage)load(context, "vkCmdBlitImage");
	vilc_vkCmdClearAttachments = (PFN_vkCmdClearAttachments)load(context, "vkCmdClearAttachments");
	vilc_vkCmdClearColorImage = (PFN_vkCmdClearColorImage)load(context, "vkCmdClearColorImage");
	vilc_vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)load(context, "vkCmdClearDepthStencilImage");
	vilc_vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)load(context, "vkCmdCopyBuffer");
	vilc_vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)load(context, "vkCmdCopyBufferToImage");
	vilc_vkCmdCopyImage = (PFN_vkCmdCopyImage)load(context, "vkCmdCopyImage");
	vilc_vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)load(context, "vkCmdCopyImageToBuffer");
	vilc_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)load(context, "vkCmdCopyQueryPoolResults");
	vilc_vkCmdDispatch = (PFN_vkCmdDispatch)load(context, "vkCmdDispatch");
	vilc_vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)load(context, "vkCmdDispatchIndirect");
	vilc_vkCmdDraw = (PFN_vkCmdDraw)load(context, "vkCmdDraw");
	vilc_vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)load(context, "vkCmdDrawIndexed");
	vilc_vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)load(context, "vkCmdDrawIndexedIndirect");
	vilc_vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)load(context, "vkCmdDrawIndirect");
	vilc_vkCmdEndQuery = (PFN_vkCmdEndQuery)load(context, "vkCmdEndQuery");
	vilc_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)load(context, "vkCmdEndRenderPass");
	vilc_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)load(context, "vkCmdExecuteCommands");
	vilc_vkCmdFillBuffer = (PFN_vkCmdFillBuffer)load(context, "vkCmdFillBuffer");
	vilc_vkCmdNextSubpass = (PFN_vkCmdNextSubpass)load(context, "vkCmdNextSubpass");
	vilc_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)load(context, "vkCmdPipelineBarrier");
	vilc_vkCmdPushConstants = (PFN_vkCmdPushConstants)load(context, "vkCmdPushConstants");
	vilc_vkCmdResetEvent = (PFN_vkCmdResetEvent)load(context, "vkCmdResetEvent");
	vilc_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)load(context, "vkCmdResetQueryPool");
	vilc_vkCmdResolveImage = (PFN_vkCmdResolveImage)load(context, "vkCmdResolveImage");
	vilc_vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)load(context, "vkCmdSetBlendConstants");
	vilc_vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)load(context, "vkCmdSetDepthBias");
	vilc_vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)load(context, "vkCmdSetDepthBounds");
	vilc_vkCmdSetEvent = (PFN_vkCmdSetEvent)load(context, "vkCmdSetEvent");
	vilc_vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)load(context, "vkCmdSetLineWidth");
	vilc_vkCmdSetScissor = (PFN_vkCmdSetScissor)load(context, "vkCmdSetScissor");
	vilc_vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)load(context, "vkCmdSetStencilCompareMask");
	vilc_vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)load(context, "vkCmdSetStencilReference");
	vilc_vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)load(context, "vkCmdSetStencilWriteMask");
	vilc_vkCmdSetViewport = (PFN_vkCmdSetViewport)load(context, "vkCmdSetViewport");
	vilc_vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)load(context, "vkCmdUpdateBuffer");
	vilc_vkCmdWaitEvents = (PFN_vkCmdWaitEvents)load(context, "vkCmdWaitEvents");
	vilc_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)load(context, "vkCmdWriteTimestamp");
	vilc_vkCreateBuffer = (PFN_vkCreateBuffer)load(context, "vkCreateBuffer");
	vilc_vkCreateBufferView = (PFN_vkCreateBufferView)load(context, "vkCreateBufferView");
	vilc_vkCreateCommandPool = (PFN_vkCreateCommandPool)load(context, "vkCreateCommandPool");
	vilc_vkCreateComputePipelines = (PFN_vkCreateComputePipelines)load(context, "vkCreateComputePipelines");
	vilc_vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)load(context, "vkCreateDescriptorPool");
	vilc_vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)load(context, "vkCreateDescriptorSetLayout");
	vilc_vkCreateEvent = (PFN_vkCreateEvent)load(context, "vkCreateEvent");
	vilc_vkCreateFence = (PFN_vkCreateFence)load(context, "vkCreateFence");
	vilc_vkCreateFramebuffer = (PFN_vkCreateFramebuffer)load(context, "vkCreateFramebuffer");
	vilc_vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)load(context, "vkCreateGraphicsPipelines");
	vilc_vkCreateImage = (PFN_vkCreateImage)load(context, "vkCreateImage");
	vilc_vkCreateImageView = (PFN_vkCreateImageView)load(context, "vkCreateImageView");
	vilc_vkCreatePipelineCache = (PFN_vkCreatePipelineCache)load(context, "vkCreatePipelineCache");
	vilc_vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)load(context, "vkCreatePipelineLayout");
	vilc_vkCreateQueryPool = (PFN_vkCreateQueryPool)load(context, "vkCreateQueryPool");
	vilc_vkCreateRenderPass = (PFN_vkCreateRenderPass)load(context, "vkCreateRenderPass");
	vilc_vkCreateSampler = (PFN_vkCreateSampler)load(context, "vkCreateSampler");
	vilc_vkCreateSemaphore = (PFN_vkCreateSemaphore)load(context, "vkCreateSemaphore");
	vilc_vkCreateShaderModule = (PFN_vkCreateShaderModule)load(context, "vkCreateShaderModule");
	vilc_vkDestroyBuffer = (PFN_vkDestroyBuffer)load(context, "vkDestroyBuffer");
	vilc_vkDestroyBufferView = (PFN_vkDestroyBufferView)load(context, "vkDestroyBufferView");
	vilc_vkDestroyCommandPool = (PFN_vkDestroyCommandPool)load(context, "vkDestroyCommandPool");
	vilc_vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)load(context, "vkDestroyDescriptorPool");
	vilc_vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)load(context, "vkDestroyDescriptorSetLayout");
	vilc_vkDestroyDevice = (PFN_vkDestroyDevice)load(context, "vkDestroyDevice");
	vilc_vkDestroyEvent = (PFN_vkDestroyEvent)load(context, "vkDestroyEvent");
	vilc_vkDestroyFence = (PFN_vkDestroyFence)load(context, "vkDestroyFence");
	vilc_vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)load(context, "vkDestroyFramebuffer");
	vilc_vkDestroyImage = (PFN_vkDestroyImage)load(context, "vkDestroyImage");
	vilc_vkDestroyImageView = (PFN_vkDestroyImageView)load(context, "vkDestroyImageView");
	vilc_vkDestroyPipeline = (PFN_vkDestroyPipeline)load(context, "vkDestroyPipeline");
	vilc_vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)load(context, "vkDestroyPipelineCache");
	vilc_vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)load(context, "vkDestroyPipelineLayout");
	vilc_vkDestroyQueryPool = (PFN_vkDestroyQueryPool)load(context, "vkDestroyQueryPool");
	vilc_vkDestroyRenderPass = (PFN_vkDestroyRenderPass)load(context, "vkDestroyRenderPass");
	vilc_vkDestroySampler = (PFN_vkDestroySampler)load(context, "vkDestroySampler");
	vilc_vkDestroySemaphore = (PFN_vkDestroySemaphore)load(context, "vkDestroySemaphore");
	vilc_vkDestroyShaderModule = (PFN_vkDestroyShaderModule)load(context, "vkDestroyShaderModule");
	vilc_vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)load(context, "vkDeviceWaitIdle");
	vilc_vkEndCommandBuffer = (PFN_vkEndCommandBuffer)load(context, "vkEndCommandBuffer");
	vilc_vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)load(context, "vkFlushMappedMemoryRanges");
	vilc_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)load(context, "vkFreeCommandBuffers");
	vilc_vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)load(context, "vkFreeDescriptorSets");
	vilc_vkFreeMemory = (PFN_vkFreeMemory)load(context, "vkFreeMemory");
	vilc_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)load(context, "vkGetBufferMemoryRequirements");
	vilc_vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)load(context, "vkGetDeviceMemoryCommitment");
	vilc_vkGetDeviceQueue = (PFN_vkGetDeviceQueue)load(context, "vkGetDeviceQueue");
	vilc_vkGetEventStatus = (PFN_vkGetEventStatus)load(context, "vkGetEventStatus");
	vilc_vkGetFenceStatus = (PFN_vkGetFenceStatus)load(context, "vkGetFenceStatus");
	vilc_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)load(context, "vkGetImageMemoryRequirements");
	vilc_vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)load(context, "vkGetImageSparseMemoryRequirements");
	vilc_vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)load(context, "vkGetImageSubresourceLayout");
	vilc_vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)load(context, "vkGetPipelineCacheData");
	vilc_vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)load(context, "vkGetQueryPoolResults");
	vilc_vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)load(context, "vkGetRenderAreaGranularity");
	vilc_vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)load(context, "vkInvalidateMappedMemoryRanges");
	vilc_vkMapMemory = (PFN_vkMapMemory)load(context, "vkMapMemory");
	vilc_vkMergePipelineCaches = (PFN_vkMergePipelineCaches)load(context, "vkMergePipelineCaches");
	vilc_vkQueueBindSparse = (PFN_vkQueueBindSparse)load(context, "vkQueueBindSparse");
	vilc_vkQueueSubmit = (PFN_vkQueueSubmit)load(context, "vkQueueSubmit");
	vilc_vkQueueWaitIdle = (PFN_vkQueueWaitIdle)load(context, "vkQueueWaitIdle");
	vilc_vkResetCommandBuffer = (PFN_vkResetCommandBuffer)load(context, "vkResetCommandBuffer");
	vilc_vkResetCommandPool = (PFN_vkResetCommandPool)load(context, "vkResetCommandPool");
	vilc_vkResetDescriptorPool = (PFN_vkResetDescriptorPool)load(context, "vkResetDescriptorPool");
	vilc_vkResetEvent = (PFN_vkResetEvent)load(context, "vkResetEvent");
	vilc_vkResetFences = (PFN_vkResetFences)load(context, "vkResetFences");
	vilc_vkSetEvent = (PFN_vkSetEvent)load(context, "vkSetEvent");
	vilc_vkUnmapMemory = (PFN_vkUnmapMemory)load(context, "vkUnmapMemory");
	vilc_vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)load(context, "vkUpdateDescriptorSets");
	vilc_vkWaitForFences = (PFN_vkWaitForFences)load(context, "vkWaitForFences");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	vilc_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)load(context, "vkBindBufferMemory2");
	vilc_vkBindImageMemory2 = (PFN_vkBindImageMemory2)load(context, "vkBindImageMemory2");
	vilc_vkCmdDispatchBase = (PFN_vkCmdDispatchBase)load(context, "vkCmdDispatchBase");
	vilc_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)load(context, "vkCmdSetDeviceMask");
	vilc_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)load(context, "vkCreateDescriptorUpdateTemplate");
	vilc_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)load(context, "vkCreateSamplerYcbcrConversion");
	vilc_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)load(context, "vkDestroyDescriptorUpdateTemplate");
	vilc_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)load(context, "vkDestroySamplerYcbcrConversion");
	vilc_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)load(context, "vkGetBufferMemoryRequirements2");
	vilc_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)load(context, "vkGetDescriptorSetLayoutSupport");
	vilc_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)load(context, "vkGetDeviceGroupPeerMemoryFeatures");
	vilc_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)load(context, "vkGetDeviceQueue2");
	vilc_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)load(context, "vkGetImageMemoryRequirements2");
	vilc_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)load(context, "vkGetImageSparseMemoryRequirements2");
	vilc_vkTrimCommandPool = (PFN_vkTrimCommandPool)load(context, "vkTrimCommandPool");
	vilc_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)load(context, "vkUpdateDescriptorSetWithTemplate");
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_2)
	vilc_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)load(context, "vkCmdBeginRenderPass2");
	vilc_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)load(context, "vkCmdDrawIndexedIndirectCount");
	vilc_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)load(context, "vkCmdDrawIndirectCount");
	vilc_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)load(context, "vkCmdEndRenderPass2");
	vilc_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)load(context, "vkCmdNextSubpass2");
	vilc_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)load(context, "vkCreateRenderPass2");
	vilc_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)load(context, "vkGetBufferDeviceAddress");
	vilc_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)load(context, "vkGetBufferOpaqueCaptureAddress");
	vilc_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)load(context, "vkGetDeviceMemoryOpaqueCaptureAddress");
	vilc_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)load(context, "vkGetSemaphoreCounterValue");
	vilc_vkResetQueryPool = (PFN_vkResetQueryPool)load(context, "vkResetQueryPool");
	vilc_vkSignalSemaphore = (PFN_vkSignalSemaphore)load(context, "vkSignalSemaphore");
	vilc_vkWaitSemaphores = (PFN_vkWaitSemaphores)load(context, "vkWaitSemaphores");
#endif /* defined(VK_VERSION_1_2) */
#if defined(VK_VERSION_1_3)
	vilc_vkCmdBeginRendering = (PFN_vkCmdBeginRendering)load(context, "vkCmdBeginRendering");
	vilc_vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)load(context, "vkCmdBindVertexBuffers2");
	vilc_vkCmdBlitImage2 = (PFN_vkCmdBlitImage2)load(context, "vkCmdBlitImage2");
	vilc_vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)load(context, "vkCmdCopyBuffer2");
	vilc_vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)load(context, "vkCmdCopyBufferToImage2");
	vilc_vkCmdCopyImage2 = (PFN_vkCmdCopyImage2)load(context, "vkCmdCopyImage2");
	vilc_vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)load(context, "vkCmdCopyImageToBuffer2");
	vilc_vkCmdEndRendering = (PFN_vkCmdEndRendering)load(context, "vkCmdEndRendering");
	vilc_vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)load(context, "vkCmdPipelineBarrier2");
	vilc_vkCmdResetEvent2 = (PFN_vkCmdResetEvent2)load(context, "vkCmdResetEvent2");
	vilc_vkCmdResolveImage2 = (PFN_vkCmdResolveImage2)load(context, "vkCmdResolveImage2");
	vilc_vkCmdSetCullMode = (PFN_vkCmdSetCullMode)load(context, "vkCmdSetCullMode");
	vilc_vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)load(context, "vkCmdSetDepthBiasEnable");
	vilc_vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)load(context, "vkCmdSetDepthBoundsTestEnable");
	vilc_vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)load(context, "vkCmdSetDepthCompareOp");
	vilc_vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)load(context, "vkCmdSetDepthTestEnable");
	vilc_vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)load(context, "vkCmdSetDepthWriteEnable");
	vilc_vkCmdSetEvent2 = (PFN_vkCmdSetEvent2)load(context, "vkCmdSetEvent2");
	vilc_vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace)load(context, "vkCmdSetFrontFace");
	vilc_vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)load(context, "vkCmdSetPrimitiveRestartEnable");
	vilc_vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)load(context, "vkCmdSetPrimitiveTopology");
	vilc_vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable)load(context, "vkCmdSetRasterizerDiscardEnable");
	vilc_vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)load(context, "vkCmdSetScissorWithCount");
	vilc_vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp)load(context, "vkCmdSetStencilOp");
	vilc_vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)load(context, "vkCmdSetStencilTestEnable");
	vilc_vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)load(context, "vkCmdSetViewportWithCount");
	vilc_vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2)load(context, "vkCmdWaitEvents2");
	vilc_vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)load(context, "vkCmdWriteTimestamp2");
	vilc_vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)load(context, "vkCreatePrivateDataSlot");
	vilc_vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)load(context, "vkDestroyPrivateDataSlot");
	vilc_vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements)load(context, "vkGetDeviceBufferMemoryRequirements");
	vilc_vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements)load(context, "vkGetDeviceImageMemoryRequirements");
	vilc_vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)load(context, "vkGetDeviceImageSparseMemoryRequirements");
	vilc_vkGetPrivateData = (PFN_vkGetPrivateData)load(context, "vkGetPrivateData");
	vilc_vkQueueSubmit2 = (PFN_vkQueueSubmit2)load(context, "vkQueueSubmit2");
	vilc_vkSetPrivateData = (PFN_vkSetPrivateData)load(context, "vkSetPrivateData");
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_VERSION_1_4)
	vilc_vkCmdBindDescriptorSets2 = (PFN_vkCmdBindDescriptorSets2)load(context, "vkCmdBindDescriptorSets2");
	vilc_vkCmdBindIndexBuffer2 = (PFN_vkCmdBindIndexBuffer2)load(context, "vkCmdBindIndexBuffer2");
	vilc_vkCmdPushConstants2 = (PFN_vkCmdPushConstants2)load(context, "vkCmdPushConstants2");
	vilc_vkCmdPushDescriptorSet = (PFN_vkCmdPushDescriptorSet)load(context, "vkCmdPushDescriptorSet");
	vilc_vkCmdPushDescriptorSet2 = (PFN_vkCmdPushDescriptorSet2)load(context, "vkCmdPushDescriptorSet2");
	vilc_vkCmdPushDescriptorSetWithTemplate = (PFN_vkCmdPushDescriptorSetWithTemplate)load(context, "vkCmdPushDescriptorSetWithTemplate");
	vilc_vkCmdPushDescriptorSetWithTemplate2 = (PFN_vkCmdPushDescriptorSetWithTemplate2)load(context, "vkCmdPushDescriptorSetWithTemplate2");
	vilc_vkCmdSetLineStipple = (PFN_vkCmdSetLineStipple)load(context, "vkCmdSetLineStipple");
	vilc_vkCmdSetRenderingAttachmentLocations = (PFN_vkCmdSetRenderingAttachmentLocations)load(context, "vkCmdSetRenderingAttachmentLocations");
	vilc_vkCmdSetRenderingInputAttachmentIndices = (PFN_vkCmdSetRenderingInputAttachmentIndices)load(context, "vkCmdSetRenderingInputAttachmentIndices");
	vilc_vkCopyImageToImage = (PFN_vkCopyImageToImage)load(context, "vkCopyImageToImage");
	vilc_vkCopyImageToMemory = (PFN_vkCopyImageToMemory)load(context, "vkCopyImageToMemory");
	vilc_vkCopyMemoryToImage = (PFN_vkCopyMemoryToImage)load(context, "vkCopyMemoryToImage");
	vilc_vkGetDeviceImageSubresourceLayout = (PFN_vkGetDeviceImageSubresourceLayout)load(context, "vkGetDeviceImageSubresourceLayout");
	vilc_vkGetImageSubresourceLayout2 = (PFN_vkGetImageSubresourceLayout2)load(context, "vkGetImageSubresourceLayout2");
	vilc_vkGetRenderingAreaGranularity = (PFN_vkGetRenderingAreaGranularity)load(context, "vkGetRenderingAreaGranularity");
	vilc_vkMapMemory2 = (PFN_vkMapMemory2)load(context, "vkMapMemory2");
	vilc_vkTransitionImageLayout = (PFN_vkTransitionImageLayout)load(context, "vkTransitionImageLayout");
	vilc_vkUnmapMemory2 = (PFN_vkUnmapMemory2)load(context, "vkUnmapMemory2");
#endif /* defined(VK_VERSION_1_4) */
#if defined(VK_AMDX_shader_enqueue)
	vilc_vkCmdDispatchGraphAMDX = (PFN_vkCmdDispatchGraphAMDX)load(context, "vkCmdDispatchGraphAMDX");
	vilc_vkCmdDispatchGraphIndirectAMDX = (PFN_vkCmdDispatchGraphIndirectAMDX)load(context, "vkCmdDispatchGraphIndirectAMDX");
	vilc_vkCmdDispatchGraphIndirectCountAMDX = (PFN_vkCmdDispatchGraphIndirectCountAMDX)load(context, "vkCmdDispatchGraphIndirectCountAMDX");
	vilc_vkCmdInitializeGraphScratchMemoryAMDX = (PFN_vkCmdInitializeGraphScratchMemoryAMDX)load(context, "vkCmdInitializeGraphScratchMemoryAMDX");
	vilc_vkCreateExecutionGraphPipelinesAMDX = (PFN_vkCreateExecutionGraphPipelinesAMDX)load(context, "vkCreateExecutionGraphPipelinesAMDX");
	vilc_vkGetExecutionGraphPipelineNodeIndexAMDX = (PFN_vkGetExecutionGraphPipelineNodeIndexAMDX)load(context, "vkGetExecutionGraphPipelineNodeIndexAMDX");
	vilc_vkGetExecutionGraphPipelineScratchSizeAMDX = (PFN_vkGetExecutionGraphPipelineScratchSizeAMDX)load(context, "vkGetExecutionGraphPipelineScratchSizeAMDX");
#endif /* defined(VK_AMDX_shader_enqueue) */
#if defined(VK_AMD_anti_lag)
	vilc_vkAntiLagUpdateAMD = (PFN_vkAntiLagUpdateAMD)load(context, "vkAntiLagUpdateAMD");
#endif /* defined(VK_AMD_anti_lag) */
#if defined(VK_AMD_buffer_marker)
	vilc_vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)load(context, "vkCmdWriteBufferMarkerAMD");
#endif /* defined(VK_AMD_buffer_marker) */
#if defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
	vilc_vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)load(context, "vkCmdWriteBufferMarker2AMD");
#endif /* defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_AMD_display_native_hdr)
	vilc_vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)load(context, "vkSetLocalDimmingAMD");
#endif /* defined(VK_AMD_display_native_hdr) */
#if defined(VK_AMD_draw_indirect_count)
	vilc_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)load(context, "vkCmdDrawIndexedIndirectCountAMD");
	vilc_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)load(context, "vkCmdDrawIndirectCountAMD");
#endif /* defined(VK_AMD_draw_indirect_count) */
#if defined(VK_AMD_shader_info)
	vilc_vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)load(context, "vkGetShaderInfoAMD");
#endif /* defined(VK_AMD_shader_info) */
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
	vilc_vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)load(context, "vkGetAndroidHardwareBufferPropertiesANDROID");
	vilc_vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)load(context, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
#if defined(VK_ARM_data_graph)
	vilc_vkBindDataGraphPipelineSessionMemoryARM = (PFN_vkBindDataGraphPipelineSessionMemoryARM)load(context, "vkBindDataGraphPipelineSessionMemoryARM");
	vilc_vkCmdDispatchDataGraphARM = (PFN_vkCmdDispatchDataGraphARM)load(context, "vkCmdDispatchDataGraphARM");
	vilc_vkCreateDataGraphPipelineSessionARM = (PFN_vkCreateDataGraphPipelineSessionARM)load(context, "vkCreateDataGraphPipelineSessionARM");
	vilc_vkCreateDataGraphPipelinesARM = (PFN_vkCreateDataGraphPipelinesARM)load(context, "vkCreateDataGraphPipelinesARM");
	vilc_vkDestroyDataGraphPipelineSessionARM = (PFN_vkDestroyDataGraphPipelineSessionARM)load(context, "vkDestroyDataGraphPipelineSessionARM");
	vilc_vkGetDataGraphPipelineAvailablePropertiesARM = (PFN_vkGetDataGraphPipelineAvailablePropertiesARM)load(context, "vkGetDataGraphPipelineAvailablePropertiesARM");
	vilc_vkGetDataGraphPipelinePropertiesARM = (PFN_vkGetDataGraphPipelinePropertiesARM)load(context, "vkGetDataGraphPipelinePropertiesARM");
	vilc_vkGetDataGraphPipelineSessionBindPointRequirementsARM = (PFN_vkGetDataGraphPipelineSessionBindPointRequirementsARM)load(context, "vkGetDataGraphPipelineSessionBindPointRequirementsARM");
	vilc_vkGetDataGraphPipelineSessionMemoryRequirementsARM = (PFN_vkGetDataGraphPipelineSessionMemoryRequirementsARM)load(context, "vkGetDataGraphPipelineSessionMemoryRequirementsARM");
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_tensors)
	vilc_vkBindTensorMemoryARM = (PFN_vkBindTensorMemoryARM)load(context, "vkBindTensorMemoryARM");
	vilc_vkCmdCopyTensorARM = (PFN_vkCmdCopyTensorARM)load(context, "vkCmdCopyTensorARM");
	vilc_vkCreateTensorARM = (PFN_vkCreateTensorARM)load(context, "vkCreateTensorARM");
	vilc_vkCreateTensorViewARM = (PFN_vkCreateTensorViewARM)load(context, "vkCreateTensorViewARM");
	vilc_vkDestroyTensorARM = (PFN_vkDestroyTensorARM)load(context, "vkDestroyTensorARM");
	vilc_vkDestroyTensorViewARM = (PFN_vkDestroyTensorViewARM)load(context, "vkDestroyTensorViewARM");
	vilc_vkGetDeviceTensorMemoryRequirementsARM = (PFN_vkGetDeviceTensorMemoryRequirementsARM)load(context, "vkGetDeviceTensorMemoryRequirementsARM");
	vilc_vkGetTensorMemoryRequirementsARM = (PFN_vkGetTensorMemoryRequirementsARM)load(context, "vkGetTensorMemoryRequirementsARM");
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer)
	vilc_vkGetTensorOpaqueCaptureDescriptorDataARM = (PFN_vkGetTensorOpaqueCaptureDescriptorDataARM)load(context, "vkGetTensorOpaqueCaptureDescriptorDataARM");
	vilc_vkGetTensorViewOpaqueCaptureDescriptorDataARM = (PFN_vkGetTensorViewOpaqueCaptureDescriptorDataARM)load(context, "vkGetTensorViewOpaqueCaptureDescriptorDataARM");
#endif /* defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
	vilc_vkCmdSetAttachmentFeedbackLoopEnableEXT = (PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT)load(context, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
#endif /* defined(VK_EXT_attachment_feedback_loop_dynamic_state) */
#if defined(VK_EXT_buffer_device_address)
	vilc_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)load(context, "vkGetBufferDeviceAddressEXT");
#endif /* defined(VK_EXT_buffer_device_address) */
#if defined(VK_EXT_calibrated_timestamps)
	vilc_vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)load(context, "vkGetCalibratedTimestampsEXT");
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_color_write_enable)
	vilc_vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)load(context, "vkCmdSetColorWriteEnableEXT");
#endif /* defined(VK_EXT_color_write_enable) */
#if defined(VK_EXT_conditional_rendering)
	vilc_vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)load(context, "vkCmdBeginConditionalRenderingEXT");
	vilc_vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)load(context, "vkCmdEndConditionalRenderingEXT");
#endif /* defined(VK_EXT_conditional_rendering) */
#if defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3))
	vilc_vkCmdBeginCustomResolveEXT = (PFN_vkCmdBeginCustomResolveEXT)load(context, "vkCmdBeginCustomResolveEXT");
#endif /* defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3)) */
#if defined(VK_EXT_debug_marker)
	vilc_vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)load(context, "vkCmdDebugMarkerBeginEXT");
	vilc_vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)load(context, "vkCmdDebugMarkerEndEXT");
	vilc_vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)load(context, "vkCmdDebugMarkerInsertEXT");
	vilc_vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)load(context, "vkDebugMarkerSetObjectNameEXT");
	vilc_vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)load(context, "vkDebugMarkerSetObjectTagEXT");
#endif /* defined(VK_EXT_debug_marker) */
#if defined(VK_EXT_depth_bias_control)
	vilc_vkCmdSetDepthBias2EXT = (PFN_vkCmdSetDepthBias2EXT)load(context, "vkCmdSetDepthBias2EXT");
#endif /* defined(VK_EXT_depth_bias_control) */
#if defined(VK_EXT_descriptor_buffer)
	vilc_vkCmdBindDescriptorBufferEmbeddedSamplersEXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT)load(context, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
	vilc_vkCmdBindDescriptorBuffersEXT = (PFN_vkCmdBindDescriptorBuffersEXT)load(context, "vkCmdBindDescriptorBuffersEXT");
	vilc_vkCmdSetDescriptorBufferOffsetsEXT = (PFN_vkCmdSetDescriptorBufferOffsetsEXT)load(context, "vkCmdSetDescriptorBufferOffsetsEXT");
	vilc_vkGetBufferOpaqueCaptureDescriptorDataEXT = (PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT)load(context, "vkGetBufferOpaqueCaptureDescriptorDataEXT");
	vilc_vkGetDescriptorEXT = (PFN_vkGetDescriptorEXT)load(context, "vkGetDescriptorEXT");
	vilc_vkGetDescriptorSetLayoutBindingOffsetEXT = (PFN_vkGetDescriptorSetLayoutBindingOffsetEXT)load(context, "vkGetDescriptorSetLayoutBindingOffsetEXT");
	vilc_vkGetDescriptorSetLayoutSizeEXT = (PFN_vkGetDescriptorSetLayoutSizeEXT)load(context, "vkGetDescriptorSetLayoutSizeEXT");
	vilc_vkGetImageOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageOpaqueCaptureDescriptorDataEXT)load(context, "vkGetImageOpaqueCaptureDescriptorDataEXT");
	vilc_vkGetImageViewOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT)load(context, "vkGetImageViewOpaqueCaptureDescriptorDataEXT");
	vilc_vkGetSamplerOpaqueCaptureDescriptorDataEXT = (PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT)load(context, "vkGetSamplerOpaqueCaptureDescriptorDataEXT");
#endif /* defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing))
	vilc_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = (PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT)load(context, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT");
#endif /* defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing)) */
#if defined(VK_EXT_device_fault)
	vilc_vkGetDeviceFaultInfoEXT = (PFN_vkGetDeviceFaultInfoEXT)load(context, "vkGetDeviceFaultInfoEXT");
#endif /* defined(VK_EXT_device_fault) */
#if defined(VK_EXT_device_generated_commands)
	vilc_vkCmdExecuteGeneratedCommandsEXT = (PFN_vkCmdExecuteGeneratedCommandsEXT)load(context, "vkCmdExecuteGeneratedCommandsEXT");
	vilc_vkCmdPreprocessGeneratedCommandsEXT = (PFN_vkCmdPreprocessGeneratedCommandsEXT)load(context, "vkCmdPreprocessGeneratedCommandsEXT");
	vilc_vkCreateIndirectCommandsLayoutEXT = (PFN_vkCreateIndirectCommandsLayoutEXT)load(context, "vkCreateIndirectCommandsLayoutEXT");
	vilc_vkCreateIndirectExecutionSetEXT = (PFN_vkCreateIndirectExecutionSetEXT)load(context, "vkCreateIndirectExecutionSetEXT");
	vilc_vkDestroyIndirectCommandsLayoutEXT = (PFN_vkDestroyIndirectCommandsLayoutEXT)load(context, "vkDestroyIndirectCommandsLayoutEXT");
	vilc_vkDestroyIndirectExecutionSetEXT = (PFN_vkDestroyIndirectExecutionSetEXT)load(context, "vkDestroyIndirectExecutionSetEXT");
	vilc_vkGetGeneratedCommandsMemoryRequirementsEXT = (PFN_vkGetGeneratedCommandsMemoryRequirementsEXT)load(context, "vkGetGeneratedCommandsMemoryRequirementsEXT");
	vilc_vkUpdateIndirectExecutionSetPipelineEXT = (PFN_vkUpdateIndirectExecutionSetPipelineEXT)load(context, "vkUpdateIndirectExecutionSetPipelineEXT");
	vilc_vkUpdateIndirectExecutionSetShaderEXT = (PFN_vkUpdateIndirectExecutionSetShaderEXT)load(context, "vkUpdateIndirectExecutionSetShaderEXT");
#endif /* defined(VK_EXT_device_generated_commands) */
#if defined(VK_EXT_discard_rectangles)
	vilc_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)load(context, "vkCmdSetDiscardRectangleEXT");
#endif /* defined(VK_EXT_discard_rectangles) */
#if defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2
	vilc_vkCmdSetDiscardRectangleEnableEXT = (PFN_vkCmdSetDiscardRectangleEnableEXT)load(context, "vkCmdSetDiscardRectangleEnableEXT");
	vilc_vkCmdSetDiscardRectangleModeEXT = (PFN_vkCmdSetDiscardRectangleModeEXT)load(context, "vkCmdSetDiscardRectangleModeEXT");
#endif /* defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2 */
#if defined(VK_EXT_display_control)
	vilc_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)load(context, "vkDisplayPowerControlEXT");
	vilc_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)load(context, "vkGetSwapchainCounterEXT");
	vilc_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)load(context, "vkRegisterDeviceEventEXT");
	vilc_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)load(context, "vkRegisterDisplayEventEXT");
#endif /* defined(VK_EXT_display_control) */
#if defined(VK_EXT_external_memory_host)
	vilc_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)load(context, "vkGetMemoryHostPointerPropertiesEXT");
#endif /* defined(VK_EXT_external_memory_host) */
#if defined(VK_EXT_external_memory_metal)
	vilc_vkGetMemoryMetalHandleEXT = (PFN_vkGetMemoryMetalHandleEXT)load(context, "vkGetMemoryMetalHandleEXT");
	vilc_vkGetMemoryMetalHandlePropertiesEXT = (PFN_vkGetMemoryMetalHandlePropertiesEXT)load(context, "vkGetMemoryMetalHandlePropertiesEXT");
#endif /* defined(VK_EXT_external_memory_metal) */
#if defined(VK_EXT_fragment_density_map_offset)
	vilc_vkCmdEndRendering2EXT = (PFN_vkCmdEndRendering2EXT)load(context, "vkCmdEndRendering2EXT");
#endif /* defined(VK_EXT_fragment_density_map_offset) */
#if defined(VK_EXT_full_screen_exclusive)
	vilc_vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)load(context, "vkAcquireFullScreenExclusiveModeEXT");
	vilc_vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)load(context, "vkReleaseFullScreenExclusiveModeEXT");
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1))
	vilc_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)load(context, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif /* defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1)) */
#if defined(VK_EXT_hdr_metadata)
	vilc_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)load(context, "vkSetHdrMetadataEXT");
#endif /* defined(VK_EXT_hdr_metadata) */
#if defined(VK_EXT_host_image_copy)
	vilc_vkCopyImageToImageEXT = (PFN_vkCopyImageToImageEXT)load(context, "vkCopyImageToImageEXT");
	vilc_vkCopyImageToMemoryEXT = (PFN_vkCopyImageToMemoryEXT)load(context, "vkCopyImageToMemoryEXT");
	vilc_vkCopyMemoryToImageEXT = (PFN_vkCopyMemoryToImageEXT)load(context, "vkCopyMemoryToImageEXT");
	vilc_vkTransitionImageLayoutEXT = (PFN_vkTransitionImageLayoutEXT)load(context, "vkTransitionImageLayoutEXT");
#endif /* defined(VK_EXT_host_image_copy) */
#if defined(VK_EXT_host_query_reset)
	vilc_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)load(context, "vkResetQueryPoolEXT");
#endif /* defined(VK_EXT_host_query_reset) */
#if defined(VK_EXT_image_drm_format_modifier)
	vilc_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)load(context, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif /* defined(VK_EXT_image_drm_format_modifier) */
#if defined(VK_EXT_line_rasterization)
	vilc_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)load(context, "vkCmdSetLineStippleEXT");
#endif /* defined(VK_EXT_line_rasterization) */
#if defined(VK_EXT_memory_decompression)
	vilc_vkCmdDecompressMemoryEXT = (PFN_vkCmdDecompressMemoryEXT)load(context, "vkCmdDecompressMemoryEXT");
	vilc_vkCmdDecompressMemoryIndirectCountEXT = (PFN_vkCmdDecompressMemoryIndirectCountEXT)load(context, "vkCmdDecompressMemoryIndirectCountEXT");
#endif /* defined(VK_EXT_memory_decompression) */
#if defined(VK_EXT_mesh_shader)
	vilc_vkCmdDrawMeshTasksEXT = (PFN_vkCmdDrawMeshTasksEXT)load(context, "vkCmdDrawMeshTasksEXT");
	vilc_vkCmdDrawMeshTasksIndirectEXT = (PFN_vkCmdDrawMeshTasksIndirectEXT)load(context, "vkCmdDrawMeshTasksIndirectEXT");
#endif /* defined(VK_EXT_mesh_shader) */
#if defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
	vilc_vkCmdDrawMeshTasksIndirectCountEXT = (PFN_vkCmdDrawMeshTasksIndirectCountEXT)load(context, "vkCmdDrawMeshTasksIndirectCountEXT");
#endif /* defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_EXT_metal_objects)
	vilc_vkExportMetalObjectsEXT = (PFN_vkExportMetalObjectsEXT)load(context, "vkExportMetalObjectsEXT");
#endif /* defined(VK_EXT_metal_objects) */
#if defined(VK_EXT_multi_draw)
	vilc_vkCmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT)load(context, "vkCmdDrawMultiEXT");
	vilc_vkCmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT)load(context, "vkCmdDrawMultiIndexedEXT");
#endif /* defined(VK_EXT_multi_draw) */
#if defined(VK_EXT_opacity_micromap)
	vilc_vkBuildMicromapsEXT = (PFN_vkBuildMicromapsEXT)load(context, "vkBuildMicromapsEXT");
	vilc_vkCmdBuildMicromapsEXT = (PFN_vkCmdBuildMicromapsEXT)load(context, "vkCmdBuildMicromapsEXT");
	vilc_vkCmdCopyMemoryToMicromapEXT = (PFN_vkCmdCopyMemoryToMicromapEXT)load(context, "vkCmdCopyMemoryToMicromapEXT");
	vilc_vkCmdCopyMicromapEXT = (PFN_vkCmdCopyMicromapEXT)load(context, "vkCmdCopyMicromapEXT");
	vilc_vkCmdCopyMicromapToMemoryEXT = (PFN_vkCmdCopyMicromapToMemoryEXT)load(context, "vkCmdCopyMicromapToMemoryEXT");
	vilc_vkCmdWriteMicromapsPropertiesEXT = (PFN_vkCmdWriteMicromapsPropertiesEXT)load(context, "vkCmdWriteMicromapsPropertiesEXT");
	vilc_vkCopyMemoryToMicromapEXT = (PFN_vkCopyMemoryToMicromapEXT)load(context, "vkCopyMemoryToMicromapEXT");
	vilc_vkCopyMicromapEXT = (PFN_vkCopyMicromapEXT)load(context, "vkCopyMicromapEXT");
	vilc_vkCopyMicromapToMemoryEXT = (PFN_vkCopyMicromapToMemoryEXT)load(context, "vkCopyMicromapToMemoryEXT");
	vilc_vkCreateMicromapEXT = (PFN_vkCreateMicromapEXT)load(context, "vkCreateMicromapEXT");
	vilc_vkDestroyMicromapEXT = (PFN_vkDestroyMicromapEXT)load(context, "vkDestroyMicromapEXT");
	vilc_vkGetDeviceMicromapCompatibilityEXT = (PFN_vkGetDeviceMicromapCompatibilityEXT)load(context, "vkGetDeviceMicromapCompatibilityEXT");
	vilc_vkGetMicromapBuildSizesEXT = (PFN_vkGetMicromapBuildSizesEXT)load(context, "vkGetMicromapBuildSizesEXT");
	vilc_vkWriteMicromapsPropertiesEXT = (PFN_vkWriteMicromapsPropertiesEXT)load(context, "vkWriteMicromapsPropertiesEXT");
#endif /* defined(VK_EXT_opacity_micromap) */
#if defined(VK_EXT_pageable_device_local_memory)
	vilc_vkSetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT)load(context, "vkSetDeviceMemoryPriorityEXT");
#endif /* defined(VK_EXT_pageable_device_local_memory) */
#if defined(VK_EXT_pipeline_properties)
	vilc_vkGetPipelinePropertiesEXT = (PFN_vkGetPipelinePropertiesEXT)load(context, "vkGetPipelinePropertiesEXT");
#endif /* defined(VK_EXT_pipeline_properties) */
#if defined(VK_EXT_present_timing)
	vilc_vkGetPastPresentationTimingEXT = (PFN_vkGetPastPresentationTimingEXT)load(context, "vkGetPastPresentationTimingEXT");
	vilc_vkGetSwapchainTimeDomainPropertiesEXT = (PFN_vkGetSwapchainTimeDomainPropertiesEXT)load(context, "vkGetSwapchainTimeDomainPropertiesEXT");
	vilc_vkGetSwapchainTimingPropertiesEXT = (PFN_vkGetSwapchainTimingPropertiesEXT)load(context, "vkGetSwapchainTimingPropertiesEXT");
	vilc_vkSetSwapchainPresentTimingQueueSizeEXT = (PFN_vkSetSwapchainPresentTimingQueueSizeEXT)load(context, "vkSetSwapchainPresentTimingQueueSizeEXT");
#endif /* defined(VK_EXT_present_timing) */
#if defined(VK_EXT_private_data)
	vilc_vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)load(context, "vkCreatePrivateDataSlotEXT");
	vilc_vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)load(context, "vkDestroyPrivateDataSlotEXT");
	vilc_vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)load(context, "vkGetPrivateDataEXT");
	vilc_vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)load(context, "vkSetPrivateDataEXT");
#endif /* defined(VK_EXT_private_data) */
#if defined(VK_EXT_sample_locations)
	vilc_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)load(context, "vkCmdSetSampleLocationsEXT");
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_shader_module_identifier)
	vilc_vkGetShaderModuleCreateInfoIdentifierEXT = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT)load(context, "vkGetShaderModuleCreateInfoIdentifierEXT");
	vilc_vkGetShaderModuleIdentifierEXT = (PFN_vkGetShaderModuleIdentifierEXT)load(context, "vkGetShaderModuleIdentifierEXT");
#endif /* defined(VK_EXT_shader_module_identifier) */
#if defined(VK_EXT_shader_object)
	vilc_vkCmdBindShadersEXT = (PFN_vkCmdBindShadersEXT)load(context, "vkCmdBindShadersEXT");
	vilc_vkCreateShadersEXT = (PFN_vkCreateShadersEXT)load(context, "vkCreateShadersEXT");
	vilc_vkDestroyShaderEXT = (PFN_vkDestroyShaderEXT)load(context, "vkDestroyShaderEXT");
	vilc_vkGetShaderBinaryDataEXT = (PFN_vkGetShaderBinaryDataEXT)load(context, "vkGetShaderBinaryDataEXT");
#endif /* defined(VK_EXT_shader_object) */
#if defined(VK_EXT_swapchain_maintenance1)
	vilc_vkReleaseSwapchainImagesEXT = (PFN_vkReleaseSwapchainImagesEXT)load(context, "vkReleaseSwapchainImagesEXT");
#endif /* defined(VK_EXT_swapchain_maintenance1) */
#if defined(VK_EXT_transform_feedback)
	vilc_vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)load(context, "vkCmdBeginQueryIndexedEXT");
	vilc_vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)load(context, "vkCmdBeginTransformFeedbackEXT");
	vilc_vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)load(context, "vkCmdBindTransformFeedbackBuffersEXT");
	vilc_vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)load(context, "vkCmdDrawIndirectByteCountEXT");
	vilc_vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)load(context, "vkCmdEndQueryIndexedEXT");
	vilc_vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)load(context, "vkCmdEndTransformFeedbackEXT");
#endif /* defined(VK_EXT_transform_feedback) */
#if defined(VK_EXT_validation_cache)
	vilc_vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)load(context, "vkCreateValidationCacheEXT");
	vilc_vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)load(context, "vkDestroyValidationCacheEXT");
	vilc_vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)load(context, "vkGetValidationCacheDataEXT");
	vilc_vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)load(context, "vkMergeValidationCachesEXT");
#endif /* defined(VK_EXT_validation_cache) */
#if defined(VK_FUCHSIA_buffer_collection)
	vilc_vkCreateBufferCollectionFUCHSIA = (PFN_vkCreateBufferCollectionFUCHSIA)load(context, "vkCreateBufferCollectionFUCHSIA");
	vilc_vkDestroyBufferCollectionFUCHSIA = (PFN_vkDestroyBufferCollectionFUCHSIA)load(context, "vkDestroyBufferCollectionFUCHSIA");
	vilc_vkGetBufferCollectionPropertiesFUCHSIA = (PFN_vkGetBufferCollectionPropertiesFUCHSIA)load(context, "vkGetBufferCollectionPropertiesFUCHSIA");
	vilc_vkSetBufferCollectionBufferConstraintsFUCHSIA = (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)load(context, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
	vilc_vkSetBufferCollectionImageConstraintsFUCHSIA = (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)load(context, "vkSetBufferCollectionImageConstraintsFUCHSIA");
#endif /* defined(VK_FUCHSIA_buffer_collection) */
#if defined(VK_FUCHSIA_external_memory)
	vilc_vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)load(context, "vkGetMemoryZirconHandleFUCHSIA");
	vilc_vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)load(context, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif /* defined(VK_FUCHSIA_external_memory) */
#if defined(VK_FUCHSIA_external_semaphore)
	vilc_vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)load(context, "vkGetSemaphoreZirconHandleFUCHSIA");
	vilc_vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)load(context, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif /* defined(VK_FUCHSIA_external_semaphore) */
#if defined(VK_GOOGLE_display_timing)
	vilc_vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)load(context, "vkGetPastPresentationTimingGOOGLE");
	vilc_vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)load(context, "vkGetRefreshCycleDurationGOOGLE");
#endif /* defined(VK_GOOGLE_display_timing) */
#if defined(VK_HUAWEI_cluster_culling_shader)
	vilc_vkCmdDrawClusterHUAWEI = (PFN_vkCmdDrawClusterHUAWEI)load(context, "vkCmdDrawClusterHUAWEI");
	vilc_vkCmdDrawClusterIndirectHUAWEI = (PFN_vkCmdDrawClusterIndirectHUAWEI)load(context, "vkCmdDrawClusterIndirectHUAWEI");
#endif /* defined(VK_HUAWEI_cluster_culling_shader) */
#if defined(VK_HUAWEI_invocation_mask)
	vilc_vkCmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI)load(context, "vkCmdBindInvocationMaskHUAWEI");
#endif /* defined(VK_HUAWEI_invocation_mask) */
#if defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2
	vilc_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = (PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI)load(context, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI");
#endif /* defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2 */
#if defined(VK_HUAWEI_subpass_shading)
	vilc_vkCmdSubpassShadingHUAWEI = (PFN_vkCmdSubpassShadingHUAWEI)load(context, "vkCmdSubpassShadingHUAWEI");
#endif /* defined(VK_HUAWEI_subpass_shading) */
#if defined(VK_INTEL_performance_query)
	vilc_vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)load(context, "vkAcquirePerformanceConfigurationINTEL");
	vilc_vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)load(context, "vkCmdSetPerformanceMarkerINTEL");
	vilc_vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)load(context, "vkCmdSetPerformanceOverrideINTEL");
	vilc_vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)load(context, "vkCmdSetPerformanceStreamMarkerINTEL");
	vilc_vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)load(context, "vkGetPerformanceParameterINTEL");
	vilc_vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)load(context, "vkInitializePerformanceApiINTEL");
	vilc_vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)load(context, "vkQueueSetPerformanceConfigurationINTEL");
	vilc_vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)load(context, "vkReleasePerformanceConfigurationINTEL");
	vilc_vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)load(context, "vkUninitializePerformanceApiINTEL");
#endif /* defined(VK_INTEL_performance_query) */
#if defined(VK_KHR_acceleration_structure)
	vilc_vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)load(context, "vkBuildAccelerationStructuresKHR");
	vilc_vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)load(context, "vkCmdBuildAccelerationStructuresIndirectKHR");
	vilc_vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)load(context, "vkCmdBuildAccelerationStructuresKHR");
	vilc_vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)load(context, "vkCmdCopyAccelerationStructureKHR");
	vilc_vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)load(context, "vkCmdCopyAccelerationStructureToMemoryKHR");
	vilc_vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)load(context, "vkCmdCopyMemoryToAccelerationStructureKHR");
	vilc_vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)load(context, "vkCmdWriteAccelerationStructuresPropertiesKHR");
	vilc_vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)load(context, "vkCopyAccelerationStructureKHR");
	vilc_vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)load(context, "vkCopyAccelerationStructureToMemoryKHR");
	vilc_vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)load(context, "vkCopyMemoryToAccelerationStructureKHR");
	vilc_vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)load(context, "vkCreateAccelerationStructureKHR");
	vilc_vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)load(context, "vkDestroyAccelerationStructureKHR");
	vilc_vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)load(context, "vkGetAccelerationStructureBuildSizesKHR");
	vilc_vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)load(context, "vkGetAccelerationStructureDeviceAddressKHR");
	vilc_vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)load(context, "vkGetDeviceAccelerationStructureCompatibilityKHR");
	vilc_vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)load(context, "vkWriteAccelerationStructuresPropertiesKHR");
#endif /* defined(VK_KHR_acceleration_structure) */
#if defined(VK_KHR_bind_memory2)
	vilc_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)load(context, "vkBindBufferMemory2KHR");
	vilc_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)load(context, "vkBindImageMemory2KHR");
#endif /* defined(VK_KHR_bind_memory2) */
#if defined(VK_KHR_buffer_device_address)
	vilc_vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)load(context, "vkGetBufferDeviceAddressKHR");
	vilc_vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)load(context, "vkGetBufferOpaqueCaptureAddressKHR");
	vilc_vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)load(context, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif /* defined(VK_KHR_buffer_device_address) */
#if defined(VK_KHR_calibrated_timestamps)
	vilc_vkGetCalibratedTimestampsKHR = (PFN_vkGetCalibratedTimestampsKHR)load(context, "vkGetCalibratedTimestampsKHR");
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_copy_commands2)
	vilc_vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)load(context, "vkCmdBlitImage2KHR");
	vilc_vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)load(context, "vkCmdCopyBuffer2KHR");
	vilc_vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)load(context, "vkCmdCopyBufferToImage2KHR");
	vilc_vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)load(context, "vkCmdCopyImage2KHR");
	vilc_vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)load(context, "vkCmdCopyImageToBuffer2KHR");
	vilc_vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)load(context, "vkCmdResolveImage2KHR");
#endif /* defined(VK_KHR_copy_commands2) */
#if defined(VK_KHR_copy_memory_indirect)
	vilc_vkCmdCopyMemoryIndirectKHR = (PFN_vkCmdCopyMemoryIndirectKHR)load(context, "vkCmdCopyMemoryIndirectKHR");
	vilc_vkCmdCopyMemoryToImageIndirectKHR = (PFN_vkCmdCopyMemoryToImageIndirectKHR)load(context, "vkCmdCopyMemoryToImageIndirectKHR");
#endif /* defined(VK_KHR_copy_memory_indirect) */
#if defined(VK_KHR_create_renderpass2)
	vilc_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)load(context, "vkCmdBeginRenderPass2KHR");
	vilc_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)load(context, "vkCmdEndRenderPass2KHR");
	vilc_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)load(context, "vkCmdNextSubpass2KHR");
	vilc_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)load(context, "vkCreateRenderPass2KHR");
#endif /* defined(VK_KHR_create_renderpass2) */
#if defined(VK_KHR_deferred_host_operations)
	vilc_vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)load(context, "vkCreateDeferredOperationKHR");
	vilc_vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)load(context, "vkDeferredOperationJoinKHR");
	vilc_vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)load(context, "vkDestroyDeferredOperationKHR");
	vilc_vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)load(context, "vkGetDeferredOperationMaxConcurrencyKHR");
	vilc_vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)load(context, "vkGetDeferredOperationResultKHR");
#endif /* defined(VK_KHR_deferred_host_operations) */
#if defined(VK_KHR_descriptor_update_template)
	vilc_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)load(context, "vkCreateDescriptorUpdateTemplateKHR");
	vilc_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)load(context, "vkDestroyDescriptorUpdateTemplateKHR");
	vilc_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)load(context, "vkUpdateDescriptorSetWithTemplateKHR");
#endif /* defined(VK_KHR_descriptor_update_template) */
#if defined(VK_KHR_device_group)
	vilc_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)load(context, "vkCmdDispatchBaseKHR");
	vilc_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)load(context, "vkCmdSetDeviceMaskKHR");
	vilc_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)load(context, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif /* defined(VK_KHR_device_group) */
#if defined(VK_KHR_display_swapchain)
	vilc_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)load(context, "vkCreateSharedSwapchainsKHR");
#endif /* defined(VK_KHR_display_swapchain) */
#if defined(VK_KHR_draw_indirect_count)
	vilc_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)load(context, "vkCmdDrawIndexedIndirectCountKHR");
	vilc_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)load(context, "vkCmdDrawIndirectCountKHR");
#endif /* defined(VK_KHR_draw_indirect_count) */
#if defined(VK_KHR_dynamic_rendering)
	vilc_vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR)load(context, "vkCmdBeginRenderingKHR");
	vilc_vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR)load(context, "vkCmdEndRenderingKHR");
#endif /* defined(VK_KHR_dynamic_rendering) */
#if defined(VK_KHR_dynamic_rendering_local_read)
	vilc_vkCmdSetRenderingAttachmentLocationsKHR = (PFN_vkCmdSetRenderingAttachmentLocationsKHR)load(context, "vkCmdSetRenderingAttachmentLocationsKHR");
	vilc_vkCmdSetRenderingInputAttachmentIndicesKHR = (PFN_vkCmdSetRenderingInputAttachmentIndicesKHR)load(context, "vkCmdSetRenderingInputAttachmentIndicesKHR");
#endif /* defined(VK_KHR_dynamic_rendering_local_read) */
#if defined(VK_KHR_external_fence_fd)
	vilc_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)load(context, "vkGetFenceFdKHR");
	vilc_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)load(context, "vkImportFenceFdKHR");
#endif /* defined(VK_KHR_external_fence_fd) */
#if defined(VK_KHR_external_fence_win32)
	vilc_vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)load(context, "vkGetFenceWin32HandleKHR");
	vilc_vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)load(context, "vkImportFenceWin32HandleKHR");
#endif /* defined(VK_KHR_external_fence_win32) */
#if defined(VK_KHR_external_memory_fd)
	vilc_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)load(context, "vkGetMemoryFdKHR");
	vilc_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)load(context, "vkGetMemoryFdPropertiesKHR");
#endif /* defined(VK_KHR_external_memory_fd) */
#if defined(VK_KHR_external_memory_win32)
	vilc_vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)load(context, "vkGetMemoryWin32HandleKHR");
	vilc_vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)load(context, "vkGetMemoryWin32HandlePropertiesKHR");
#endif /* defined(VK_KHR_external_memory_win32) */
#if defined(VK_KHR_external_semaphore_fd)
	vilc_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)load(context, "vkGetSemaphoreFdKHR");
	vilc_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)load(context, "vkImportSemaphoreFdKHR");
#endif /* defined(VK_KHR_external_semaphore_fd) */
#if defined(VK_KHR_external_semaphore_win32)
	vilc_vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)load(context, "vkGetSemaphoreWin32HandleKHR");
	vilc_vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)load(context, "vkImportSemaphoreWin32HandleKHR");
#endif /* defined(VK_KHR_external_semaphore_win32) */
#if defined(VK_KHR_fragment_shading_rate)
	vilc_vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)load(context, "vkCmdSetFragmentShadingRateKHR");
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_memory_requirements2)
	vilc_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)load(context, "vkGetBufferMemoryRequirements2KHR");
	vilc_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)load(context, "vkGetImageMemoryRequirements2KHR");
	vilc_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)load(context, "vkGetImageSparseMemoryRequirements2KHR");
#endif /* defined(VK_KHR_get_memory_requirements2) */
#if defined(VK_KHR_line_rasterization)
	vilc_vkCmdSetLineStippleKHR = (PFN_vkCmdSetLineStippleKHR)load(context, "vkCmdSetLineStippleKHR");
#endif /* defined(VK_KHR_line_rasterization) */
#if defined(VK_KHR_maintenance1)
	vilc_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)load(context, "vkTrimCommandPoolKHR");
#endif /* defined(VK_KHR_maintenance1) */
#if defined(VK_KHR_maintenance10)
	vilc_vkCmdEndRendering2KHR = (PFN_vkCmdEndRendering2KHR)load(context, "vkCmdEndRendering2KHR");
#endif /* defined(VK_KHR_maintenance10) */
#if defined(VK_KHR_maintenance3)
	vilc_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)load(context, "vkGetDescriptorSetLayoutSupportKHR");
#endif /* defined(VK_KHR_maintenance3) */
#if defined(VK_KHR_maintenance4)
	vilc_vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR)load(context, "vkGetDeviceBufferMemoryRequirementsKHR");
	vilc_vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR)load(context, "vkGetDeviceImageMemoryRequirementsKHR");
	vilc_vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR)load(context, "vkGetDeviceImageSparseMemoryRequirementsKHR");
#endif /* defined(VK_KHR_maintenance4) */
#if defined(VK_KHR_maintenance5)
	vilc_vkCmdBindIndexBuffer2KHR = (PFN_vkCmdBindIndexBuffer2KHR)load(context, "vkCmdBindIndexBuffer2KHR");
	vilc_vkGetDeviceImageSubresourceLayoutKHR = (PFN_vkGetDeviceImageSubresourceLayoutKHR)load(context, "vkGetDeviceImageSubresourceLayoutKHR");
	vilc_vkGetImageSubresourceLayout2KHR = (PFN_vkGetImageSubresourceLayout2KHR)load(context, "vkGetImageSubresourceLayout2KHR");
	vilc_vkGetRenderingAreaGranularityKHR = (PFN_vkGetRenderingAreaGranularityKHR)load(context, "vkGetRenderingAreaGranularityKHR");
#endif /* defined(VK_KHR_maintenance5) */
#if defined(VK_KHR_maintenance6)
	vilc_vkCmdBindDescriptorSets2KHR = (PFN_vkCmdBindDescriptorSets2KHR)load(context, "vkCmdBindDescriptorSets2KHR");
	vilc_vkCmdPushConstants2KHR = (PFN_vkCmdPushConstants2KHR)load(context, "vkCmdPushConstants2KHR");
#endif /* defined(VK_KHR_maintenance6) */
#if defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor)
	vilc_vkCmdPushDescriptorSet2KHR = (PFN_vkCmdPushDescriptorSet2KHR)load(context, "vkCmdPushDescriptorSet2KHR");
	vilc_vkCmdPushDescriptorSetWithTemplate2KHR = (PFN_vkCmdPushDescriptorSetWithTemplate2KHR)load(context, "vkCmdPushDescriptorSetWithTemplate2KHR");
#endif /* defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer)
	vilc_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT)load(context, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
	vilc_vkCmdSetDescriptorBufferOffsets2EXT = (PFN_vkCmdSetDescriptorBufferOffsets2EXT)load(context, "vkCmdSetDescriptorBufferOffsets2EXT");
#endif /* defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_KHR_map_memory2)
	vilc_vkMapMemory2KHR = (PFN_vkMapMemory2KHR)load(context, "vkMapMemory2KHR");
	vilc_vkUnmapMemory2KHR = (PFN_vkUnmapMemory2KHR)load(context, "vkUnmapMemory2KHR");
#endif /* defined(VK_KHR_map_memory2) */
#if defined(VK_KHR_performance_query)
	vilc_vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)load(context, "vkAcquireProfilingLockKHR");
	vilc_vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)load(context, "vkReleaseProfilingLockKHR");
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_pipeline_binary)
	vilc_vkCreatePipelineBinariesKHR = (PFN_vkCreatePipelineBinariesKHR)load(context, "vkCreatePipelineBinariesKHR");
	vilc_vkDestroyPipelineBinaryKHR = (PFN_vkDestroyPipelineBinaryKHR)load(context, "vkDestroyPipelineBinaryKHR");
	vilc_vkGetPipelineBinaryDataKHR = (PFN_vkGetPipelineBinaryDataKHR)load(context, "vkGetPipelineBinaryDataKHR");
	vilc_vkGetPipelineKeyKHR = (PFN_vkGetPipelineKeyKHR)load(context, "vkGetPipelineKeyKHR");
	vilc_vkReleaseCapturedPipelineDataKHR = (PFN_vkReleaseCapturedPipelineDataKHR)load(context, "vkReleaseCapturedPipelineDataKHR");
#endif /* defined(VK_KHR_pipeline_binary) */
#if defined(VK_KHR_pipeline_executable_properties)
	vilc_vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)load(context, "vkGetPipelineExecutableInternalRepresentationsKHR");
	vilc_vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)load(context, "vkGetPipelineExecutablePropertiesKHR");
	vilc_vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)load(context, "vkGetPipelineExecutableStatisticsKHR");
#endif /* defined(VK_KHR_pipeline_executable_properties) */
#if defined(VK_KHR_present_wait)
	vilc_vkWaitForPresentKHR = (PFN_vkWaitForPresentKHR)load(context, "vkWaitForPresentKHR");
#endif /* defined(VK_KHR_present_wait) */
#if defined(VK_KHR_present_wait2)
	vilc_vkWaitForPresent2KHR = (PFN_vkWaitForPresent2KHR)load(context, "vkWaitForPresent2KHR");
#endif /* defined(VK_KHR_present_wait2) */
#if defined(VK_KHR_push_descriptor)
	vilc_vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)load(context, "vkCmdPushDescriptorSetKHR");
#endif /* defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
	vilc_vkCmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR)load(context, "vkCmdTraceRaysIndirect2KHR");
#endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_ray_tracing_pipeline)
	vilc_vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)load(context, "vkCmdSetRayTracingPipelineStackSizeKHR");
	vilc_vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)load(context, "vkCmdTraceRaysIndirectKHR");
	vilc_vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)load(context, "vkCmdTraceRaysKHR");
	vilc_vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)load(context, "vkCreateRayTracingPipelinesKHR");
	vilc_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)load(context, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
	vilc_vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)load(context, "vkGetRayTracingShaderGroupHandlesKHR");
	vilc_vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)load(context, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif /* defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_sampler_ycbcr_conversion)
	vilc_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)load(context, "vkCreateSamplerYcbcrConversionKHR");
	vilc_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)load(context, "vkDestroySamplerYcbcrConversionKHR");
#endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
#if defined(VK_KHR_shared_presentable_image)
	vilc_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)load(context, "vkGetSwapchainStatusKHR");
#endif /* defined(VK_KHR_shared_presentable_image) */
#if defined(VK_KHR_swapchain)
	vilc_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)load(context, "vkAcquireNextImageKHR");
	vilc_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)load(context, "vkCreateSwapchainKHR");
	vilc_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)load(context, "vkDestroySwapchainKHR");
	vilc_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)load(context, "vkGetSwapchainImagesKHR");
	vilc_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)load(context, "vkQueuePresentKHR");
#endif /* defined(VK_KHR_swapchain) */
#if defined(VK_KHR_swapchain_maintenance1)
	vilc_vkReleaseSwapchainImagesKHR = (PFN_vkReleaseSwapchainImagesKHR)load(context, "vkReleaseSwapchainImagesKHR");
#endif /* defined(VK_KHR_swapchain_maintenance1) */
#if defined(VK_KHR_synchronization2)
	vilc_vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)load(context, "vkCmdPipelineBarrier2KHR");
	vilc_vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)load(context, "vkCmdResetEvent2KHR");
	vilc_vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)load(context, "vkCmdSetEvent2KHR");
	vilc_vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)load(context, "vkCmdWaitEvents2KHR");
	vilc_vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)load(context, "vkCmdWriteTimestamp2KHR");
	vilc_vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)load(context, "vkQueueSubmit2KHR");
#endif /* defined(VK_KHR_synchronization2) */
#if defined(VK_KHR_timeline_semaphore)
	vilc_vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)load(context, "vkGetSemaphoreCounterValueKHR");
	vilc_vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)load(context, "vkSignalSemaphoreKHR");
	vilc_vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)load(context, "vkWaitSemaphoresKHR");
#endif /* defined(VK_KHR_timeline_semaphore) */
#if defined(VK_KHR_video_decode_queue)
	vilc_vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)load(context, "vkCmdDecodeVideoKHR");
#endif /* defined(VK_KHR_video_decode_queue) */
#if defined(VK_KHR_video_encode_queue)
	vilc_vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)load(context, "vkCmdEncodeVideoKHR");
	vilc_vkGetEncodedVideoSessionParametersKHR = (PFN_vkGetEncodedVideoSessionParametersKHR)load(context, "vkGetEncodedVideoSessionParametersKHR");
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
	vilc_vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)load(context, "vkBindVideoSessionMemoryKHR");
	vilc_vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)load(context, "vkCmdBeginVideoCodingKHR");
	vilc_vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)load(context, "vkCmdControlVideoCodingKHR");
	vilc_vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)load(context, "vkCmdEndVideoCodingKHR");
	vilc_vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)load(context, "vkCreateVideoSessionKHR");
	vilc_vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)load(context, "vkCreateVideoSessionParametersKHR");
	vilc_vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)load(context, "vkDestroyVideoSessionKHR");
	vilc_vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)load(context, "vkDestroyVideoSessionParametersKHR");
	vilc_vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)load(context, "vkGetVideoSessionMemoryRequirementsKHR");
	vilc_vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)load(context, "vkUpdateVideoSessionParametersKHR");
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_NVX_binary_import)
	vilc_vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)load(context, "vkCmdCuLaunchKernelNVX");
	vilc_vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)load(context, "vkCreateCuFunctionNVX");
	vilc_vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)load(context, "vkCreateCuModuleNVX");
	vilc_vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)load(context, "vkDestroyCuFunctionNVX");
	vilc_vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)load(context, "vkDestroyCuModuleNVX");
#endif /* defined(VK_NVX_binary_import) */
#if defined(VK_NVX_image_view_handle)
	vilc_vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)load(context, "vkGetImageViewHandleNVX");
#endif /* defined(VK_NVX_image_view_handle) */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3
	vilc_vkGetImageViewHandle64NVX = (PFN_vkGetImageViewHandle64NVX)load(context, "vkGetImageViewHandle64NVX");
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3 */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2
	vilc_vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)load(context, "vkGetImageViewAddressNVX");
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2 */
#if defined(VK_NV_clip_space_w_scaling)
	vilc_vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)load(context, "vkCmdSetViewportWScalingNV");
#endif /* defined(VK_NV_clip_space_w_scaling) */
#if defined(VK_NV_cluster_acceleration_structure)
	vilc_vkCmdBuildClusterAccelerationStructureIndirectNV = (PFN_vkCmdBuildClusterAccelerationStructureIndirectNV)load(context, "vkCmdBuildClusterAccelerationStructureIndirectNV");
	vilc_vkGetClusterAccelerationStructureBuildSizesNV = (PFN_vkGetClusterAccelerationStructureBuildSizesNV)load(context, "vkGetClusterAccelerationStructureBuildSizesNV");
#endif /* defined(VK_NV_cluster_acceleration_structure) */
#if defined(VK_NV_compute_occupancy_priority)
	vilc_vkCmdSetComputeOccupancyPriorityNV = (PFN_vkCmdSetComputeOccupancyPriorityNV)load(context, "vkCmdSetComputeOccupancyPriorityNV");
#endif /* defined(VK_NV_compute_occupancy_priority) */
#if defined(VK_NV_cooperative_vector)
	vilc_vkCmdConvertCooperativeVectorMatrixNV = (PFN_vkCmdConvertCooperativeVectorMatrixNV)load(context, "vkCmdConvertCooperativeVectorMatrixNV");
	vilc_vkConvertCooperativeVectorMatrixNV = (PFN_vkConvertCooperativeVectorMatrixNV)load(context, "vkConvertCooperativeVectorMatrixNV");
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_copy_memory_indirect)
	vilc_vkCmdCopyMemoryIndirectNV = (PFN_vkCmdCopyMemoryIndirectNV)load(context, "vkCmdCopyMemoryIndirectNV");
	vilc_vkCmdCopyMemoryToImageIndirectNV = (PFN_vkCmdCopyMemoryToImageIndirectNV)load(context, "vkCmdCopyMemoryToImageIndirectNV");
#endif /* defined(VK_NV_copy_memory_indirect) */
#if defined(VK_NV_cuda_kernel_launch)
	vilc_vkCmdCudaLaunchKernelNV = (PFN_vkCmdCudaLaunchKernelNV)load(context, "vkCmdCudaLaunchKernelNV");
	vilc_vkCreateCudaFunctionNV = (PFN_vkCreateCudaFunctionNV)load(context, "vkCreateCudaFunctionNV");
	vilc_vkCreateCudaModuleNV = (PFN_vkCreateCudaModuleNV)load(context, "vkCreateCudaModuleNV");
	vilc_vkDestroyCudaFunctionNV = (PFN_vkDestroyCudaFunctionNV)load(context, "vkDestroyCudaFunctionNV");
	vilc_vkDestroyCudaModuleNV = (PFN_vkDestroyCudaModuleNV)load(context, "vkDestroyCudaModuleNV");
	vilc_vkGetCudaModuleCacheNV = (PFN_vkGetCudaModuleCacheNV)load(context, "vkGetCudaModuleCacheNV");
#endif /* defined(VK_NV_cuda_kernel_launch) */
#if defined(VK_NV_device_diagnostic_checkpoints)
	vilc_vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)load(context, "vkCmdSetCheckpointNV");
	vilc_vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)load(context, "vkGetQueueCheckpointDataNV");
#endif /* defined(VK_NV_device_diagnostic_checkpoints) */
#if defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
	vilc_vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)load(context, "vkGetQueueCheckpointData2NV");
#endif /* defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_NV_device_generated_commands)
	vilc_vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)load(context, "vkCmdBindPipelineShaderGroupNV");
	vilc_vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)load(context, "vkCmdExecuteGeneratedCommandsNV");
	vilc_vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)load(context, "vkCmdPreprocessGeneratedCommandsNV");
	vilc_vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)load(context, "vkCreateIndirectCommandsLayoutNV");
	vilc_vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)load(context, "vkDestroyIndirectCommandsLayoutNV");
	vilc_vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)load(context, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif /* defined(VK_NV_device_generated_commands) */
#if defined(VK_NV_device_generated_commands_compute)
	vilc_vkCmdUpdatePipelineIndirectBufferNV = (PFN_vkCmdUpdatePipelineIndirectBufferNV)load(context, "vkCmdUpdatePipelineIndirectBufferNV");
	vilc_vkGetPipelineIndirectDeviceAddressNV = (PFN_vkGetPipelineIndirectDeviceAddressNV)load(context, "vkGetPipelineIndirectDeviceAddressNV");
	vilc_vkGetPipelineIndirectMemoryRequirementsNV = (PFN_vkGetPipelineIndirectMemoryRequirementsNV)load(context, "vkGetPipelineIndirectMemoryRequirementsNV");
#endif /* defined(VK_NV_device_generated_commands_compute) */
#if defined(VK_NV_external_compute_queue)
	vilc_vkCreateExternalComputeQueueNV = (PFN_vkCreateExternalComputeQueueNV)load(context, "vkCreateExternalComputeQueueNV");
	vilc_vkDestroyExternalComputeQueueNV = (PFN_vkDestroyExternalComputeQueueNV)load(context, "vkDestroyExternalComputeQueueNV");
	vilc_vkGetExternalComputeQueueDataNV = (PFN_vkGetExternalComputeQueueDataNV)load(context, "vkGetExternalComputeQueueDataNV");
#endif /* defined(VK_NV_external_compute_queue) */
#if defined(VK_NV_external_memory_rdma)
	vilc_vkGetMemoryRemoteAddressNV = (PFN_vkGetMemoryRemoteAddressNV)load(context, "vkGetMemoryRemoteAddressNV");
#endif /* defined(VK_NV_external_memory_rdma) */
#if defined(VK_NV_external_memory_win32)
	vilc_vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)load(context, "vkGetMemoryWin32HandleNV");
#endif /* defined(VK_NV_external_memory_win32) */
#if defined(VK_NV_fragment_shading_rate_enums)
	vilc_vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)load(context, "vkCmdSetFragmentShadingRateEnumNV");
#endif /* defined(VK_NV_fragment_shading_rate_enums) */
#if defined(VK_NV_low_latency2)
	vilc_vkGetLatencyTimingsNV = (PFN_vkGetLatencyTimingsNV)load(context, "vkGetLatencyTimingsNV");
	vilc_vkLatencySleepNV = (PFN_vkLatencySleepNV)load(context, "vkLatencySleepNV");
	vilc_vkQueueNotifyOutOfBandNV = (PFN_vkQueueNotifyOutOfBandNV)load(context, "vkQueueNotifyOutOfBandNV");
	vilc_vkSetLatencyMarkerNV = (PFN_vkSetLatencyMarkerNV)load(context, "vkSetLatencyMarkerNV");
	vilc_vkSetLatencySleepModeNV = (PFN_vkSetLatencySleepModeNV)load(context, "vkSetLatencySleepModeNV");
#endif /* defined(VK_NV_low_latency2) */
#if defined(VK_NV_memory_decompression)
	vilc_vkCmdDecompressMemoryIndirectCountNV = (PFN_vkCmdDecompressMemoryIndirectCountNV)load(context, "vkCmdDecompressMemoryIndirectCountNV");
	vilc_vkCmdDecompressMemoryNV = (PFN_vkCmdDecompressMemoryNV)load(context, "vkCmdDecompressMemoryNV");
#endif /* defined(VK_NV_memory_decompression) */
#if defined(VK_NV_mesh_shader)
	vilc_vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)load(context, "vkCmdDrawMeshTasksIndirectNV");
	vilc_vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)load(context, "vkCmdDrawMeshTasksNV");
#endif /* defined(VK_NV_mesh_shader) */
#if defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
	vilc_vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)load(context, "vkCmdDrawMeshTasksIndirectCountNV");
#endif /* defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_NV_optical_flow)
	vilc_vkBindOpticalFlowSessionImageNV = (PFN_vkBindOpticalFlowSessionImageNV)load(context, "vkBindOpticalFlowSessionImageNV");
	vilc_vkCmdOpticalFlowExecuteNV = (PFN_vkCmdOpticalFlowExecuteNV)load(context, "vkCmdOpticalFlowExecuteNV");
	vilc_vkCreateOpticalFlowSessionNV = (PFN_vkCreateOpticalFlowSessionNV)load(context, "vkCreateOpticalFlowSessionNV");
	vilc_vkDestroyOpticalFlowSessionNV = (PFN_vkDestroyOpticalFlowSessionNV)load(context, "vkDestroyOpticalFlowSessionNV");
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_NV_partitioned_acceleration_structure)
	vilc_vkCmdBuildPartitionedAccelerationStructuresNV = (PFN_vkCmdBuildPartitionedAccelerationStructuresNV)load(context, "vkCmdBuildPartitionedAccelerationStructuresNV");
	vilc_vkGetPartitionedAccelerationStructuresBuildSizesNV = (PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV)load(context, "vkGetPartitionedAccelerationStructuresBuildSizesNV");
#endif /* defined(VK_NV_partitioned_acceleration_structure) */
#if defined(VK_NV_ray_tracing)
	vilc_vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)load(context, "vkBindAccelerationStructureMemoryNV");
	vilc_vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)load(context, "vkCmdBuildAccelerationStructureNV");
	vilc_vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)load(context, "vkCmdCopyAccelerationStructureNV");
	vilc_vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)load(context, "vkCmdTraceRaysNV");
	vilc_vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)load(context, "vkCmdWriteAccelerationStructuresPropertiesNV");
	vilc_vkCompileDeferredNV = (PFN_vkCompileDeferredNV)load(context, "vkCompileDeferredNV");
	vilc_vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)load(context, "vkCreateAccelerationStructureNV");
	vilc_vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)load(context, "vkCreateRayTracingPipelinesNV");
	vilc_vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)load(context, "vkDestroyAccelerationStructureNV");
	vilc_vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)load(context, "vkGetAccelerationStructureHandleNV");
	vilc_vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)load(context, "vkGetAccelerationStructureMemoryRequirementsNV");
	vilc_vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)load(context, "vkGetRayTracingShaderGroupHandlesNV");
#endif /* defined(VK_NV_ray_tracing) */
#if defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2
	vilc_vkCmdSetExclusiveScissorEnableNV = (PFN_vkCmdSetExclusiveScissorEnableNV)load(context, "vkCmdSetExclusiveScissorEnableNV");
#endif /* defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2 */
#if defined(VK_NV_scissor_exclusive)
	vilc_vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)load(context, "vkCmdSetExclusiveScissorNV");
#endif /* defined(VK_NV_scissor_exclusive) */
#if defined(VK_NV_shading_rate_image)
	vilc_vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)load(context, "vkCmdBindShadingRateImageNV");
	vilc_vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)load(context, "vkCmdSetCoarseSampleOrderNV");
	vilc_vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)load(context, "vkCmdSetViewportShadingRatePaletteNV");
#endif /* defined(VK_NV_shading_rate_image) */
#if defined(VK_OHOS_external_memory)
	vilc_vkGetMemoryNativeBufferOHOS = (PFN_vkGetMemoryNativeBufferOHOS)load(context, "vkGetMemoryNativeBufferOHOS");
	vilc_vkGetNativeBufferPropertiesOHOS = (PFN_vkGetNativeBufferPropertiesOHOS)load(context, "vkGetNativeBufferPropertiesOHOS");
#endif /* defined(VK_OHOS_external_memory) */
#if defined(VK_QCOM_tile_memory_heap)
	vilc_vkCmdBindTileMemoryQCOM = (PFN_vkCmdBindTileMemoryQCOM)load(context, "vkCmdBindTileMemoryQCOM");
#endif /* defined(VK_QCOM_tile_memory_heap) */
#if defined(VK_QCOM_tile_properties)
	vilc_vkGetDynamicRenderingTilePropertiesQCOM = (PFN_vkGetDynamicRenderingTilePropertiesQCOM)load(context, "vkGetDynamicRenderingTilePropertiesQCOM");
	vilc_vkGetFramebufferTilePropertiesQCOM = (PFN_vkGetFramebufferTilePropertiesQCOM)load(context, "vkGetFramebufferTilePropertiesQCOM");
#endif /* defined(VK_QCOM_tile_properties) */
#if defined(VK_QCOM_tile_shading)
	vilc_vkCmdBeginPerTileExecutionQCOM = (PFN_vkCmdBeginPerTileExecutionQCOM)load(context, "vkCmdBeginPerTileExecutionQCOM");
	vilc_vkCmdDispatchTileQCOM = (PFN_vkCmdDispatchTileQCOM)load(context, "vkCmdDispatchTileQCOM");
	vilc_vkCmdEndPerTileExecutionQCOM = (PFN_vkCmdEndPerTileExecutionQCOM)load(context, "vkCmdEndPerTileExecutionQCOM");
#endif /* defined(VK_QCOM_tile_shading) */
#if defined(VK_QNX_external_memory_screen_buffer)
	vilc_vkGetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX)load(context, "vkGetScreenBufferPropertiesQNX");
#endif /* defined(VK_QNX_external_memory_screen_buffer) */
#if defined(VK_VALVE_descriptor_set_host_mapping)
	vilc_vkGetDescriptorSetHostMappingVALVE = (PFN_vkGetDescriptorSetHostMappingVALVE)load(context, "vkGetDescriptorSetHostMappingVALVE");
	vilc_vkGetDescriptorSetLayoutHostMappingInfoVALVE = (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE)load(context, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
#endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
#if (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control))
	vilc_vkCmdSetDepthClampRangeEXT = (PFN_vkCmdSetDepthClampRangeEXT)load(context, "vkCmdSetDepthClampRangeEXT");
#endif /* (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control)) */
#if (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object))
	vilc_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)load(context, "vkCmdBindVertexBuffers2EXT");
	vilc_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)load(context, "vkCmdSetCullModeEXT");
	vilc_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)load(context, "vkCmdSetDepthBoundsTestEnableEXT");
	vilc_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)load(context, "vkCmdSetDepthCompareOpEXT");
	vilc_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)load(context, "vkCmdSetDepthTestEnableEXT");
	vilc_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)load(context, "vkCmdSetDepthWriteEnableEXT");
	vilc_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)load(context, "vkCmdSetFrontFaceEXT");
	vilc_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)load(context, "vkCmdSetPrimitiveTopologyEXT");
	vilc_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)load(context, "vkCmdSetScissorWithCountEXT");
	vilc_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)load(context, "vkCmdSetStencilOpEXT");
	vilc_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)load(context, "vkCmdSetStencilTestEnableEXT");
	vilc_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)load(context, "vkCmdSetViewportWithCountEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object))
	vilc_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)load(context, "vkCmdSetDepthBiasEnableEXT");
	vilc_vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)load(context, "vkCmdSetLogicOpEXT");
	vilc_vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)load(context, "vkCmdSetPatchControlPointsEXT");
	vilc_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)load(context, "vkCmdSetPrimitiveRestartEnableEXT");
	vilc_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)load(context, "vkCmdSetRasterizerDiscardEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object))
	vilc_vkCmdSetAlphaToCoverageEnableEXT = (PFN_vkCmdSetAlphaToCoverageEnableEXT)load(context, "vkCmdSetAlphaToCoverageEnableEXT");
	vilc_vkCmdSetAlphaToOneEnableEXT = (PFN_vkCmdSetAlphaToOneEnableEXT)load(context, "vkCmdSetAlphaToOneEnableEXT");
	vilc_vkCmdSetColorBlendEnableEXT = (PFN_vkCmdSetColorBlendEnableEXT)load(context, "vkCmdSetColorBlendEnableEXT");
	vilc_vkCmdSetColorBlendEquationEXT = (PFN_vkCmdSetColorBlendEquationEXT)load(context, "vkCmdSetColorBlendEquationEXT");
	vilc_vkCmdSetColorWriteMaskEXT = (PFN_vkCmdSetColorWriteMaskEXT)load(context, "vkCmdSetColorWriteMaskEXT");
	vilc_vkCmdSetDepthClampEnableEXT = (PFN_vkCmdSetDepthClampEnableEXT)load(context, "vkCmdSetDepthClampEnableEXT");
	vilc_vkCmdSetLogicOpEnableEXT = (PFN_vkCmdSetLogicOpEnableEXT)load(context, "vkCmdSetLogicOpEnableEXT");
	vilc_vkCmdSetPolygonModeEXT = (PFN_vkCmdSetPolygonModeEXT)load(context, "vkCmdSetPolygonModeEXT");
	vilc_vkCmdSetRasterizationSamplesEXT = (PFN_vkCmdSetRasterizationSamplesEXT)load(context, "vkCmdSetRasterizationSamplesEXT");
	vilc_vkCmdSetSampleMaskEXT = (PFN_vkCmdSetSampleMaskEXT)load(context, "vkCmdSetSampleMaskEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object))
	vilc_vkCmdSetTessellationDomainOriginEXT = (PFN_vkCmdSetTessellationDomainOriginEXT)load(context, "vkCmdSetTessellationDomainOriginEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback))
	vilc_vkCmdSetRasterizationStreamEXT = (PFN_vkCmdSetRasterizationStreamEXT)load(context, "vkCmdSetRasterizationStreamEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization))
	vilc_vkCmdSetConservativeRasterizationModeEXT = (PFN_vkCmdSetConservativeRasterizationModeEXT)load(context, "vkCmdSetConservativeRasterizationModeEXT");
	vilc_vkCmdSetExtraPrimitiveOverestimationSizeEXT = (PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT)load(context, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable))
	vilc_vkCmdSetDepthClipEnableEXT = (PFN_vkCmdSetDepthClipEnableEXT)load(context, "vkCmdSetDepthClipEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations))
	vilc_vkCmdSetSampleLocationsEnableEXT = (PFN_vkCmdSetSampleLocationsEnableEXT)load(context, "vkCmdSetSampleLocationsEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced))
	vilc_vkCmdSetColorBlendAdvancedEXT = (PFN_vkCmdSetColorBlendAdvancedEXT)load(context, "vkCmdSetColorBlendAdvancedEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex))
	vilc_vkCmdSetProvokingVertexModeEXT = (PFN_vkCmdSetProvokingVertexModeEXT)load(context, "vkCmdSetProvokingVertexModeEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization))
	vilc_vkCmdSetLineRasterizationModeEXT = (PFN_vkCmdSetLineRasterizationModeEXT)load(context, "vkCmdSetLineRasterizationModeEXT");
	vilc_vkCmdSetLineStippleEnableEXT = (PFN_vkCmdSetLineStippleEnableEXT)load(context, "vkCmdSetLineStippleEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control))
	vilc_vkCmdSetDepthClipNegativeOneToOneEXT = (PFN_vkCmdSetDepthClipNegativeOneToOneEXT)load(context, "vkCmdSetDepthClipNegativeOneToOneEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling))
	vilc_vkCmdSetViewportWScalingEnableNV = (PFN_vkCmdSetViewportWScalingEnableNV)load(context, "vkCmdSetViewportWScalingEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle))
	vilc_vkCmdSetViewportSwizzleNV = (PFN_vkCmdSetViewportSwizzleNV)load(context, "vkCmdSetViewportSwizzleNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color))
	vilc_vkCmdSetCoverageToColorEnableNV = (PFN_vkCmdSetCoverageToColorEnableNV)load(context, "vkCmdSetCoverageToColorEnableNV");
	vilc_vkCmdSetCoverageToColorLocationNV = (PFN_vkCmdSetCoverageToColorLocationNV)load(context, "vkCmdSetCoverageToColorLocationNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples))
	vilc_vkCmdSetCoverageModulationModeNV = (PFN_vkCmdSetCoverageModulationModeNV)load(context, "vkCmdSetCoverageModulationModeNV");
	vilc_vkCmdSetCoverageModulationTableEnableNV = (PFN_vkCmdSetCoverageModulationTableEnableNV)load(context, "vkCmdSetCoverageModulationTableEnableNV");
	vilc_vkCmdSetCoverageModulationTableNV = (PFN_vkCmdSetCoverageModulationTableNV)load(context, "vkCmdSetCoverageModulationTableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image))
	vilc_vkCmdSetShadingRateImageEnableNV = (PFN_vkCmdSetShadingRateImageEnableNV)load(context, "vkCmdSetShadingRateImageEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test))
	vilc_vkCmdSetRepresentativeFragmentTestEnableNV = (PFN_vkCmdSetRepresentativeFragmentTestEnableNV)load(context, "vkCmdSetRepresentativeFragmentTestEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode))
	vilc_vkCmdSetCoverageReductionModeNV = (PFN_vkCmdSetCoverageReductionModeNV)load(context, "vkCmdSetCoverageReductionModeNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode)) */
#if (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control))
	vilc_vkGetImageSubresourceLayout2EXT = (PFN_vkGetImageSubresourceLayout2EXT)load(context, "vkGetImageSubresourceLayout2EXT");
#endif /* (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control)) */
#if (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state))
	vilc_vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)load(context, "vkCmdSetVertexInputEXT");
#endif /* (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state)) */
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)))
	vilc_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)load(context, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template))) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	vilc_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)load(context, "vkGetDeviceGroupPresentCapabilitiesKHR");
	vilc_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)load(context, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	vilc_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)load(context, "vkAcquireNextImage2KHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_LOAD_DEVICE_VILC */
#else /* VOLK_IN_LOADERS_CLOTH */
	/* VOLK_GENERATE_LOAD_DEVICE */
#if defined(VK_VERSION_1_0)
	vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)load(context, "vkAllocateCommandBuffers");
	vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)load(context, "vkAllocateDescriptorSets");
	vkAllocateMemory = (PFN_vkAllocateMemory)load(context, "vkAllocateMemory");
	vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)load(context, "vkBeginCommandBuffer");
	vkBindBufferMemory = (PFN_vkBindBufferMemory)load(context, "vkBindBufferMemory");
	vkBindImageMemory = (PFN_vkBindImageMemory)load(context, "vkBindImageMemory");
	vkCmdBeginQuery = (PFN_vkCmdBeginQuery)load(context, "vkCmdBeginQuery");
	vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)load(context, "vkCmdBeginRenderPass");
	vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)load(context, "vkCmdBindDescriptorSets");
	vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)load(context, "vkCmdBindIndexBuffer");
	vkCmdBindPipeline = (PFN_vkCmdBindPipeline)load(context, "vkCmdBindPipeline");
	vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)load(context, "vkCmdBindVertexBuffers");
	vkCmdBlitImage = (PFN_vkCmdBlitImage)load(context, "vkCmdBlitImage");
	vkCmdClearAttachments = (PFN_vkCmdClearAttachments)load(context, "vkCmdClearAttachments");
	vkCmdClearColorImage = (PFN_vkCmdClearColorImage)load(context, "vkCmdClearColorImage");
	vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)load(context, "vkCmdClearDepthStencilImage");
	vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)load(context, "vkCmdCopyBuffer");
	vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)load(context, "vkCmdCopyBufferToImage");
	vkCmdCopyImage = (PFN_vkCmdCopyImage)load(context, "vkCmdCopyImage");
	vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)load(context, "vkCmdCopyImageToBuffer");
	vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)load(context, "vkCmdCopyQueryPoolResults");
	vkCmdDispatch = (PFN_vkCmdDispatch)load(context, "vkCmdDispatch");
	vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)load(context, "vkCmdDispatchIndirect");
	vkCmdDraw = (PFN_vkCmdDraw)load(context, "vkCmdDraw");
	vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)load(context, "vkCmdDrawIndexed");
	vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)load(context, "vkCmdDrawIndexedIndirect");
	vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)load(context, "vkCmdDrawIndirect");
	vkCmdEndQuery = (PFN_vkCmdEndQuery)load(context, "vkCmdEndQuery");
	vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)load(context, "vkCmdEndRenderPass");
	vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)load(context, "vkCmdExecuteCommands");
	vkCmdFillBuffer = (PFN_vkCmdFillBuffer)load(context, "vkCmdFillBuffer");
	vkCmdNextSubpass = (PFN_vkCmdNextSubpass)load(context, "vkCmdNextSubpass");
	vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)load(context, "vkCmdPipelineBarrier");
	vkCmdPushConstants = (PFN_vkCmdPushConstants)load(context, "vkCmdPushConstants");
	vkCmdResetEvent = (PFN_vkCmdResetEvent)load(context, "vkCmdResetEvent");
	vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)load(context, "vkCmdResetQueryPool");
	vkCmdResolveImage = (PFN_vkCmdResolveImage)load(context, "vkCmdResolveImage");
	vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)load(context, "vkCmdSetBlendConstants");
	vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)load(context, "vkCmdSetDepthBias");
	vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)load(context, "vkCmdSetDepthBounds");
	vkCmdSetEvent = (PFN_vkCmdSetEvent)load(context, "vkCmdSetEvent");
	vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)load(context, "vkCmdSetLineWidth");
	vkCmdSetScissor = (PFN_vkCmdSetScissor)load(context, "vkCmdSetScissor");
	vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)load(context, "vkCmdSetStencilCompareMask");
	vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)load(context, "vkCmdSetStencilReference");
	vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)load(context, "vkCmdSetStencilWriteMask");
	vkCmdSetViewport = (PFN_vkCmdSetViewport)load(context, "vkCmdSetViewport");
	vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)load(context, "vkCmdUpdateBuffer");
	vkCmdWaitEvents = (PFN_vkCmdWaitEvents)load(context, "vkCmdWaitEvents");
	vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)load(context, "vkCmdWriteTimestamp");
	vkCreateBuffer = (PFN_vkCreateBuffer)load(context, "vkCreateBuffer");
	vkCreateBufferView = (PFN_vkCreateBufferView)load(context, "vkCreateBufferView");
	vkCreateCommandPool = (PFN_vkCreateCommandPool)load(context, "vkCreateCommandPool");
	vkCreateComputePipelines = (PFN_vkCreateComputePipelines)load(context, "vkCreateComputePipelines");
	vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)load(context, "vkCreateDescriptorPool");
	vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)load(context, "vkCreateDescriptorSetLayout");
	vkCreateEvent = (PFN_vkCreateEvent)load(context, "vkCreateEvent");
	vkCreateFence = (PFN_vkCreateFence)load(context, "vkCreateFence");
	vkCreateFramebuffer = (PFN_vkCreateFramebuffer)load(context, "vkCreateFramebuffer");
	vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)load(context, "vkCreateGraphicsPipelines");
	vkCreateImage = (PFN_vkCreateImage)load(context, "vkCreateImage");
	vkCreateImageView = (PFN_vkCreateImageView)load(context, "vkCreateImageView");
	vkCreatePipelineCache = (PFN_vkCreatePipelineCache)load(context, "vkCreatePipelineCache");
	vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)load(context, "vkCreatePipelineLayout");
	vkCreateQueryPool = (PFN_vkCreateQueryPool)load(context, "vkCreateQueryPool");
	vkCreateRenderPass = (PFN_vkCreateRenderPass)load(context, "vkCreateRenderPass");
	vkCreateSampler = (PFN_vkCreateSampler)load(context, "vkCreateSampler");
	vkCreateSemaphore = (PFN_vkCreateSemaphore)load(context, "vkCreateSemaphore");
	vkCreateShaderModule = (PFN_vkCreateShaderModule)load(context, "vkCreateShaderModule");
	vkDestroyBuffer = (PFN_vkDestroyBuffer)load(context, "vkDestroyBuffer");
	vkDestroyBufferView = (PFN_vkDestroyBufferView)load(context, "vkDestroyBufferView");
	vkDestroyCommandPool = (PFN_vkDestroyCommandPool)load(context, "vkDestroyCommandPool");
	vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)load(context, "vkDestroyDescriptorPool");
	vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)load(context, "vkDestroyDescriptorSetLayout");
	vkDestroyDevice = (PFN_vkDestroyDevice)load(context, "vkDestroyDevice");
	vkDestroyEvent = (PFN_vkDestroyEvent)load(context, "vkDestroyEvent");
	vkDestroyFence = (PFN_vkDestroyFence)load(context, "vkDestroyFence");
	vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)load(context, "vkDestroyFramebuffer");
	vkDestroyImage = (PFN_vkDestroyImage)load(context, "vkDestroyImage");
	vkDestroyImageView = (PFN_vkDestroyImageView)load(context, "vkDestroyImageView");
	vkDestroyPipeline = (PFN_vkDestroyPipeline)load(context, "vkDestroyPipeline");
	vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)load(context, "vkDestroyPipelineCache");
	vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)load(context, "vkDestroyPipelineLayout");
	vkDestroyQueryPool = (PFN_vkDestroyQueryPool)load(context, "vkDestroyQueryPool");
	vkDestroyRenderPass = (PFN_vkDestroyRenderPass)load(context, "vkDestroyRenderPass");
	vkDestroySampler = (PFN_vkDestroySampler)load(context, "vkDestroySampler");
	vkDestroySemaphore = (PFN_vkDestroySemaphore)load(context, "vkDestroySemaphore");
	vkDestroyShaderModule = (PFN_vkDestroyShaderModule)load(context, "vkDestroyShaderModule");
	vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)load(context, "vkDeviceWaitIdle");
	vkEndCommandBuffer = (PFN_vkEndCommandBuffer)load(context, "vkEndCommandBuffer");
	vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)load(context, "vkFlushMappedMemoryRanges");
	vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)load(context, "vkFreeCommandBuffers");
	vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)load(context, "vkFreeDescriptorSets");
	vkFreeMemory = (PFN_vkFreeMemory)load(context, "vkFreeMemory");
	vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)load(context, "vkGetBufferMemoryRequirements");
	vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)load(context, "vkGetDeviceMemoryCommitment");
	vkGetDeviceQueue = (PFN_vkGetDeviceQueue)load(context, "vkGetDeviceQueue");
	vkGetEventStatus = (PFN_vkGetEventStatus)load(context, "vkGetEventStatus");
	vkGetFenceStatus = (PFN_vkGetFenceStatus)load(context, "vkGetFenceStatus");
	vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)load(context, "vkGetImageMemoryRequirements");
	vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)load(context, "vkGetImageSparseMemoryRequirements");
	vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)load(context, "vkGetImageSubresourceLayout");
	vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)load(context, "vkGetPipelineCacheData");
	vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)load(context, "vkGetQueryPoolResults");
	vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)load(context, "vkGetRenderAreaGranularity");
	vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)load(context, "vkInvalidateMappedMemoryRanges");
	vkMapMemory = (PFN_vkMapMemory)load(context, "vkMapMemory");
	vkMergePipelineCaches = (PFN_vkMergePipelineCaches)load(context, "vkMergePipelineCaches");
	vkQueueBindSparse = (PFN_vkQueueBindSparse)load(context, "vkQueueBindSparse");
	vkQueueSubmit = (PFN_vkQueueSubmit)load(context, "vkQueueSubmit");
	vkQueueWaitIdle = (PFN_vkQueueWaitIdle)load(context, "vkQueueWaitIdle");
	vkResetCommandBuffer = (PFN_vkResetCommandBuffer)load(context, "vkResetCommandBuffer");
	vkResetCommandPool = (PFN_vkResetCommandPool)load(context, "vkResetCommandPool");
	vkResetDescriptorPool = (PFN_vkResetDescriptorPool)load(context, "vkResetDescriptorPool");
	vkResetEvent = (PFN_vkResetEvent)load(context, "vkResetEvent");
	vkResetFences = (PFN_vkResetFences)load(context, "vkResetFences");
	vkSetEvent = (PFN_vkSetEvent)load(context, "vkSetEvent");
	vkUnmapMemory = (PFN_vkUnmapMemory)load(context, "vkUnmapMemory");
	vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)load(context, "vkUpdateDescriptorSets");
	vkWaitForFences = (PFN_vkWaitForFences)load(context, "vkWaitForFences");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)load(context, "vkBindBufferMemory2");
	vkBindImageMemory2 = (PFN_vkBindImageMemory2)load(context, "vkBindImageMemory2");
	vkCmdDispatchBase = (PFN_vkCmdDispatchBase)load(context, "vkCmdDispatchBase");
	vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)load(context, "vkCmdSetDeviceMask");
	vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)load(context, "vkCreateDescriptorUpdateTemplate");
	vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)load(context, "vkCreateSamplerYcbcrConversion");
	vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)load(context, "vkDestroyDescriptorUpdateTemplate");
	vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)load(context, "vkDestroySamplerYcbcrConversion");
	vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)load(context, "vkGetBufferMemoryRequirements2");
	vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)load(context, "vkGetDescriptorSetLayoutSupport");
	vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)load(context, "vkGetDeviceGroupPeerMemoryFeatures");
	vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)load(context, "vkGetDeviceQueue2");
	vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)load(context, "vkGetImageMemoryRequirements2");
	vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)load(context, "vkGetImageSparseMemoryRequirements2");
	vkTrimCommandPool = (PFN_vkTrimCommandPool)load(context, "vkTrimCommandPool");
	vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)load(context, "vkUpdateDescriptorSetWithTemplate");
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_2)
	vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)load(context, "vkCmdBeginRenderPass2");
	vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)load(context, "vkCmdDrawIndexedIndirectCount");
	vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)load(context, "vkCmdDrawIndirectCount");
	vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)load(context, "vkCmdEndRenderPass2");
	vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)load(context, "vkCmdNextSubpass2");
	vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)load(context, "vkCreateRenderPass2");
	vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)load(context, "vkGetBufferDeviceAddress");
	vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)load(context, "vkGetBufferOpaqueCaptureAddress");
	vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)load(context, "vkGetDeviceMemoryOpaqueCaptureAddress");
	vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)load(context, "vkGetSemaphoreCounterValue");
	vkResetQueryPool = (PFN_vkResetQueryPool)load(context, "vkResetQueryPool");
	vkSignalSemaphore = (PFN_vkSignalSemaphore)load(context, "vkSignalSemaphore");
	vkWaitSemaphores = (PFN_vkWaitSemaphores)load(context, "vkWaitSemaphores");
#endif /* defined(VK_VERSION_1_2) */
#if defined(VK_VERSION_1_3)
	vkCmdBeginRendering = (PFN_vkCmdBeginRendering)load(context, "vkCmdBeginRendering");
	vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)load(context, "vkCmdBindVertexBuffers2");
	vkCmdBlitImage2 = (PFN_vkCmdBlitImage2)load(context, "vkCmdBlitImage2");
	vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)load(context, "vkCmdCopyBuffer2");
	vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)load(context, "vkCmdCopyBufferToImage2");
	vkCmdCopyImage2 = (PFN_vkCmdCopyImage2)load(context, "vkCmdCopyImage2");
	vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)load(context, "vkCmdCopyImageToBuffer2");
	vkCmdEndRendering = (PFN_vkCmdEndRendering)load(context, "vkCmdEndRendering");
	vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)load(context, "vkCmdPipelineBarrier2");
	vkCmdResetEvent2 = (PFN_vkCmdResetEvent2)load(context, "vkCmdResetEvent2");
	vkCmdResolveImage2 = (PFN_vkCmdResolveImage2)load(context, "vkCmdResolveImage2");
	vkCmdSetCullMode = (PFN_vkCmdSetCullMode)load(context, "vkCmdSetCullMode");
	vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)load(context, "vkCmdSetDepthBiasEnable");
	vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)load(context, "vkCmdSetDepthBoundsTestEnable");
	vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)load(context, "vkCmdSetDepthCompareOp");
	vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)load(context, "vkCmdSetDepthTestEnable");
	vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)load(context, "vkCmdSetDepthWriteEnable");
	vkCmdSetEvent2 = (PFN_vkCmdSetEvent2)load(context, "vkCmdSetEvent2");
	vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace)load(context, "vkCmdSetFrontFace");
	vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)load(context, "vkCmdSetPrimitiveRestartEnable");
	vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)load(context, "vkCmdSetPrimitiveTopology");
	vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable)load(context, "vkCmdSetRasterizerDiscardEnable");
	vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)load(context, "vkCmdSetScissorWithCount");
	vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp)load(context, "vkCmdSetStencilOp");
	vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)load(context, "vkCmdSetStencilTestEnable");
	vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)load(context, "vkCmdSetViewportWithCount");
	vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2)load(context, "vkCmdWaitEvents2");
	vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)load(context, "vkCmdWriteTimestamp2");
	vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)load(context, "vkCreatePrivateDataSlot");
	vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)load(context, "vkDestroyPrivateDataSlot");
	vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements)load(context, "vkGetDeviceBufferMemoryRequirements");
	vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements)load(context, "vkGetDeviceImageMemoryRequirements");
	vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)load(context, "vkGetDeviceImageSparseMemoryRequirements");
	vkGetPrivateData = (PFN_vkGetPrivateData)load(context, "vkGetPrivateData");
	vkQueueSubmit2 = (PFN_vkQueueSubmit2)load(context, "vkQueueSubmit2");
	vkSetPrivateData = (PFN_vkSetPrivateData)load(context, "vkSetPrivateData");
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_VERSION_1_4)
	vkCmdBindDescriptorSets2 = (PFN_vkCmdBindDescriptorSets2)load(context, "vkCmdBindDescriptorSets2");
	vkCmdBindIndexBuffer2 = (PFN_vkCmdBindIndexBuffer2)load(context, "vkCmdBindIndexBuffer2");
	vkCmdPushConstants2 = (PFN_vkCmdPushConstants2)load(context, "vkCmdPushConstants2");
	vkCmdPushDescriptorSet = (PFN_vkCmdPushDescriptorSet)load(context, "vkCmdPushDescriptorSet");
	vkCmdPushDescriptorSet2 = (PFN_vkCmdPushDescriptorSet2)load(context, "vkCmdPushDescriptorSet2");
	vkCmdPushDescriptorSetWithTemplate = (PFN_vkCmdPushDescriptorSetWithTemplate)load(context, "vkCmdPushDescriptorSetWithTemplate");
	vkCmdPushDescriptorSetWithTemplate2 = (PFN_vkCmdPushDescriptorSetWithTemplate2)load(context, "vkCmdPushDescriptorSetWithTemplate2");
	vkCmdSetLineStipple = (PFN_vkCmdSetLineStipple)load(context, "vkCmdSetLineStipple");
	vkCmdSetRenderingAttachmentLocations = (PFN_vkCmdSetRenderingAttachmentLocations)load(context, "vkCmdSetRenderingAttachmentLocations");
	vkCmdSetRenderingInputAttachmentIndices = (PFN_vkCmdSetRenderingInputAttachmentIndices)load(context, "vkCmdSetRenderingInputAttachmentIndices");
	vkCopyImageToImage = (PFN_vkCopyImageToImage)load(context, "vkCopyImageToImage");
	vkCopyImageToMemory = (PFN_vkCopyImageToMemory)load(context, "vkCopyImageToMemory");
	vkCopyMemoryToImage = (PFN_vkCopyMemoryToImage)load(context, "vkCopyMemoryToImage");
	vkGetDeviceImageSubresourceLayout = (PFN_vkGetDeviceImageSubresourceLayout)load(context, "vkGetDeviceImageSubresourceLayout");
	vkGetImageSubresourceLayout2 = (PFN_vkGetImageSubresourceLayout2)load(context, "vkGetImageSubresourceLayout2");
	vkGetRenderingAreaGranularity = (PFN_vkGetRenderingAreaGranularity)load(context, "vkGetRenderingAreaGranularity");
	vkMapMemory2 = (PFN_vkMapMemory2)load(context, "vkMapMemory2");
	vkTransitionImageLayout = (PFN_vkTransitionImageLayout)load(context, "vkTransitionImageLayout");
	vkUnmapMemory2 = (PFN_vkUnmapMemory2)load(context, "vkUnmapMemory2");
#endif /* defined(VK_VERSION_1_4) */
#if defined(VK_AMDX_shader_enqueue)
	vkCmdDispatchGraphAMDX = (PFN_vkCmdDispatchGraphAMDX)load(context, "vkCmdDispatchGraphAMDX");
	vkCmdDispatchGraphIndirectAMDX = (PFN_vkCmdDispatchGraphIndirectAMDX)load(context, "vkCmdDispatchGraphIndirectAMDX");
	vkCmdDispatchGraphIndirectCountAMDX = (PFN_vkCmdDispatchGraphIndirectCountAMDX)load(context, "vkCmdDispatchGraphIndirectCountAMDX");
	vkCmdInitializeGraphScratchMemoryAMDX = (PFN_vkCmdInitializeGraphScratchMemoryAMDX)load(context, "vkCmdInitializeGraphScratchMemoryAMDX");
	vkCreateExecutionGraphPipelinesAMDX = (PFN_vkCreateExecutionGraphPipelinesAMDX)load(context, "vkCreateExecutionGraphPipelinesAMDX");
	vkGetExecutionGraphPipelineNodeIndexAMDX = (PFN_vkGetExecutionGraphPipelineNodeIndexAMDX)load(context, "vkGetExecutionGraphPipelineNodeIndexAMDX");
	vkGetExecutionGraphPipelineScratchSizeAMDX = (PFN_vkGetExecutionGraphPipelineScratchSizeAMDX)load(context, "vkGetExecutionGraphPipelineScratchSizeAMDX");
#endif /* defined(VK_AMDX_shader_enqueue) */
#if defined(VK_AMD_anti_lag)
	vkAntiLagUpdateAMD = (PFN_vkAntiLagUpdateAMD)load(context, "vkAntiLagUpdateAMD");
#endif /* defined(VK_AMD_anti_lag) */
#if defined(VK_AMD_buffer_marker)
	vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)load(context, "vkCmdWriteBufferMarkerAMD");
#endif /* defined(VK_AMD_buffer_marker) */
#if defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
	vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)load(context, "vkCmdWriteBufferMarker2AMD");
#endif /* defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_AMD_display_native_hdr)
	vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)load(context, "vkSetLocalDimmingAMD");
#endif /* defined(VK_AMD_display_native_hdr) */
#if defined(VK_AMD_draw_indirect_count)
	vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)load(context, "vkCmdDrawIndexedIndirectCountAMD");
	vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)load(context, "vkCmdDrawIndirectCountAMD");
#endif /* defined(VK_AMD_draw_indirect_count) */
#if defined(VK_AMD_shader_info)
	vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)load(context, "vkGetShaderInfoAMD");
#endif /* defined(VK_AMD_shader_info) */
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
	vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)load(context, "vkGetAndroidHardwareBufferPropertiesANDROID");
	vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)load(context, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
#if defined(VK_ARM_data_graph)
	vkBindDataGraphPipelineSessionMemoryARM = (PFN_vkBindDataGraphPipelineSessionMemoryARM)load(context, "vkBindDataGraphPipelineSessionMemoryARM");
	vkCmdDispatchDataGraphARM = (PFN_vkCmdDispatchDataGraphARM)load(context, "vkCmdDispatchDataGraphARM");
	vkCreateDataGraphPipelineSessionARM = (PFN_vkCreateDataGraphPipelineSessionARM)load(context, "vkCreateDataGraphPipelineSessionARM");
	vkCreateDataGraphPipelinesARM = (PFN_vkCreateDataGraphPipelinesARM)load(context, "vkCreateDataGraphPipelinesARM");
	vkDestroyDataGraphPipelineSessionARM = (PFN_vkDestroyDataGraphPipelineSessionARM)load(context, "vkDestroyDataGraphPipelineSessionARM");
	vkGetDataGraphPipelineAvailablePropertiesARM = (PFN_vkGetDataGraphPipelineAvailablePropertiesARM)load(context, "vkGetDataGraphPipelineAvailablePropertiesARM");
	vkGetDataGraphPipelinePropertiesARM = (PFN_vkGetDataGraphPipelinePropertiesARM)load(context, "vkGetDataGraphPipelinePropertiesARM");
	vkGetDataGraphPipelineSessionBindPointRequirementsARM = (PFN_vkGetDataGraphPipelineSessionBindPointRequirementsARM)load(context, "vkGetDataGraphPipelineSessionBindPointRequirementsARM");
	vkGetDataGraphPipelineSessionMemoryRequirementsARM = (PFN_vkGetDataGraphPipelineSessionMemoryRequirementsARM)load(context, "vkGetDataGraphPipelineSessionMemoryRequirementsARM");
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_tensors)
	vkBindTensorMemoryARM = (PFN_vkBindTensorMemoryARM)load(context, "vkBindTensorMemoryARM");
	vkCmdCopyTensorARM = (PFN_vkCmdCopyTensorARM)load(context, "vkCmdCopyTensorARM");
	vkCreateTensorARM = (PFN_vkCreateTensorARM)load(context, "vkCreateTensorARM");
	vkCreateTensorViewARM = (PFN_vkCreateTensorViewARM)load(context, "vkCreateTensorViewARM");
	vkDestroyTensorARM = (PFN_vkDestroyTensorARM)load(context, "vkDestroyTensorARM");
	vkDestroyTensorViewARM = (PFN_vkDestroyTensorViewARM)load(context, "vkDestroyTensorViewARM");
	vkGetDeviceTensorMemoryRequirementsARM = (PFN_vkGetDeviceTensorMemoryRequirementsARM)load(context, "vkGetDeviceTensorMemoryRequirementsARM");
	vkGetTensorMemoryRequirementsARM = (PFN_vkGetTensorMemoryRequirementsARM)load(context, "vkGetTensorMemoryRequirementsARM");
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer)
	vkGetTensorOpaqueCaptureDescriptorDataARM = (PFN_vkGetTensorOpaqueCaptureDescriptorDataARM)load(context, "vkGetTensorOpaqueCaptureDescriptorDataARM");
	vkGetTensorViewOpaqueCaptureDescriptorDataARM = (PFN_vkGetTensorViewOpaqueCaptureDescriptorDataARM)load(context, "vkGetTensorViewOpaqueCaptureDescriptorDataARM");
#endif /* defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
	vkCmdSetAttachmentFeedbackLoopEnableEXT = (PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT)load(context, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
#endif /* defined(VK_EXT_attachment_feedback_loop_dynamic_state) */
#if defined(VK_EXT_buffer_device_address)
	vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)load(context, "vkGetBufferDeviceAddressEXT");
#endif /* defined(VK_EXT_buffer_device_address) */
#if defined(VK_EXT_calibrated_timestamps)
	vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)load(context, "vkGetCalibratedTimestampsEXT");
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_color_write_enable)
	vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)load(context, "vkCmdSetColorWriteEnableEXT");
#endif /* defined(VK_EXT_color_write_enable) */
#if defined(VK_EXT_conditional_rendering)
	vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)load(context, "vkCmdBeginConditionalRenderingEXT");
	vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)load(context, "vkCmdEndConditionalRenderingEXT");
#endif /* defined(VK_EXT_conditional_rendering) */
#if defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3))
	vkCmdBeginCustomResolveEXT = (PFN_vkCmdBeginCustomResolveEXT)load(context, "vkCmdBeginCustomResolveEXT");
#endif /* defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3)) */
#if defined(VK_EXT_debug_marker)
	vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)load(context, "vkCmdDebugMarkerBeginEXT");
	vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)load(context, "vkCmdDebugMarkerEndEXT");
	vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)load(context, "vkCmdDebugMarkerInsertEXT");
	vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)load(context, "vkDebugMarkerSetObjectNameEXT");
	vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)load(context, "vkDebugMarkerSetObjectTagEXT");
#endif /* defined(VK_EXT_debug_marker) */
#if defined(VK_EXT_depth_bias_control)
	vkCmdSetDepthBias2EXT = (PFN_vkCmdSetDepthBias2EXT)load(context, "vkCmdSetDepthBias2EXT");
#endif /* defined(VK_EXT_depth_bias_control) */
#if defined(VK_EXT_descriptor_buffer)
	vkCmdBindDescriptorBufferEmbeddedSamplersEXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT)load(context, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
	vkCmdBindDescriptorBuffersEXT = (PFN_vkCmdBindDescriptorBuffersEXT)load(context, "vkCmdBindDescriptorBuffersEXT");
	vkCmdSetDescriptorBufferOffsetsEXT = (PFN_vkCmdSetDescriptorBufferOffsetsEXT)load(context, "vkCmdSetDescriptorBufferOffsetsEXT");
	vkGetBufferOpaqueCaptureDescriptorDataEXT = (PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT)load(context, "vkGetBufferOpaqueCaptureDescriptorDataEXT");
	vkGetDescriptorEXT = (PFN_vkGetDescriptorEXT)load(context, "vkGetDescriptorEXT");
	vkGetDescriptorSetLayoutBindingOffsetEXT = (PFN_vkGetDescriptorSetLayoutBindingOffsetEXT)load(context, "vkGetDescriptorSetLayoutBindingOffsetEXT");
	vkGetDescriptorSetLayoutSizeEXT = (PFN_vkGetDescriptorSetLayoutSizeEXT)load(context, "vkGetDescriptorSetLayoutSizeEXT");
	vkGetImageOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageOpaqueCaptureDescriptorDataEXT)load(context, "vkGetImageOpaqueCaptureDescriptorDataEXT");
	vkGetImageViewOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT)load(context, "vkGetImageViewOpaqueCaptureDescriptorDataEXT");
	vkGetSamplerOpaqueCaptureDescriptorDataEXT = (PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT)load(context, "vkGetSamplerOpaqueCaptureDescriptorDataEXT");
#endif /* defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing))
	vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = (PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT)load(context, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT");
#endif /* defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing)) */
#if defined(VK_EXT_device_fault)
	vkGetDeviceFaultInfoEXT = (PFN_vkGetDeviceFaultInfoEXT)load(context, "vkGetDeviceFaultInfoEXT");
#endif /* defined(VK_EXT_device_fault) */
#if defined(VK_EXT_device_generated_commands)
	vkCmdExecuteGeneratedCommandsEXT = (PFN_vkCmdExecuteGeneratedCommandsEXT)load(context, "vkCmdExecuteGeneratedCommandsEXT");
	vkCmdPreprocessGeneratedCommandsEXT = (PFN_vkCmdPreprocessGeneratedCommandsEXT)load(context, "vkCmdPreprocessGeneratedCommandsEXT");
	vkCreateIndirectCommandsLayoutEXT = (PFN_vkCreateIndirectCommandsLayoutEXT)load(context, "vkCreateIndirectCommandsLayoutEXT");
	vkCreateIndirectExecutionSetEXT = (PFN_vkCreateIndirectExecutionSetEXT)load(context, "vkCreateIndirectExecutionSetEXT");
	vkDestroyIndirectCommandsLayoutEXT = (PFN_vkDestroyIndirectCommandsLayoutEXT)load(context, "vkDestroyIndirectCommandsLayoutEXT");
	vkDestroyIndirectExecutionSetEXT = (PFN_vkDestroyIndirectExecutionSetEXT)load(context, "vkDestroyIndirectExecutionSetEXT");
	vkGetGeneratedCommandsMemoryRequirementsEXT = (PFN_vkGetGeneratedCommandsMemoryRequirementsEXT)load(context, "vkGetGeneratedCommandsMemoryRequirementsEXT");
	vkUpdateIndirectExecutionSetPipelineEXT = (PFN_vkUpdateIndirectExecutionSetPipelineEXT)load(context, "vkUpdateIndirectExecutionSetPipelineEXT");
	vkUpdateIndirectExecutionSetShaderEXT = (PFN_vkUpdateIndirectExecutionSetShaderEXT)load(context, "vkUpdateIndirectExecutionSetShaderEXT");
#endif /* defined(VK_EXT_device_generated_commands) */
#if defined(VK_EXT_discard_rectangles)
	vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)load(context, "vkCmdSetDiscardRectangleEXT");
#endif /* defined(VK_EXT_discard_rectangles) */
#if defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2
	vkCmdSetDiscardRectangleEnableEXT = (PFN_vkCmdSetDiscardRectangleEnableEXT)load(context, "vkCmdSetDiscardRectangleEnableEXT");
	vkCmdSetDiscardRectangleModeEXT = (PFN_vkCmdSetDiscardRectangleModeEXT)load(context, "vkCmdSetDiscardRectangleModeEXT");
#endif /* defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2 */
#if defined(VK_EXT_display_control)
	vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)load(context, "vkDisplayPowerControlEXT");
	vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)load(context, "vkGetSwapchainCounterEXT");
	vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)load(context, "vkRegisterDeviceEventEXT");
	vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)load(context, "vkRegisterDisplayEventEXT");
#endif /* defined(VK_EXT_display_control) */
#if defined(VK_EXT_external_memory_host)
	vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)load(context, "vkGetMemoryHostPointerPropertiesEXT");
#endif /* defined(VK_EXT_external_memory_host) */
#if defined(VK_EXT_external_memory_metal)
	vkGetMemoryMetalHandleEXT = (PFN_vkGetMemoryMetalHandleEXT)load(context, "vkGetMemoryMetalHandleEXT");
	vkGetMemoryMetalHandlePropertiesEXT = (PFN_vkGetMemoryMetalHandlePropertiesEXT)load(context, "vkGetMemoryMetalHandlePropertiesEXT");
#endif /* defined(VK_EXT_external_memory_metal) */
#if defined(VK_EXT_fragment_density_map_offset)
	vkCmdEndRendering2EXT = (PFN_vkCmdEndRendering2EXT)load(context, "vkCmdEndRendering2EXT");
#endif /* defined(VK_EXT_fragment_density_map_offset) */
#if defined(VK_EXT_full_screen_exclusive)
	vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)load(context, "vkAcquireFullScreenExclusiveModeEXT");
	vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)load(context, "vkReleaseFullScreenExclusiveModeEXT");
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1))
	vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)load(context, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif /* defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1)) */
#if defined(VK_EXT_hdr_metadata)
	vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)load(context, "vkSetHdrMetadataEXT");
#endif /* defined(VK_EXT_hdr_metadata) */
#if defined(VK_EXT_host_image_copy)
	vkCopyImageToImageEXT = (PFN_vkCopyImageToImageEXT)load(context, "vkCopyImageToImageEXT");
	vkCopyImageToMemoryEXT = (PFN_vkCopyImageToMemoryEXT)load(context, "vkCopyImageToMemoryEXT");
	vkCopyMemoryToImageEXT = (PFN_vkCopyMemoryToImageEXT)load(context, "vkCopyMemoryToImageEXT");
	vkTransitionImageLayoutEXT = (PFN_vkTransitionImageLayoutEXT)load(context, "vkTransitionImageLayoutEXT");
#endif /* defined(VK_EXT_host_image_copy) */
#if defined(VK_EXT_host_query_reset)
	vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)load(context, "vkResetQueryPoolEXT");
#endif /* defined(VK_EXT_host_query_reset) */
#if defined(VK_EXT_image_drm_format_modifier)
	vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)load(context, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif /* defined(VK_EXT_image_drm_format_modifier) */
#if defined(VK_EXT_line_rasterization)
	vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)load(context, "vkCmdSetLineStippleEXT");
#endif /* defined(VK_EXT_line_rasterization) */
#if defined(VK_EXT_memory_decompression)
	vkCmdDecompressMemoryEXT = (PFN_vkCmdDecompressMemoryEXT)load(context, "vkCmdDecompressMemoryEXT");
	vkCmdDecompressMemoryIndirectCountEXT = (PFN_vkCmdDecompressMemoryIndirectCountEXT)load(context, "vkCmdDecompressMemoryIndirectCountEXT");
#endif /* defined(VK_EXT_memory_decompression) */
#if defined(VK_EXT_mesh_shader)
	vkCmdDrawMeshTasksEXT = (PFN_vkCmdDrawMeshTasksEXT)load(context, "vkCmdDrawMeshTasksEXT");
	vkCmdDrawMeshTasksIndirectEXT = (PFN_vkCmdDrawMeshTasksIndirectEXT)load(context, "vkCmdDrawMeshTasksIndirectEXT");
#endif /* defined(VK_EXT_mesh_shader) */
#if defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
	vkCmdDrawMeshTasksIndirectCountEXT = (PFN_vkCmdDrawMeshTasksIndirectCountEXT)load(context, "vkCmdDrawMeshTasksIndirectCountEXT");
#endif /* defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_EXT_metal_objects)
	vkExportMetalObjectsEXT = (PFN_vkExportMetalObjectsEXT)load(context, "vkExportMetalObjectsEXT");
#endif /* defined(VK_EXT_metal_objects) */
#if defined(VK_EXT_multi_draw)
	vkCmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT)load(context, "vkCmdDrawMultiEXT");
	vkCmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT)load(context, "vkCmdDrawMultiIndexedEXT");
#endif /* defined(VK_EXT_multi_draw) */
#if defined(VK_EXT_opacity_micromap)
	vkBuildMicromapsEXT = (PFN_vkBuildMicromapsEXT)load(context, "vkBuildMicromapsEXT");
	vkCmdBuildMicromapsEXT = (PFN_vkCmdBuildMicromapsEXT)load(context, "vkCmdBuildMicromapsEXT");
	vkCmdCopyMemoryToMicromapEXT = (PFN_vkCmdCopyMemoryToMicromapEXT)load(context, "vkCmdCopyMemoryToMicromapEXT");
	vkCmdCopyMicromapEXT = (PFN_vkCmdCopyMicromapEXT)load(context, "vkCmdCopyMicromapEXT");
	vkCmdCopyMicromapToMemoryEXT = (PFN_vkCmdCopyMicromapToMemoryEXT)load(context, "vkCmdCopyMicromapToMemoryEXT");
	vkCmdWriteMicromapsPropertiesEXT = (PFN_vkCmdWriteMicromapsPropertiesEXT)load(context, "vkCmdWriteMicromapsPropertiesEXT");
	vkCopyMemoryToMicromapEXT = (PFN_vkCopyMemoryToMicromapEXT)load(context, "vkCopyMemoryToMicromapEXT");
	vkCopyMicromapEXT = (PFN_vkCopyMicromapEXT)load(context, "vkCopyMicromapEXT");
	vkCopyMicromapToMemoryEXT = (PFN_vkCopyMicromapToMemoryEXT)load(context, "vkCopyMicromapToMemoryEXT");
	vkCreateMicromapEXT = (PFN_vkCreateMicromapEXT)load(context, "vkCreateMicromapEXT");
	vkDestroyMicromapEXT = (PFN_vkDestroyMicromapEXT)load(context, "vkDestroyMicromapEXT");
	vkGetDeviceMicromapCompatibilityEXT = (PFN_vkGetDeviceMicromapCompatibilityEXT)load(context, "vkGetDeviceMicromapCompatibilityEXT");
	vkGetMicromapBuildSizesEXT = (PFN_vkGetMicromapBuildSizesEXT)load(context, "vkGetMicromapBuildSizesEXT");
	vkWriteMicromapsPropertiesEXT = (PFN_vkWriteMicromapsPropertiesEXT)load(context, "vkWriteMicromapsPropertiesEXT");
#endif /* defined(VK_EXT_opacity_micromap) */
#if defined(VK_EXT_pageable_device_local_memory)
	vkSetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT)load(context, "vkSetDeviceMemoryPriorityEXT");
#endif /* defined(VK_EXT_pageable_device_local_memory) */
#if defined(VK_EXT_pipeline_properties)
	vkGetPipelinePropertiesEXT = (PFN_vkGetPipelinePropertiesEXT)load(context, "vkGetPipelinePropertiesEXT");
#endif /* defined(VK_EXT_pipeline_properties) */
#if defined(VK_EXT_present_timing)
	vkGetPastPresentationTimingEXT = (PFN_vkGetPastPresentationTimingEXT)load(context, "vkGetPastPresentationTimingEXT");
	vkGetSwapchainTimeDomainPropertiesEXT = (PFN_vkGetSwapchainTimeDomainPropertiesEXT)load(context, "vkGetSwapchainTimeDomainPropertiesEXT");
	vkGetSwapchainTimingPropertiesEXT = (PFN_vkGetSwapchainTimingPropertiesEXT)load(context, "vkGetSwapchainTimingPropertiesEXT");
	vkSetSwapchainPresentTimingQueueSizeEXT = (PFN_vkSetSwapchainPresentTimingQueueSizeEXT)load(context, "vkSetSwapchainPresentTimingQueueSizeEXT");
#endif /* defined(VK_EXT_present_timing) */
#if defined(VK_EXT_private_data)
	vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)load(context, "vkCreatePrivateDataSlotEXT");
	vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)load(context, "vkDestroyPrivateDataSlotEXT");
	vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)load(context, "vkGetPrivateDataEXT");
	vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)load(context, "vkSetPrivateDataEXT");
#endif /* defined(VK_EXT_private_data) */
#if defined(VK_EXT_sample_locations)
	vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)load(context, "vkCmdSetSampleLocationsEXT");
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_shader_module_identifier)
	vkGetShaderModuleCreateInfoIdentifierEXT = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT)load(context, "vkGetShaderModuleCreateInfoIdentifierEXT");
	vkGetShaderModuleIdentifierEXT = (PFN_vkGetShaderModuleIdentifierEXT)load(context, "vkGetShaderModuleIdentifierEXT");
#endif /* defined(VK_EXT_shader_module_identifier) */
#if defined(VK_EXT_shader_object)
	vkCmdBindShadersEXT = (PFN_vkCmdBindShadersEXT)load(context, "vkCmdBindShadersEXT");
	vkCreateShadersEXT = (PFN_vkCreateShadersEXT)load(context, "vkCreateShadersEXT");
	vkDestroyShaderEXT = (PFN_vkDestroyShaderEXT)load(context, "vkDestroyShaderEXT");
	vkGetShaderBinaryDataEXT = (PFN_vkGetShaderBinaryDataEXT)load(context, "vkGetShaderBinaryDataEXT");
#endif /* defined(VK_EXT_shader_object) */
#if defined(VK_EXT_swapchain_maintenance1)
	vkReleaseSwapchainImagesEXT = (PFN_vkReleaseSwapchainImagesEXT)load(context, "vkReleaseSwapchainImagesEXT");
#endif /* defined(VK_EXT_swapchain_maintenance1) */
#if defined(VK_EXT_transform_feedback)
	vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)load(context, "vkCmdBeginQueryIndexedEXT");
	vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)load(context, "vkCmdBeginTransformFeedbackEXT");
	vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)load(context, "vkCmdBindTransformFeedbackBuffersEXT");
	vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)load(context, "vkCmdDrawIndirectByteCountEXT");
	vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)load(context, "vkCmdEndQueryIndexedEXT");
	vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)load(context, "vkCmdEndTransformFeedbackEXT");
#endif /* defined(VK_EXT_transform_feedback) */
#if defined(VK_EXT_validation_cache)
	vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)load(context, "vkCreateValidationCacheEXT");
	vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)load(context, "vkDestroyValidationCacheEXT");
	vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)load(context, "vkGetValidationCacheDataEXT");
	vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)load(context, "vkMergeValidationCachesEXT");
#endif /* defined(VK_EXT_validation_cache) */
#if defined(VK_FUCHSIA_buffer_collection)
	vkCreateBufferCollectionFUCHSIA = (PFN_vkCreateBufferCollectionFUCHSIA)load(context, "vkCreateBufferCollectionFUCHSIA");
	vkDestroyBufferCollectionFUCHSIA = (PFN_vkDestroyBufferCollectionFUCHSIA)load(context, "vkDestroyBufferCollectionFUCHSIA");
	vkGetBufferCollectionPropertiesFUCHSIA = (PFN_vkGetBufferCollectionPropertiesFUCHSIA)load(context, "vkGetBufferCollectionPropertiesFUCHSIA");
	vkSetBufferCollectionBufferConstraintsFUCHSIA = (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)load(context, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
	vkSetBufferCollectionImageConstraintsFUCHSIA = (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)load(context, "vkSetBufferCollectionImageConstraintsFUCHSIA");
#endif /* defined(VK_FUCHSIA_buffer_collection) */
#if defined(VK_FUCHSIA_external_memory)
	vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)load(context, "vkGetMemoryZirconHandleFUCHSIA");
	vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)load(context, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif /* defined(VK_FUCHSIA_external_memory) */
#if defined(VK_FUCHSIA_external_semaphore)
	vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)load(context, "vkGetSemaphoreZirconHandleFUCHSIA");
	vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)load(context, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif /* defined(VK_FUCHSIA_external_semaphore) */
#if defined(VK_GOOGLE_display_timing)
	vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)load(context, "vkGetPastPresentationTimingGOOGLE");
	vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)load(context, "vkGetRefreshCycleDurationGOOGLE");
#endif /* defined(VK_GOOGLE_display_timing) */
#if defined(VK_HUAWEI_cluster_culling_shader)
	vkCmdDrawClusterHUAWEI = (PFN_vkCmdDrawClusterHUAWEI)load(context, "vkCmdDrawClusterHUAWEI");
	vkCmdDrawClusterIndirectHUAWEI = (PFN_vkCmdDrawClusterIndirectHUAWEI)load(context, "vkCmdDrawClusterIndirectHUAWEI");
#endif /* defined(VK_HUAWEI_cluster_culling_shader) */
#if defined(VK_HUAWEI_invocation_mask)
	vkCmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI)load(context, "vkCmdBindInvocationMaskHUAWEI");
#endif /* defined(VK_HUAWEI_invocation_mask) */
#if defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2
	vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = (PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI)load(context, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI");
#endif /* defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2 */
#if defined(VK_HUAWEI_subpass_shading)
	vkCmdSubpassShadingHUAWEI = (PFN_vkCmdSubpassShadingHUAWEI)load(context, "vkCmdSubpassShadingHUAWEI");
#endif /* defined(VK_HUAWEI_subpass_shading) */
#if defined(VK_INTEL_performance_query)
	vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)load(context, "vkAcquirePerformanceConfigurationINTEL");
	vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)load(context, "vkCmdSetPerformanceMarkerINTEL");
	vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)load(context, "vkCmdSetPerformanceOverrideINTEL");
	vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)load(context, "vkCmdSetPerformanceStreamMarkerINTEL");
	vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)load(context, "vkGetPerformanceParameterINTEL");
	vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)load(context, "vkInitializePerformanceApiINTEL");
	vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)load(context, "vkQueueSetPerformanceConfigurationINTEL");
	vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)load(context, "vkReleasePerformanceConfigurationINTEL");
	vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)load(context, "vkUninitializePerformanceApiINTEL");
#endif /* defined(VK_INTEL_performance_query) */
#if defined(VK_KHR_acceleration_structure)
	vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)load(context, "vkBuildAccelerationStructuresKHR");
	vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)load(context, "vkCmdBuildAccelerationStructuresIndirectKHR");
	vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)load(context, "vkCmdBuildAccelerationStructuresKHR");
	vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)load(context, "vkCmdCopyAccelerationStructureKHR");
	vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)load(context, "vkCmdCopyAccelerationStructureToMemoryKHR");
	vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)load(context, "vkCmdCopyMemoryToAccelerationStructureKHR");
	vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)load(context, "vkCmdWriteAccelerationStructuresPropertiesKHR");
	vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)load(context, "vkCopyAccelerationStructureKHR");
	vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)load(context, "vkCopyAccelerationStructureToMemoryKHR");
	vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)load(context, "vkCopyMemoryToAccelerationStructureKHR");
	vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)load(context, "vkCreateAccelerationStructureKHR");
	vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)load(context, "vkDestroyAccelerationStructureKHR");
	vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)load(context, "vkGetAccelerationStructureBuildSizesKHR");
	vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)load(context, "vkGetAccelerationStructureDeviceAddressKHR");
	vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)load(context, "vkGetDeviceAccelerationStructureCompatibilityKHR");
	vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)load(context, "vkWriteAccelerationStructuresPropertiesKHR");
#endif /* defined(VK_KHR_acceleration_structure) */
#if defined(VK_KHR_bind_memory2)
	vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)load(context, "vkBindBufferMemory2KHR");
	vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)load(context, "vkBindImageMemory2KHR");
#endif /* defined(VK_KHR_bind_memory2) */
#if defined(VK_KHR_buffer_device_address)
	vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)load(context, "vkGetBufferDeviceAddressKHR");
	vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)load(context, "vkGetBufferOpaqueCaptureAddressKHR");
	vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)load(context, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif /* defined(VK_KHR_buffer_device_address) */
#if defined(VK_KHR_calibrated_timestamps)
	vkGetCalibratedTimestampsKHR = (PFN_vkGetCalibratedTimestampsKHR)load(context, "vkGetCalibratedTimestampsKHR");
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_copy_commands2)
	vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)load(context, "vkCmdBlitImage2KHR");
	vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)load(context, "vkCmdCopyBuffer2KHR");
	vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)load(context, "vkCmdCopyBufferToImage2KHR");
	vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)load(context, "vkCmdCopyImage2KHR");
	vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)load(context, "vkCmdCopyImageToBuffer2KHR");
	vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)load(context, "vkCmdResolveImage2KHR");
#endif /* defined(VK_KHR_copy_commands2) */
#if defined(VK_KHR_copy_memory_indirect)
	vkCmdCopyMemoryIndirectKHR = (PFN_vkCmdCopyMemoryIndirectKHR)load(context, "vkCmdCopyMemoryIndirectKHR");
	vkCmdCopyMemoryToImageIndirectKHR = (PFN_vkCmdCopyMemoryToImageIndirectKHR)load(context, "vkCmdCopyMemoryToImageIndirectKHR");
#endif /* defined(VK_KHR_copy_memory_indirect) */
#if defined(VK_KHR_create_renderpass2)
	vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)load(context, "vkCmdBeginRenderPass2KHR");
	vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)load(context, "vkCmdEndRenderPass2KHR");
	vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)load(context, "vkCmdNextSubpass2KHR");
	vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)load(context, "vkCreateRenderPass2KHR");
#endif /* defined(VK_KHR_create_renderpass2) */
#if defined(VK_KHR_deferred_host_operations)
	vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)load(context, "vkCreateDeferredOperationKHR");
	vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)load(context, "vkDeferredOperationJoinKHR");
	vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)load(context, "vkDestroyDeferredOperationKHR");
	vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)load(context, "vkGetDeferredOperationMaxConcurrencyKHR");
	vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)load(context, "vkGetDeferredOperationResultKHR");
#endif /* defined(VK_KHR_deferred_host_operations) */
#if defined(VK_KHR_descriptor_update_template)
	vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)load(context, "vkCreateDescriptorUpdateTemplateKHR");
	vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)load(context, "vkDestroyDescriptorUpdateTemplateKHR");
	vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)load(context, "vkUpdateDescriptorSetWithTemplateKHR");
#endif /* defined(VK_KHR_descriptor_update_template) */
#if defined(VK_KHR_device_group)
	vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)load(context, "vkCmdDispatchBaseKHR");
	vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)load(context, "vkCmdSetDeviceMaskKHR");
	vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)load(context, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif /* defined(VK_KHR_device_group) */
#if defined(VK_KHR_display_swapchain)
	vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)load(context, "vkCreateSharedSwapchainsKHR");
#endif /* defined(VK_KHR_display_swapchain) */
#if defined(VK_KHR_draw_indirect_count)
	vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)load(context, "vkCmdDrawIndexedIndirectCountKHR");
	vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)load(context, "vkCmdDrawIndirectCountKHR");
#endif /* defined(VK_KHR_draw_indirect_count) */
#if defined(VK_KHR_dynamic_rendering)
	vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR)load(context, "vkCmdBeginRenderingKHR");
	vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR)load(context, "vkCmdEndRenderingKHR");
#endif /* defined(VK_KHR_dynamic_rendering) */
#if defined(VK_KHR_dynamic_rendering_local_read)
	vkCmdSetRenderingAttachmentLocationsKHR = (PFN_vkCmdSetRenderingAttachmentLocationsKHR)load(context, "vkCmdSetRenderingAttachmentLocationsKHR");
	vkCmdSetRenderingInputAttachmentIndicesKHR = (PFN_vkCmdSetRenderingInputAttachmentIndicesKHR)load(context, "vkCmdSetRenderingInputAttachmentIndicesKHR");
#endif /* defined(VK_KHR_dynamic_rendering_local_read) */
#if defined(VK_KHR_external_fence_fd)
	vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)load(context, "vkGetFenceFdKHR");
	vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)load(context, "vkImportFenceFdKHR");
#endif /* defined(VK_KHR_external_fence_fd) */
#if defined(VK_KHR_external_fence_win32)
	vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)load(context, "vkGetFenceWin32HandleKHR");
	vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)load(context, "vkImportFenceWin32HandleKHR");
#endif /* defined(VK_KHR_external_fence_win32) */
#if defined(VK_KHR_external_memory_fd)
	vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)load(context, "vkGetMemoryFdKHR");
	vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)load(context, "vkGetMemoryFdPropertiesKHR");
#endif /* defined(VK_KHR_external_memory_fd) */
#if defined(VK_KHR_external_memory_win32)
	vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)load(context, "vkGetMemoryWin32HandleKHR");
	vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)load(context, "vkGetMemoryWin32HandlePropertiesKHR");
#endif /* defined(VK_KHR_external_memory_win32) */
#if defined(VK_KHR_external_semaphore_fd)
	vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)load(context, "vkGetSemaphoreFdKHR");
	vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)load(context, "vkImportSemaphoreFdKHR");
#endif /* defined(VK_KHR_external_semaphore_fd) */
#if defined(VK_KHR_external_semaphore_win32)
	vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)load(context, "vkGetSemaphoreWin32HandleKHR");
	vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)load(context, "vkImportSemaphoreWin32HandleKHR");
#endif /* defined(VK_KHR_external_semaphore_win32) */
#if defined(VK_KHR_fragment_shading_rate)
	vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)load(context, "vkCmdSetFragmentShadingRateKHR");
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_memory_requirements2)
	vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)load(context, "vkGetBufferMemoryRequirements2KHR");
	vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)load(context, "vkGetImageMemoryRequirements2KHR");
	vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)load(context, "vkGetImageSparseMemoryRequirements2KHR");
#endif /* defined(VK_KHR_get_memory_requirements2) */
#if defined(VK_KHR_line_rasterization)
	vkCmdSetLineStippleKHR = (PFN_vkCmdSetLineStippleKHR)load(context, "vkCmdSetLineStippleKHR");
#endif /* defined(VK_KHR_line_rasterization) */
#if defined(VK_KHR_maintenance1)
	vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)load(context, "vkTrimCommandPoolKHR");
#endif /* defined(VK_KHR_maintenance1) */
#if defined(VK_KHR_maintenance10)
	vkCmdEndRendering2KHR = (PFN_vkCmdEndRendering2KHR)load(context, "vkCmdEndRendering2KHR");
#endif /* defined(VK_KHR_maintenance10) */
#if defined(VK_KHR_maintenance3)
	vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)load(context, "vkGetDescriptorSetLayoutSupportKHR");
#endif /* defined(VK_KHR_maintenance3) */
#if defined(VK_KHR_maintenance4)
	vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR)load(context, "vkGetDeviceBufferMemoryRequirementsKHR");
	vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR)load(context, "vkGetDeviceImageMemoryRequirementsKHR");
	vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR)load(context, "vkGetDeviceImageSparseMemoryRequirementsKHR");
#endif /* defined(VK_KHR_maintenance4) */
#if defined(VK_KHR_maintenance5)
	vkCmdBindIndexBuffer2KHR = (PFN_vkCmdBindIndexBuffer2KHR)load(context, "vkCmdBindIndexBuffer2KHR");
	vkGetDeviceImageSubresourceLayoutKHR = (PFN_vkGetDeviceImageSubresourceLayoutKHR)load(context, "vkGetDeviceImageSubresourceLayoutKHR");
	vkGetImageSubresourceLayout2KHR = (PFN_vkGetImageSubresourceLayout2KHR)load(context, "vkGetImageSubresourceLayout2KHR");
	vkGetRenderingAreaGranularityKHR = (PFN_vkGetRenderingAreaGranularityKHR)load(context, "vkGetRenderingAreaGranularityKHR");
#endif /* defined(VK_KHR_maintenance5) */
#if defined(VK_KHR_maintenance6)
	vkCmdBindDescriptorSets2KHR = (PFN_vkCmdBindDescriptorSets2KHR)load(context, "vkCmdBindDescriptorSets2KHR");
	vkCmdPushConstants2KHR = (PFN_vkCmdPushConstants2KHR)load(context, "vkCmdPushConstants2KHR");
#endif /* defined(VK_KHR_maintenance6) */
#if defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor)
	vkCmdPushDescriptorSet2KHR = (PFN_vkCmdPushDescriptorSet2KHR)load(context, "vkCmdPushDescriptorSet2KHR");
	vkCmdPushDescriptorSetWithTemplate2KHR = (PFN_vkCmdPushDescriptorSetWithTemplate2KHR)load(context, "vkCmdPushDescriptorSetWithTemplate2KHR");
#endif /* defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer)
	vkCmdBindDescriptorBufferEmbeddedSamplers2EXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT)load(context, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
	vkCmdSetDescriptorBufferOffsets2EXT = (PFN_vkCmdSetDescriptorBufferOffsets2EXT)load(context, "vkCmdSetDescriptorBufferOffsets2EXT");
#endif /* defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_KHR_map_memory2)
	vkMapMemory2KHR = (PFN_vkMapMemory2KHR)load(context, "vkMapMemory2KHR");
	vkUnmapMemory2KHR = (PFN_vkUnmapMemory2KHR)load(context, "vkUnmapMemory2KHR");
#endif /* defined(VK_KHR_map_memory2) */
#if defined(VK_KHR_performance_query)
	vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)load(context, "vkAcquireProfilingLockKHR");
	vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)load(context, "vkReleaseProfilingLockKHR");
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_pipeline_binary)
	vkCreatePipelineBinariesKHR = (PFN_vkCreatePipelineBinariesKHR)load(context, "vkCreatePipelineBinariesKHR");
	vkDestroyPipelineBinaryKHR = (PFN_vkDestroyPipelineBinaryKHR)load(context, "vkDestroyPipelineBinaryKHR");
	vkGetPipelineBinaryDataKHR = (PFN_vkGetPipelineBinaryDataKHR)load(context, "vkGetPipelineBinaryDataKHR");
	vkGetPipelineKeyKHR = (PFN_vkGetPipelineKeyKHR)load(context, "vkGetPipelineKeyKHR");
	vkReleaseCapturedPipelineDataKHR = (PFN_vkReleaseCapturedPipelineDataKHR)load(context, "vkReleaseCapturedPipelineDataKHR");
#endif /* defined(VK_KHR_pipeline_binary) */
#if defined(VK_KHR_pipeline_executable_properties)
	vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)load(context, "vkGetPipelineExecutableInternalRepresentationsKHR");
	vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)load(context, "vkGetPipelineExecutablePropertiesKHR");
	vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)load(context, "vkGetPipelineExecutableStatisticsKHR");
#endif /* defined(VK_KHR_pipeline_executable_properties) */
#if defined(VK_KHR_present_wait)
	vkWaitForPresentKHR = (PFN_vkWaitForPresentKHR)load(context, "vkWaitForPresentKHR");
#endif /* defined(VK_KHR_present_wait) */
#if defined(VK_KHR_present_wait2)
	vkWaitForPresent2KHR = (PFN_vkWaitForPresent2KHR)load(context, "vkWaitForPresent2KHR");
#endif /* defined(VK_KHR_present_wait2) */
#if defined(VK_KHR_push_descriptor)
	vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)load(context, "vkCmdPushDescriptorSetKHR");
#endif /* defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
	vkCmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR)load(context, "vkCmdTraceRaysIndirect2KHR");
#endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_ray_tracing_pipeline)
	vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)load(context, "vkCmdSetRayTracingPipelineStackSizeKHR");
	vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)load(context, "vkCmdTraceRaysIndirectKHR");
	vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)load(context, "vkCmdTraceRaysKHR");
	vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)load(context, "vkCreateRayTracingPipelinesKHR");
	vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)load(context, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
	vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)load(context, "vkGetRayTracingShaderGroupHandlesKHR");
	vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)load(context, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif /* defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_sampler_ycbcr_conversion)
	vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)load(context, "vkCreateSamplerYcbcrConversionKHR");
	vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)load(context, "vkDestroySamplerYcbcrConversionKHR");
#endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
#if defined(VK_KHR_shared_presentable_image)
	vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)load(context, "vkGetSwapchainStatusKHR");
#endif /* defined(VK_KHR_shared_presentable_image) */
#if defined(VK_KHR_swapchain)
	vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)load(context, "vkAcquireNextImageKHR");
	vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)load(context, "vkCreateSwapchainKHR");
	vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)load(context, "vkDestroySwapchainKHR");
	vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)load(context, "vkGetSwapchainImagesKHR");
	vkQueuePresentKHR = (PFN_vkQueuePresentKHR)load(context, "vkQueuePresentKHR");
#endif /* defined(VK_KHR_swapchain) */
#if defined(VK_KHR_swapchain_maintenance1)
	vkReleaseSwapchainImagesKHR = (PFN_vkReleaseSwapchainImagesKHR)load(context, "vkReleaseSwapchainImagesKHR");
#endif /* defined(VK_KHR_swapchain_maintenance1) */
#if defined(VK_KHR_synchronization2)
	vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)load(context, "vkCmdPipelineBarrier2KHR");
	vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)load(context, "vkCmdResetEvent2KHR");
	vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)load(context, "vkCmdSetEvent2KHR");
	vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)load(context, "vkCmdWaitEvents2KHR");
	vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)load(context, "vkCmdWriteTimestamp2KHR");
	vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)load(context, "vkQueueSubmit2KHR");
#endif /* defined(VK_KHR_synchronization2) */
#if defined(VK_KHR_timeline_semaphore)
	vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)load(context, "vkGetSemaphoreCounterValueKHR");
	vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)load(context, "vkSignalSemaphoreKHR");
	vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)load(context, "vkWaitSemaphoresKHR");
#endif /* defined(VK_KHR_timeline_semaphore) */
#if defined(VK_KHR_video_decode_queue)
	vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)load(context, "vkCmdDecodeVideoKHR");
#endif /* defined(VK_KHR_video_decode_queue) */
#if defined(VK_KHR_video_encode_queue)
	vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)load(context, "vkCmdEncodeVideoKHR");
	vkGetEncodedVideoSessionParametersKHR = (PFN_vkGetEncodedVideoSessionParametersKHR)load(context, "vkGetEncodedVideoSessionParametersKHR");
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
	vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)load(context, "vkBindVideoSessionMemoryKHR");
	vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)load(context, "vkCmdBeginVideoCodingKHR");
	vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)load(context, "vkCmdControlVideoCodingKHR");
	vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)load(context, "vkCmdEndVideoCodingKHR");
	vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)load(context, "vkCreateVideoSessionKHR");
	vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)load(context, "vkCreateVideoSessionParametersKHR");
	vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)load(context, "vkDestroyVideoSessionKHR");
	vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)load(context, "vkDestroyVideoSessionParametersKHR");
	vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)load(context, "vkGetVideoSessionMemoryRequirementsKHR");
	vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)load(context, "vkUpdateVideoSessionParametersKHR");
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_NVX_binary_import)
	vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)load(context, "vkCmdCuLaunchKernelNVX");
	vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)load(context, "vkCreateCuFunctionNVX");
	vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)load(context, "vkCreateCuModuleNVX");
	vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)load(context, "vkDestroyCuFunctionNVX");
	vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)load(context, "vkDestroyCuModuleNVX");
#endif /* defined(VK_NVX_binary_import) */
#if defined(VK_NVX_image_view_handle)
	vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)load(context, "vkGetImageViewHandleNVX");
#endif /* defined(VK_NVX_image_view_handle) */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3
	vkGetImageViewHandle64NVX = (PFN_vkGetImageViewHandle64NVX)load(context, "vkGetImageViewHandle64NVX");
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3 */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2
	vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)load(context, "vkGetImageViewAddressNVX");
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2 */
#if defined(VK_NV_clip_space_w_scaling)
	vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)load(context, "vkCmdSetViewportWScalingNV");
#endif /* defined(VK_NV_clip_space_w_scaling) */
#if defined(VK_NV_cluster_acceleration_structure)
	vkCmdBuildClusterAccelerationStructureIndirectNV = (PFN_vkCmdBuildClusterAccelerationStructureIndirectNV)load(context, "vkCmdBuildClusterAccelerationStructureIndirectNV");
	vkGetClusterAccelerationStructureBuildSizesNV = (PFN_vkGetClusterAccelerationStructureBuildSizesNV)load(context, "vkGetClusterAccelerationStructureBuildSizesNV");
#endif /* defined(VK_NV_cluster_acceleration_structure) */
#if defined(VK_NV_compute_occupancy_priority)
	vkCmdSetComputeOccupancyPriorityNV = (PFN_vkCmdSetComputeOccupancyPriorityNV)load(context, "vkCmdSetComputeOccupancyPriorityNV");
#endif /* defined(VK_NV_compute_occupancy_priority) */
#if defined(VK_NV_cooperative_vector)
	vkCmdConvertCooperativeVectorMatrixNV = (PFN_vkCmdConvertCooperativeVectorMatrixNV)load(context, "vkCmdConvertCooperativeVectorMatrixNV");
	vkConvertCooperativeVectorMatrixNV = (PFN_vkConvertCooperativeVectorMatrixNV)load(context, "vkConvertCooperativeVectorMatrixNV");
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_copy_memory_indirect)
	vkCmdCopyMemoryIndirectNV = (PFN_vkCmdCopyMemoryIndirectNV)load(context, "vkCmdCopyMemoryIndirectNV");
	vkCmdCopyMemoryToImageIndirectNV = (PFN_vkCmdCopyMemoryToImageIndirectNV)load(context, "vkCmdCopyMemoryToImageIndirectNV");
#endif /* defined(VK_NV_copy_memory_indirect) */
#if defined(VK_NV_cuda_kernel_launch)
	vkCmdCudaLaunchKernelNV = (PFN_vkCmdCudaLaunchKernelNV)load(context, "vkCmdCudaLaunchKernelNV");
	vkCreateCudaFunctionNV = (PFN_vkCreateCudaFunctionNV)load(context, "vkCreateCudaFunctionNV");
	vkCreateCudaModuleNV = (PFN_vkCreateCudaModuleNV)load(context, "vkCreateCudaModuleNV");
	vkDestroyCudaFunctionNV = (PFN_vkDestroyCudaFunctionNV)load(context, "vkDestroyCudaFunctionNV");
	vkDestroyCudaModuleNV = (PFN_vkDestroyCudaModuleNV)load(context, "vkDestroyCudaModuleNV");
	vkGetCudaModuleCacheNV = (PFN_vkGetCudaModuleCacheNV)load(context, "vkGetCudaModuleCacheNV");
#endif /* defined(VK_NV_cuda_kernel_launch) */
#if defined(VK_NV_device_diagnostic_checkpoints)
	vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)load(context, "vkCmdSetCheckpointNV");
	vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)load(context, "vkGetQueueCheckpointDataNV");
#endif /* defined(VK_NV_device_diagnostic_checkpoints) */
#if defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
	vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)load(context, "vkGetQueueCheckpointData2NV");
#endif /* defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_NV_device_generated_commands)
	vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)load(context, "vkCmdBindPipelineShaderGroupNV");
	vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)load(context, "vkCmdExecuteGeneratedCommandsNV");
	vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)load(context, "vkCmdPreprocessGeneratedCommandsNV");
	vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)load(context, "vkCreateIndirectCommandsLayoutNV");
	vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)load(context, "vkDestroyIndirectCommandsLayoutNV");
	vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)load(context, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif /* defined(VK_NV_device_generated_commands) */
#if defined(VK_NV_device_generated_commands_compute)
	vkCmdUpdatePipelineIndirectBufferNV = (PFN_vkCmdUpdatePipelineIndirectBufferNV)load(context, "vkCmdUpdatePipelineIndirectBufferNV");
	vkGetPipelineIndirectDeviceAddressNV = (PFN_vkGetPipelineIndirectDeviceAddressNV)load(context, "vkGetPipelineIndirectDeviceAddressNV");
	vkGetPipelineIndirectMemoryRequirementsNV = (PFN_vkGetPipelineIndirectMemoryRequirementsNV)load(context, "vkGetPipelineIndirectMemoryRequirementsNV");
#endif /* defined(VK_NV_device_generated_commands_compute) */
#if defined(VK_NV_external_compute_queue)
	vkCreateExternalComputeQueueNV = (PFN_vkCreateExternalComputeQueueNV)load(context, "vkCreateExternalComputeQueueNV");
	vkDestroyExternalComputeQueueNV = (PFN_vkDestroyExternalComputeQueueNV)load(context, "vkDestroyExternalComputeQueueNV");
	vkGetExternalComputeQueueDataNV = (PFN_vkGetExternalComputeQueueDataNV)load(context, "vkGetExternalComputeQueueDataNV");
#endif /* defined(VK_NV_external_compute_queue) */
#if defined(VK_NV_external_memory_rdma)
	vkGetMemoryRemoteAddressNV = (PFN_vkGetMemoryRemoteAddressNV)load(context, "vkGetMemoryRemoteAddressNV");
#endif /* defined(VK_NV_external_memory_rdma) */
#if defined(VK_NV_external_memory_win32)
	vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)load(context, "vkGetMemoryWin32HandleNV");
#endif /* defined(VK_NV_external_memory_win32) */
#if defined(VK_NV_fragment_shading_rate_enums)
	vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)load(context, "vkCmdSetFragmentShadingRateEnumNV");
#endif /* defined(VK_NV_fragment_shading_rate_enums) */
#if defined(VK_NV_low_latency2)
	vkGetLatencyTimingsNV = (PFN_vkGetLatencyTimingsNV)load(context, "vkGetLatencyTimingsNV");
	vkLatencySleepNV = (PFN_vkLatencySleepNV)load(context, "vkLatencySleepNV");
	vkQueueNotifyOutOfBandNV = (PFN_vkQueueNotifyOutOfBandNV)load(context, "vkQueueNotifyOutOfBandNV");
	vkSetLatencyMarkerNV = (PFN_vkSetLatencyMarkerNV)load(context, "vkSetLatencyMarkerNV");
	vkSetLatencySleepModeNV = (PFN_vkSetLatencySleepModeNV)load(context, "vkSetLatencySleepModeNV");
#endif /* defined(VK_NV_low_latency2) */
#if defined(VK_NV_memory_decompression)
	vkCmdDecompressMemoryIndirectCountNV = (PFN_vkCmdDecompressMemoryIndirectCountNV)load(context, "vkCmdDecompressMemoryIndirectCountNV");
	vkCmdDecompressMemoryNV = (PFN_vkCmdDecompressMemoryNV)load(context, "vkCmdDecompressMemoryNV");
#endif /* defined(VK_NV_memory_decompression) */
#if defined(VK_NV_mesh_shader)
	vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)load(context, "vkCmdDrawMeshTasksIndirectNV");
	vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)load(context, "vkCmdDrawMeshTasksNV");
#endif /* defined(VK_NV_mesh_shader) */
#if defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
	vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)load(context, "vkCmdDrawMeshTasksIndirectCountNV");
#endif /* defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_NV_optical_flow)
	vkBindOpticalFlowSessionImageNV = (PFN_vkBindOpticalFlowSessionImageNV)load(context, "vkBindOpticalFlowSessionImageNV");
	vkCmdOpticalFlowExecuteNV = (PFN_vkCmdOpticalFlowExecuteNV)load(context, "vkCmdOpticalFlowExecuteNV");
	vkCreateOpticalFlowSessionNV = (PFN_vkCreateOpticalFlowSessionNV)load(context, "vkCreateOpticalFlowSessionNV");
	vkDestroyOpticalFlowSessionNV = (PFN_vkDestroyOpticalFlowSessionNV)load(context, "vkDestroyOpticalFlowSessionNV");
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_NV_partitioned_acceleration_structure)
	vkCmdBuildPartitionedAccelerationStructuresNV = (PFN_vkCmdBuildPartitionedAccelerationStructuresNV)load(context, "vkCmdBuildPartitionedAccelerationStructuresNV");
	vkGetPartitionedAccelerationStructuresBuildSizesNV = (PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV)load(context, "vkGetPartitionedAccelerationStructuresBuildSizesNV");
#endif /* defined(VK_NV_partitioned_acceleration_structure) */
#if defined(VK_NV_ray_tracing)
	vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)load(context, "vkBindAccelerationStructureMemoryNV");
	vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)load(context, "vkCmdBuildAccelerationStructureNV");
	vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)load(context, "vkCmdCopyAccelerationStructureNV");
	vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)load(context, "vkCmdTraceRaysNV");
	vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)load(context, "vkCmdWriteAccelerationStructuresPropertiesNV");
	vkCompileDeferredNV = (PFN_vkCompileDeferredNV)load(context, "vkCompileDeferredNV");
	vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)load(context, "vkCreateAccelerationStructureNV");
	vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)load(context, "vkCreateRayTracingPipelinesNV");
	vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)load(context, "vkDestroyAccelerationStructureNV");
	vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)load(context, "vkGetAccelerationStructureHandleNV");
	vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)load(context, "vkGetAccelerationStructureMemoryRequirementsNV");
	vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)load(context, "vkGetRayTracingShaderGroupHandlesNV");
#endif /* defined(VK_NV_ray_tracing) */
#if defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2
	vkCmdSetExclusiveScissorEnableNV = (PFN_vkCmdSetExclusiveScissorEnableNV)load(context, "vkCmdSetExclusiveScissorEnableNV");
#endif /* defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2 */
#if defined(VK_NV_scissor_exclusive)
	vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)load(context, "vkCmdSetExclusiveScissorNV");
#endif /* defined(VK_NV_scissor_exclusive) */
#if defined(VK_NV_shading_rate_image)
	vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)load(context, "vkCmdBindShadingRateImageNV");
	vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)load(context, "vkCmdSetCoarseSampleOrderNV");
	vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)load(context, "vkCmdSetViewportShadingRatePaletteNV");
#endif /* defined(VK_NV_shading_rate_image) */
#if defined(VK_OHOS_external_memory)
	vkGetMemoryNativeBufferOHOS = (PFN_vkGetMemoryNativeBufferOHOS)load(context, "vkGetMemoryNativeBufferOHOS");
	vkGetNativeBufferPropertiesOHOS = (PFN_vkGetNativeBufferPropertiesOHOS)load(context, "vkGetNativeBufferPropertiesOHOS");
#endif /* defined(VK_OHOS_external_memory) */
#if defined(VK_QCOM_tile_memory_heap)
	vkCmdBindTileMemoryQCOM = (PFN_vkCmdBindTileMemoryQCOM)load(context, "vkCmdBindTileMemoryQCOM");
#endif /* defined(VK_QCOM_tile_memory_heap) */
#if defined(VK_QCOM_tile_properties)
	vkGetDynamicRenderingTilePropertiesQCOM = (PFN_vkGetDynamicRenderingTilePropertiesQCOM)load(context, "vkGetDynamicRenderingTilePropertiesQCOM");
	vkGetFramebufferTilePropertiesQCOM = (PFN_vkGetFramebufferTilePropertiesQCOM)load(context, "vkGetFramebufferTilePropertiesQCOM");
#endif /* defined(VK_QCOM_tile_properties) */
#if defined(VK_QCOM_tile_shading)
	vkCmdBeginPerTileExecutionQCOM = (PFN_vkCmdBeginPerTileExecutionQCOM)load(context, "vkCmdBeginPerTileExecutionQCOM");
	vkCmdDispatchTileQCOM = (PFN_vkCmdDispatchTileQCOM)load(context, "vkCmdDispatchTileQCOM");
	vkCmdEndPerTileExecutionQCOM = (PFN_vkCmdEndPerTileExecutionQCOM)load(context, "vkCmdEndPerTileExecutionQCOM");
#endif /* defined(VK_QCOM_tile_shading) */
#if defined(VK_QNX_external_memory_screen_buffer)
	vkGetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX)load(context, "vkGetScreenBufferPropertiesQNX");
#endif /* defined(VK_QNX_external_memory_screen_buffer) */
#if defined(VK_VALVE_descriptor_set_host_mapping)
	vkGetDescriptorSetHostMappingVALVE = (PFN_vkGetDescriptorSetHostMappingVALVE)load(context, "vkGetDescriptorSetHostMappingVALVE");
	vkGetDescriptorSetLayoutHostMappingInfoVALVE = (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE)load(context, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
#endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
#if (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control))
	vkCmdSetDepthClampRangeEXT = (PFN_vkCmdSetDepthClampRangeEXT)load(context, "vkCmdSetDepthClampRangeEXT");
#endif /* (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control)) */
#if (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object))
	vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)load(context, "vkCmdBindVertexBuffers2EXT");
	vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)load(context, "vkCmdSetCullModeEXT");
	vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)load(context, "vkCmdSetDepthBoundsTestEnableEXT");
	vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)load(context, "vkCmdSetDepthCompareOpEXT");
	vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)load(context, "vkCmdSetDepthTestEnableEXT");
	vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)load(context, "vkCmdSetDepthWriteEnableEXT");
	vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)load(context, "vkCmdSetFrontFaceEXT");
	vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)load(context, "vkCmdSetPrimitiveTopologyEXT");
	vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)load(context, "vkCmdSetScissorWithCountEXT");
	vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)load(context, "vkCmdSetStencilOpEXT");
	vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)load(context, "vkCmdSetStencilTestEnableEXT");
	vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)load(context, "vkCmdSetViewportWithCountEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object))
	vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)load(context, "vkCmdSetDepthBiasEnableEXT");
	vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)load(context, "vkCmdSetLogicOpEXT");
	vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)load(context, "vkCmdSetPatchControlPointsEXT");
	vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)load(context, "vkCmdSetPrimitiveRestartEnableEXT");
	vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)load(context, "vkCmdSetRasterizerDiscardEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object))
	vkCmdSetAlphaToCoverageEnableEXT = (PFN_vkCmdSetAlphaToCoverageEnableEXT)load(context, "vkCmdSetAlphaToCoverageEnableEXT");
	vkCmdSetAlphaToOneEnableEXT = (PFN_vkCmdSetAlphaToOneEnableEXT)load(context, "vkCmdSetAlphaToOneEnableEXT");
	vkCmdSetColorBlendEnableEXT = (PFN_vkCmdSetColorBlendEnableEXT)load(context, "vkCmdSetColorBlendEnableEXT");
	vkCmdSetColorBlendEquationEXT = (PFN_vkCmdSetColorBlendEquationEXT)load(context, "vkCmdSetColorBlendEquationEXT");
	vkCmdSetColorWriteMaskEXT = (PFN_vkCmdSetColorWriteMaskEXT)load(context, "vkCmdSetColorWriteMaskEXT");
	vkCmdSetDepthClampEnableEXT = (PFN_vkCmdSetDepthClampEnableEXT)load(context, "vkCmdSetDepthClampEnableEXT");
	vkCmdSetLogicOpEnableEXT = (PFN_vkCmdSetLogicOpEnableEXT)load(context, "vkCmdSetLogicOpEnableEXT");
	vkCmdSetPolygonModeEXT = (PFN_vkCmdSetPolygonModeEXT)load(context, "vkCmdSetPolygonModeEXT");
	vkCmdSetRasterizationSamplesEXT = (PFN_vkCmdSetRasterizationSamplesEXT)load(context, "vkCmdSetRasterizationSamplesEXT");
	vkCmdSetSampleMaskEXT = (PFN_vkCmdSetSampleMaskEXT)load(context, "vkCmdSetSampleMaskEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object))
	vkCmdSetTessellationDomainOriginEXT = (PFN_vkCmdSetTessellationDomainOriginEXT)load(context, "vkCmdSetTessellationDomainOriginEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback))
	vkCmdSetRasterizationStreamEXT = (PFN_vkCmdSetRasterizationStreamEXT)load(context, "vkCmdSetRasterizationStreamEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization))
	vkCmdSetConservativeRasterizationModeEXT = (PFN_vkCmdSetConservativeRasterizationModeEXT)load(context, "vkCmdSetConservativeRasterizationModeEXT");
	vkCmdSetExtraPrimitiveOverestimationSizeEXT = (PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT)load(context, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable))
	vkCmdSetDepthClipEnableEXT = (PFN_vkCmdSetDepthClipEnableEXT)load(context, "vkCmdSetDepthClipEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations))
	vkCmdSetSampleLocationsEnableEXT = (PFN_vkCmdSetSampleLocationsEnableEXT)load(context, "vkCmdSetSampleLocationsEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced))
	vkCmdSetColorBlendAdvancedEXT = (PFN_vkCmdSetColorBlendAdvancedEXT)load(context, "vkCmdSetColorBlendAdvancedEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex))
	vkCmdSetProvokingVertexModeEXT = (PFN_vkCmdSetProvokingVertexModeEXT)load(context, "vkCmdSetProvokingVertexModeEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization))
	vkCmdSetLineRasterizationModeEXT = (PFN_vkCmdSetLineRasterizationModeEXT)load(context, "vkCmdSetLineRasterizationModeEXT");
	vkCmdSetLineStippleEnableEXT = (PFN_vkCmdSetLineStippleEnableEXT)load(context, "vkCmdSetLineStippleEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control))
	vkCmdSetDepthClipNegativeOneToOneEXT = (PFN_vkCmdSetDepthClipNegativeOneToOneEXT)load(context, "vkCmdSetDepthClipNegativeOneToOneEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling))
	vkCmdSetViewportWScalingEnableNV = (PFN_vkCmdSetViewportWScalingEnableNV)load(context, "vkCmdSetViewportWScalingEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle))
	vkCmdSetViewportSwizzleNV = (PFN_vkCmdSetViewportSwizzleNV)load(context, "vkCmdSetViewportSwizzleNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color))
	vkCmdSetCoverageToColorEnableNV = (PFN_vkCmdSetCoverageToColorEnableNV)load(context, "vkCmdSetCoverageToColorEnableNV");
	vkCmdSetCoverageToColorLocationNV = (PFN_vkCmdSetCoverageToColorLocationNV)load(context, "vkCmdSetCoverageToColorLocationNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples))
	vkCmdSetCoverageModulationModeNV = (PFN_vkCmdSetCoverageModulationModeNV)load(context, "vkCmdSetCoverageModulationModeNV");
	vkCmdSetCoverageModulationTableEnableNV = (PFN_vkCmdSetCoverageModulationTableEnableNV)load(context, "vkCmdSetCoverageModulationTableEnableNV");
	vkCmdSetCoverageModulationTableNV = (PFN_vkCmdSetCoverageModulationTableNV)load(context, "vkCmdSetCoverageModulationTableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image))
	vkCmdSetShadingRateImageEnableNV = (PFN_vkCmdSetShadingRateImageEnableNV)load(context, "vkCmdSetShadingRateImageEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test))
	vkCmdSetRepresentativeFragmentTestEnableNV = (PFN_vkCmdSetRepresentativeFragmentTestEnableNV)load(context, "vkCmdSetRepresentativeFragmentTestEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode))
	vkCmdSetCoverageReductionModeNV = (PFN_vkCmdSetCoverageReductionModeNV)load(context, "vkCmdSetCoverageReductionModeNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode)) */
#if (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control))
	vkGetImageSubresourceLayout2EXT = (PFN_vkGetImageSubresourceLayout2EXT)load(context, "vkGetImageSubresourceLayout2EXT");
#endif /* (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control)) */
#if (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state))
	vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)load(context, "vkCmdSetVertexInputEXT");
#endif /* (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state)) */
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)))
	vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)load(context, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template))) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)load(context, "vkGetDeviceGroupPresentCapabilitiesKHR");
	vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)load(context, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)load(context, "vkAcquireNextImage2KHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_LOAD_DEVICE */
#endif /* VOLK_IN_LOADERS_CLOTH */
}

static void volkGenLoadInstanceTable(struct VolkInstanceTable* table, void* context, PFN_vkVoidFunction (*load)(void*, const char*))
{
	/* VOLK_GENERATE_LOAD_INSTANCE_TABLE */
#if defined(VK_VERSION_1_0)
	table->vkCreateDevice = (PFN_vkCreateDevice)load(context, "vkCreateDevice");
	table->vkDestroyInstance = (PFN_vkDestroyInstance)load(context, "vkDestroyInstance");
	table->vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)load(context, "vkEnumerateDeviceExtensionProperties");
	table->vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)load(context, "vkEnumerateDeviceLayerProperties");
	table->vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)load(context, "vkEnumeratePhysicalDevices");
	table->vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)load(context, "vkGetDeviceProcAddr");
	table->vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)load(context, "vkGetPhysicalDeviceFeatures");
	table->vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)load(context, "vkGetPhysicalDeviceFormatProperties");
	table->vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)load(context, "vkGetPhysicalDeviceImageFormatProperties");
	table->vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)load(context, "vkGetPhysicalDeviceMemoryProperties");
	table->vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)load(context, "vkGetPhysicalDeviceProperties");
	table->vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)load(context, "vkGetPhysicalDeviceQueueFamilyProperties");
	table->vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	table->vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)load(context, "vkEnumeratePhysicalDeviceGroups");
	table->vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)load(context, "vkGetPhysicalDeviceExternalBufferProperties");
	table->vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)load(context, "vkGetPhysicalDeviceExternalFenceProperties");
	table->vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)load(context, "vkGetPhysicalDeviceExternalSemaphoreProperties");
	table->vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)load(context, "vkGetPhysicalDeviceFeatures2");
	table->vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)load(context, "vkGetPhysicalDeviceFormatProperties2");
	table->vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)load(context, "vkGetPhysicalDeviceImageFormatProperties2");
	table->vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)load(context, "vkGetPhysicalDeviceMemoryProperties2");
	table->vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)load(context, "vkGetPhysicalDeviceProperties2");
	table->vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)load(context, "vkGetPhysicalDeviceQueueFamilyProperties2");
	table->vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties2");
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_3)
	table->vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties)load(context, "vkGetPhysicalDeviceToolProperties");
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_ARM_data_graph)
	table->vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM = (PFN_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM)load(context, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM");
	table->vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM = (PFN_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM)load(context, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM");
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_performance_counters_by_region)
	table->vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM)load(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM");
#endif /* defined(VK_ARM_performance_counters_by_region) */
#if defined(VK_ARM_tensors)
	table->vkGetPhysicalDeviceExternalTensorPropertiesARM = (PFN_vkGetPhysicalDeviceExternalTensorPropertiesARM)load(context, "vkGetPhysicalDeviceExternalTensorPropertiesARM");
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_EXT_acquire_drm_display)
	table->vkAcquireDrmDisplayEXT = (PFN_vkAcquireDrmDisplayEXT)load(context, "vkAcquireDrmDisplayEXT");
	table->vkGetDrmDisplayEXT = (PFN_vkGetDrmDisplayEXT)load(context, "vkGetDrmDisplayEXT");
#endif /* defined(VK_EXT_acquire_drm_display) */
#if defined(VK_EXT_acquire_xlib_display)
	table->vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)load(context, "vkAcquireXlibDisplayEXT");
	table->vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)load(context, "vkGetRandROutputDisplayEXT");
#endif /* defined(VK_EXT_acquire_xlib_display) */
#if defined(VK_EXT_calibrated_timestamps)
	table->vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)load(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_debug_report)
	table->vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)load(context, "vkCreateDebugReportCallbackEXT");
	table->vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)load(context, "vkDebugReportMessageEXT");
	table->vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)load(context, "vkDestroyDebugReportCallbackEXT");
#endif /* defined(VK_EXT_debug_report) */
#if defined(VK_EXT_debug_utils)
	table->vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)load(context, "vkCmdBeginDebugUtilsLabelEXT");
	table->vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)load(context, "vkCmdEndDebugUtilsLabelEXT");
	table->vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)load(context, "vkCmdInsertDebugUtilsLabelEXT");
	table->vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)load(context, "vkCreateDebugUtilsMessengerEXT");
	table->vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)load(context, "vkDestroyDebugUtilsMessengerEXT");
	table->vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)load(context, "vkQueueBeginDebugUtilsLabelEXT");
	table->vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)load(context, "vkQueueEndDebugUtilsLabelEXT");
	table->vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)load(context, "vkQueueInsertDebugUtilsLabelEXT");
	table->vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)load(context, "vkSetDebugUtilsObjectNameEXT");
	table->vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)load(context, "vkSetDebugUtilsObjectTagEXT");
	table->vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)load(context, "vkSubmitDebugUtilsMessageEXT");
#endif /* defined(VK_EXT_debug_utils) */
#if defined(VK_EXT_direct_mode_display)
	table->vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)load(context, "vkReleaseDisplayEXT");
#endif /* defined(VK_EXT_direct_mode_display) */
#if defined(VK_EXT_directfb_surface)
	table->vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT)load(context, "vkCreateDirectFBSurfaceEXT");
	table->vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)load(context, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif /* defined(VK_EXT_directfb_surface) */
#if defined(VK_EXT_display_surface_counter)
	table->vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)load(context, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif /* defined(VK_EXT_display_surface_counter) */
#if defined(VK_EXT_full_screen_exclusive)
	table->vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)load(context, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_headless_surface)
	table->vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)load(context, "vkCreateHeadlessSurfaceEXT");
#endif /* defined(VK_EXT_headless_surface) */
#if defined(VK_EXT_metal_surface)
	table->vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)load(context, "vkCreateMetalSurfaceEXT");
#endif /* defined(VK_EXT_metal_surface) */
#if defined(VK_EXT_sample_locations)
	table->vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)load(context, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_tooling_info)
	table->vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)load(context, "vkGetPhysicalDeviceToolPropertiesEXT");
#endif /* defined(VK_EXT_tooling_info) */
#if defined(VK_FUCHSIA_imagepipe_surface)
	table->vkCreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA)load(context, "vkCreateImagePipeSurfaceFUCHSIA");
#endif /* defined(VK_FUCHSIA_imagepipe_surface) */
#if defined(VK_GGP_stream_descriptor_surface)
	table->vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)load(context, "vkCreateStreamDescriptorSurfaceGGP");
#endif /* defined(VK_GGP_stream_descriptor_surface) */
#if defined(VK_KHR_android_surface)
	table->vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)load(context, "vkCreateAndroidSurfaceKHR");
#endif /* defined(VK_KHR_android_surface) */
#if defined(VK_KHR_calibrated_timestamps)
	table->vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR)load(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_cooperative_matrix)
	table->vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR)load(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
#endif /* defined(VK_KHR_cooperative_matrix) */
#if defined(VK_KHR_device_group_creation)
	table->vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)load(context, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif /* defined(VK_KHR_device_group_creation) */
#if defined(VK_KHR_display)
	table->vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)load(context, "vkCreateDisplayModeKHR");
	table->vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)load(context, "vkCreateDisplayPlaneSurfaceKHR");
	table->vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)load(context, "vkGetDisplayModePropertiesKHR");
	table->vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)load(context, "vkGetDisplayPlaneCapabilitiesKHR");
	table->vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)load(context, "vkGetDisplayPlaneSupportedDisplaysKHR");
	table->vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)load(context, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
	table->vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)load(context, "vkGetPhysicalDeviceDisplayPropertiesKHR");
#endif /* defined(VK_KHR_display) */
#if defined(VK_KHR_external_fence_capabilities)
	table->vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)load(context, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif /* defined(VK_KHR_external_fence_capabilities) */
#if defined(VK_KHR_external_memory_capabilities)
	table->vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)load(context, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif /* defined(VK_KHR_external_memory_capabilities) */
#if defined(VK_KHR_external_semaphore_capabilities)
	table->vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)load(context, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif /* defined(VK_KHR_external_semaphore_capabilities) */
#if defined(VK_KHR_fragment_shading_rate)
	table->vkGetPhysicalDeviceFragmentShadingRatesKHR = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR)load(context, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_display_properties2)
	table->vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)load(context, "vkGetDisplayModeProperties2KHR");
	table->vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)load(context, "vkGetDisplayPlaneCapabilities2KHR");
	table->vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)load(context, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
	table->vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)load(context, "vkGetPhysicalDeviceDisplayProperties2KHR");
#endif /* defined(VK_KHR_get_display_properties2) */
#if defined(VK_KHR_get_physical_device_properties2)
	table->vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)load(context, "vkGetPhysicalDeviceFeatures2KHR");
	table->vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)load(context, "vkGetPhysicalDeviceFormatProperties2KHR");
	table->vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)load(context, "vkGetPhysicalDeviceImageFormatProperties2KHR");
	table->vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)load(context, "vkGetPhysicalDeviceMemoryProperties2KHR");
	table->vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)load(context, "vkGetPhysicalDeviceProperties2KHR");
	table->vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)load(context, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
	table->vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)load(context, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif /* defined(VK_KHR_get_physical_device_properties2) */
#if defined(VK_KHR_get_surface_capabilities2)
	table->vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)load(context, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
	table->vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)load(context, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif /* defined(VK_KHR_get_surface_capabilities2) */
#if defined(VK_KHR_performance_query)
	table->vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)load(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
	table->vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)load(context, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_surface)
	table->vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)load(context, "vkDestroySurfaceKHR");
	table->vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)load(context, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
	table->vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)load(context, "vkGetPhysicalDeviceSurfaceFormatsKHR");
	table->vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)load(context, "vkGetPhysicalDeviceSurfacePresentModesKHR");
	table->vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)load(context, "vkGetPhysicalDeviceSurfaceSupportKHR");
#endif /* defined(VK_KHR_surface) */
#if defined(VK_KHR_video_encode_queue)
	table->vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR)load(context, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
	table->vkGetPhysicalDeviceVideoCapabilitiesKHR = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR)load(context, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
	table->vkGetPhysicalDeviceVideoFormatPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR)load(context, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_KHR_wayland_surface)
	table->vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)load(context, "vkCreateWaylandSurfaceKHR");
	table->vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)load(context, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif /* defined(VK_KHR_wayland_surface) */
#if defined(VK_KHR_win32_surface)
	table->vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)load(context, "vkCreateWin32SurfaceKHR");
	table->vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)load(context, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif /* defined(VK_KHR_win32_surface) */
#if defined(VK_KHR_xcb_surface)
	table->vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)load(context, "vkCreateXcbSurfaceKHR");
	table->vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)load(context, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif /* defined(VK_KHR_xcb_surface) */
#if defined(VK_KHR_xlib_surface)
	table->vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)load(context, "vkCreateXlibSurfaceKHR");
	table->vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)load(context, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif /* defined(VK_KHR_xlib_surface) */
#if defined(VK_MVK_ios_surface)
	table->vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)load(context, "vkCreateIOSSurfaceMVK");
#endif /* defined(VK_MVK_ios_surface) */
#if defined(VK_MVK_macos_surface)
	table->vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)load(context, "vkCreateMacOSSurfaceMVK");
#endif /* defined(VK_MVK_macos_surface) */
#if defined(VK_NN_vi_surface)
	table->vkCreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)load(context, "vkCreateViSurfaceNN");
#endif /* defined(VK_NN_vi_surface) */
#if defined(VK_NV_acquire_winrt_display)
	table->vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)load(context, "vkAcquireWinrtDisplayNV");
	table->vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)load(context, "vkGetWinrtDisplayNV");
#endif /* defined(VK_NV_acquire_winrt_display) */
#if defined(VK_NV_cooperative_matrix)
	table->vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif /* defined(VK_NV_cooperative_matrix) */
#if defined(VK_NV_cooperative_matrix2)
	table->vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV");
#endif /* defined(VK_NV_cooperative_matrix2) */
#if defined(VK_NV_cooperative_vector)
	table->vkGetPhysicalDeviceCooperativeVectorPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV)load(context, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV");
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_coverage_reduction_mode)
	table->vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)load(context, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif /* defined(VK_NV_coverage_reduction_mode) */
#if defined(VK_NV_external_memory_capabilities)
	table->vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)load(context, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif /* defined(VK_NV_external_memory_capabilities) */
#if defined(VK_NV_optical_flow)
	table->vkGetPhysicalDeviceOpticalFlowImageFormatsNV = (PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV)load(context, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_OHOS_surface)
	table->vkCreateSurfaceOHOS = (PFN_vkCreateSurfaceOHOS)load(context, "vkCreateSurfaceOHOS");
#endif /* defined(VK_OHOS_surface) */
#if defined(VK_QNX_screen_surface)
	table->vkCreateScreenSurfaceQNX = (PFN_vkCreateScreenSurfaceQNX)load(context, "vkCreateScreenSurfaceQNX");
	table->vkGetPhysicalDeviceScreenPresentationSupportQNX = (PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)load(context, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
#endif /* defined(VK_QNX_screen_surface) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	table->vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)load(context, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_LOAD_INSTANCE_TABLE */
}

static void volkGenLoadDeviceTable(struct VolkDeviceTable* table, void* context, PFN_vkVoidFunction (*load)(void*, const char*))
{
	/* VOLK_GENERATE_LOAD_DEVICE_TABLE */
#if defined(VK_VERSION_1_0)
	table->vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)load(context, "vkAllocateCommandBuffers");
	table->vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)load(context, "vkAllocateDescriptorSets");
	table->vkAllocateMemory = (PFN_vkAllocateMemory)load(context, "vkAllocateMemory");
	table->vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)load(context, "vkBeginCommandBuffer");
	table->vkBindBufferMemory = (PFN_vkBindBufferMemory)load(context, "vkBindBufferMemory");
	table->vkBindImageMemory = (PFN_vkBindImageMemory)load(context, "vkBindImageMemory");
	table->vkCmdBeginQuery = (PFN_vkCmdBeginQuery)load(context, "vkCmdBeginQuery");
	table->vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)load(context, "vkCmdBeginRenderPass");
	table->vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)load(context, "vkCmdBindDescriptorSets");
	table->vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)load(context, "vkCmdBindIndexBuffer");
	table->vkCmdBindPipeline = (PFN_vkCmdBindPipeline)load(context, "vkCmdBindPipeline");
	table->vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)load(context, "vkCmdBindVertexBuffers");
	table->vkCmdBlitImage = (PFN_vkCmdBlitImage)load(context, "vkCmdBlitImage");
	table->vkCmdClearAttachments = (PFN_vkCmdClearAttachments)load(context, "vkCmdClearAttachments");
	table->vkCmdClearColorImage = (PFN_vkCmdClearColorImage)load(context, "vkCmdClearColorImage");
	table->vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)load(context, "vkCmdClearDepthStencilImage");
	table->vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)load(context, "vkCmdCopyBuffer");
	table->vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)load(context, "vkCmdCopyBufferToImage");
	table->vkCmdCopyImage = (PFN_vkCmdCopyImage)load(context, "vkCmdCopyImage");
	table->vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)load(context, "vkCmdCopyImageToBuffer");
	table->vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)load(context, "vkCmdCopyQueryPoolResults");
	table->vkCmdDispatch = (PFN_vkCmdDispatch)load(context, "vkCmdDispatch");
	table->vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)load(context, "vkCmdDispatchIndirect");
	table->vkCmdDraw = (PFN_vkCmdDraw)load(context, "vkCmdDraw");
	table->vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)load(context, "vkCmdDrawIndexed");
	table->vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)load(context, "vkCmdDrawIndexedIndirect");
	table->vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)load(context, "vkCmdDrawIndirect");
	table->vkCmdEndQuery = (PFN_vkCmdEndQuery)load(context, "vkCmdEndQuery");
	table->vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)load(context, "vkCmdEndRenderPass");
	table->vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)load(context, "vkCmdExecuteCommands");
	table->vkCmdFillBuffer = (PFN_vkCmdFillBuffer)load(context, "vkCmdFillBuffer");
	table->vkCmdNextSubpass = (PFN_vkCmdNextSubpass)load(context, "vkCmdNextSubpass");
	table->vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)load(context, "vkCmdPipelineBarrier");
	table->vkCmdPushConstants = (PFN_vkCmdPushConstants)load(context, "vkCmdPushConstants");
	table->vkCmdResetEvent = (PFN_vkCmdResetEvent)load(context, "vkCmdResetEvent");
	table->vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)load(context, "vkCmdResetQueryPool");
	table->vkCmdResolveImage = (PFN_vkCmdResolveImage)load(context, "vkCmdResolveImage");
	table->vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)load(context, "vkCmdSetBlendConstants");
	table->vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)load(context, "vkCmdSetDepthBias");
	table->vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)load(context, "vkCmdSetDepthBounds");
	table->vkCmdSetEvent = (PFN_vkCmdSetEvent)load(context, "vkCmdSetEvent");
	table->vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)load(context, "vkCmdSetLineWidth");
	table->vkCmdSetScissor = (PFN_vkCmdSetScissor)load(context, "vkCmdSetScissor");
	table->vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)load(context, "vkCmdSetStencilCompareMask");
	table->vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)load(context, "vkCmdSetStencilReference");
	table->vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)load(context, "vkCmdSetStencilWriteMask");
	table->vkCmdSetViewport = (PFN_vkCmdSetViewport)load(context, "vkCmdSetViewport");
	table->vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)load(context, "vkCmdUpdateBuffer");
	table->vkCmdWaitEvents = (PFN_vkCmdWaitEvents)load(context, "vkCmdWaitEvents");
	table->vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)load(context, "vkCmdWriteTimestamp");
	table->vkCreateBuffer = (PFN_vkCreateBuffer)load(context, "vkCreateBuffer");
	table->vkCreateBufferView = (PFN_vkCreateBufferView)load(context, "vkCreateBufferView");
	table->vkCreateCommandPool = (PFN_vkCreateCommandPool)load(context, "vkCreateCommandPool");
	table->vkCreateComputePipelines = (PFN_vkCreateComputePipelines)load(context, "vkCreateComputePipelines");
	table->vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)load(context, "vkCreateDescriptorPool");
	table->vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)load(context, "vkCreateDescriptorSetLayout");
	table->vkCreateEvent = (PFN_vkCreateEvent)load(context, "vkCreateEvent");
	table->vkCreateFence = (PFN_vkCreateFence)load(context, "vkCreateFence");
	table->vkCreateFramebuffer = (PFN_vkCreateFramebuffer)load(context, "vkCreateFramebuffer");
	table->vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)load(context, "vkCreateGraphicsPipelines");
	table->vkCreateImage = (PFN_vkCreateImage)load(context, "vkCreateImage");
	table->vkCreateImageView = (PFN_vkCreateImageView)load(context, "vkCreateImageView");
	table->vkCreatePipelineCache = (PFN_vkCreatePipelineCache)load(context, "vkCreatePipelineCache");
	table->vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)load(context, "vkCreatePipelineLayout");
	table->vkCreateQueryPool = (PFN_vkCreateQueryPool)load(context, "vkCreateQueryPool");
	table->vkCreateRenderPass = (PFN_vkCreateRenderPass)load(context, "vkCreateRenderPass");
	table->vkCreateSampler = (PFN_vkCreateSampler)load(context, "vkCreateSampler");
	table->vkCreateSemaphore = (PFN_vkCreateSemaphore)load(context, "vkCreateSemaphore");
	table->vkCreateShaderModule = (PFN_vkCreateShaderModule)load(context, "vkCreateShaderModule");
	table->vkDestroyBuffer = (PFN_vkDestroyBuffer)load(context, "vkDestroyBuffer");
	table->vkDestroyBufferView = (PFN_vkDestroyBufferView)load(context, "vkDestroyBufferView");
	table->vkDestroyCommandPool = (PFN_vkDestroyCommandPool)load(context, "vkDestroyCommandPool");
	table->vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)load(context, "vkDestroyDescriptorPool");
	table->vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)load(context, "vkDestroyDescriptorSetLayout");
	table->vkDestroyDevice = (PFN_vkDestroyDevice)load(context, "vkDestroyDevice");
	table->vkDestroyEvent = (PFN_vkDestroyEvent)load(context, "vkDestroyEvent");
	table->vkDestroyFence = (PFN_vkDestroyFence)load(context, "vkDestroyFence");
	table->vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)load(context, "vkDestroyFramebuffer");
	table->vkDestroyImage = (PFN_vkDestroyImage)load(context, "vkDestroyImage");
	table->vkDestroyImageView = (PFN_vkDestroyImageView)load(context, "vkDestroyImageView");
	table->vkDestroyPipeline = (PFN_vkDestroyPipeline)load(context, "vkDestroyPipeline");
	table->vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)load(context, "vkDestroyPipelineCache");
	table->vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)load(context, "vkDestroyPipelineLayout");
	table->vkDestroyQueryPool = (PFN_vkDestroyQueryPool)load(context, "vkDestroyQueryPool");
	table->vkDestroyRenderPass = (PFN_vkDestroyRenderPass)load(context, "vkDestroyRenderPass");
	table->vkDestroySampler = (PFN_vkDestroySampler)load(context, "vkDestroySampler");
	table->vkDestroySemaphore = (PFN_vkDestroySemaphore)load(context, "vkDestroySemaphore");
	table->vkDestroyShaderModule = (PFN_vkDestroyShaderModule)load(context, "vkDestroyShaderModule");
	table->vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)load(context, "vkDeviceWaitIdle");
	table->vkEndCommandBuffer = (PFN_vkEndCommandBuffer)load(context, "vkEndCommandBuffer");
	table->vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)load(context, "vkFlushMappedMemoryRanges");
	table->vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)load(context, "vkFreeCommandBuffers");
	table->vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)load(context, "vkFreeDescriptorSets");
	table->vkFreeMemory = (PFN_vkFreeMemory)load(context, "vkFreeMemory");
	table->vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)load(context, "vkGetBufferMemoryRequirements");
	table->vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)load(context, "vkGetDeviceMemoryCommitment");
	table->vkGetDeviceQueue = (PFN_vkGetDeviceQueue)load(context, "vkGetDeviceQueue");
	table->vkGetEventStatus = (PFN_vkGetEventStatus)load(context, "vkGetEventStatus");
	table->vkGetFenceStatus = (PFN_vkGetFenceStatus)load(context, "vkGetFenceStatus");
	table->vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)load(context, "vkGetImageMemoryRequirements");
	table->vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)load(context, "vkGetImageSparseMemoryRequirements");
	table->vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)load(context, "vkGetImageSubresourceLayout");
	table->vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)load(context, "vkGetPipelineCacheData");
	table->vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)load(context, "vkGetQueryPoolResults");
	table->vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)load(context, "vkGetRenderAreaGranularity");
	table->vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)load(context, "vkInvalidateMappedMemoryRanges");
	table->vkMapMemory = (PFN_vkMapMemory)load(context, "vkMapMemory");
	table->vkMergePipelineCaches = (PFN_vkMergePipelineCaches)load(context, "vkMergePipelineCaches");
	table->vkQueueBindSparse = (PFN_vkQueueBindSparse)load(context, "vkQueueBindSparse");
	table->vkQueueSubmit = (PFN_vkQueueSubmit)load(context, "vkQueueSubmit");
	table->vkQueueWaitIdle = (PFN_vkQueueWaitIdle)load(context, "vkQueueWaitIdle");
	table->vkResetCommandBuffer = (PFN_vkResetCommandBuffer)load(context, "vkResetCommandBuffer");
	table->vkResetCommandPool = (PFN_vkResetCommandPool)load(context, "vkResetCommandPool");
	table->vkResetDescriptorPool = (PFN_vkResetDescriptorPool)load(context, "vkResetDescriptorPool");
	table->vkResetEvent = (PFN_vkResetEvent)load(context, "vkResetEvent");
	table->vkResetFences = (PFN_vkResetFences)load(context, "vkResetFences");
	table->vkSetEvent = (PFN_vkSetEvent)load(context, "vkSetEvent");
	table->vkUnmapMemory = (PFN_vkUnmapMemory)load(context, "vkUnmapMemory");
	table->vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)load(context, "vkUpdateDescriptorSets");
	table->vkWaitForFences = (PFN_vkWaitForFences)load(context, "vkWaitForFences");
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
	table->vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)load(context, "vkBindBufferMemory2");
	table->vkBindImageMemory2 = (PFN_vkBindImageMemory2)load(context, "vkBindImageMemory2");
	table->vkCmdDispatchBase = (PFN_vkCmdDispatchBase)load(context, "vkCmdDispatchBase");
	table->vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)load(context, "vkCmdSetDeviceMask");
	table->vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)load(context, "vkCreateDescriptorUpdateTemplate");
	table->vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)load(context, "vkCreateSamplerYcbcrConversion");
	table->vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)load(context, "vkDestroyDescriptorUpdateTemplate");
	table->vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)load(context, "vkDestroySamplerYcbcrConversion");
	table->vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)load(context, "vkGetBufferMemoryRequirements2");
	table->vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)load(context, "vkGetDescriptorSetLayoutSupport");
	table->vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)load(context, "vkGetDeviceGroupPeerMemoryFeatures");
	table->vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)load(context, "vkGetDeviceQueue2");
	table->vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)load(context, "vkGetImageMemoryRequirements2");
	table->vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)load(context, "vkGetImageSparseMemoryRequirements2");
	table->vkTrimCommandPool = (PFN_vkTrimCommandPool)load(context, "vkTrimCommandPool");
	table->vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)load(context, "vkUpdateDescriptorSetWithTemplate");
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_2)
	table->vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)load(context, "vkCmdBeginRenderPass2");
	table->vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)load(context, "vkCmdDrawIndexedIndirectCount");
	table->vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)load(context, "vkCmdDrawIndirectCount");
	table->vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)load(context, "vkCmdEndRenderPass2");
	table->vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)load(context, "vkCmdNextSubpass2");
	table->vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)load(context, "vkCreateRenderPass2");
	table->vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)load(context, "vkGetBufferDeviceAddress");
	table->vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)load(context, "vkGetBufferOpaqueCaptureAddress");
	table->vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)load(context, "vkGetDeviceMemoryOpaqueCaptureAddress");
	table->vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)load(context, "vkGetSemaphoreCounterValue");
	table->vkResetQueryPool = (PFN_vkResetQueryPool)load(context, "vkResetQueryPool");
	table->vkSignalSemaphore = (PFN_vkSignalSemaphore)load(context, "vkSignalSemaphore");
	table->vkWaitSemaphores = (PFN_vkWaitSemaphores)load(context, "vkWaitSemaphores");
#endif /* defined(VK_VERSION_1_2) */
#if defined(VK_VERSION_1_3)
	table->vkCmdBeginRendering = (PFN_vkCmdBeginRendering)load(context, "vkCmdBeginRendering");
	table->vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)load(context, "vkCmdBindVertexBuffers2");
	table->vkCmdBlitImage2 = (PFN_vkCmdBlitImage2)load(context, "vkCmdBlitImage2");
	table->vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)load(context, "vkCmdCopyBuffer2");
	table->vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)load(context, "vkCmdCopyBufferToImage2");
	table->vkCmdCopyImage2 = (PFN_vkCmdCopyImage2)load(context, "vkCmdCopyImage2");
	table->vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)load(context, "vkCmdCopyImageToBuffer2");
	table->vkCmdEndRendering = (PFN_vkCmdEndRendering)load(context, "vkCmdEndRendering");
	table->vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)load(context, "vkCmdPipelineBarrier2");
	table->vkCmdResetEvent2 = (PFN_vkCmdResetEvent2)load(context, "vkCmdResetEvent2");
	table->vkCmdResolveImage2 = (PFN_vkCmdResolveImage2)load(context, "vkCmdResolveImage2");
	table->vkCmdSetCullMode = (PFN_vkCmdSetCullMode)load(context, "vkCmdSetCullMode");
	table->vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)load(context, "vkCmdSetDepthBiasEnable");
	table->vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)load(context, "vkCmdSetDepthBoundsTestEnable");
	table->vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)load(context, "vkCmdSetDepthCompareOp");
	table->vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)load(context, "vkCmdSetDepthTestEnable");
	table->vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)load(context, "vkCmdSetDepthWriteEnable");
	table->vkCmdSetEvent2 = (PFN_vkCmdSetEvent2)load(context, "vkCmdSetEvent2");
	table->vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace)load(context, "vkCmdSetFrontFace");
	table->vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)load(context, "vkCmdSetPrimitiveRestartEnable");
	table->vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)load(context, "vkCmdSetPrimitiveTopology");
	table->vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable)load(context, "vkCmdSetRasterizerDiscardEnable");
	table->vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)load(context, "vkCmdSetScissorWithCount");
	table->vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp)load(context, "vkCmdSetStencilOp");
	table->vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)load(context, "vkCmdSetStencilTestEnable");
	table->vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)load(context, "vkCmdSetViewportWithCount");
	table->vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2)load(context, "vkCmdWaitEvents2");
	table->vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)load(context, "vkCmdWriteTimestamp2");
	table->vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)load(context, "vkCreatePrivateDataSlot");
	table->vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)load(context, "vkDestroyPrivateDataSlot");
	table->vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements)load(context, "vkGetDeviceBufferMemoryRequirements");
	table->vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements)load(context, "vkGetDeviceImageMemoryRequirements");
	table->vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)load(context, "vkGetDeviceImageSparseMemoryRequirements");
	table->vkGetPrivateData = (PFN_vkGetPrivateData)load(context, "vkGetPrivateData");
	table->vkQueueSubmit2 = (PFN_vkQueueSubmit2)load(context, "vkQueueSubmit2");
	table->vkSetPrivateData = (PFN_vkSetPrivateData)load(context, "vkSetPrivateData");
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_VERSION_1_4)
	table->vkCmdBindDescriptorSets2 = (PFN_vkCmdBindDescriptorSets2)load(context, "vkCmdBindDescriptorSets2");
	table->vkCmdBindIndexBuffer2 = (PFN_vkCmdBindIndexBuffer2)load(context, "vkCmdBindIndexBuffer2");
	table->vkCmdPushConstants2 = (PFN_vkCmdPushConstants2)load(context, "vkCmdPushConstants2");
	table->vkCmdPushDescriptorSet = (PFN_vkCmdPushDescriptorSet)load(context, "vkCmdPushDescriptorSet");
	table->vkCmdPushDescriptorSet2 = (PFN_vkCmdPushDescriptorSet2)load(context, "vkCmdPushDescriptorSet2");
	table->vkCmdPushDescriptorSetWithTemplate = (PFN_vkCmdPushDescriptorSetWithTemplate)load(context, "vkCmdPushDescriptorSetWithTemplate");
	table->vkCmdPushDescriptorSetWithTemplate2 = (PFN_vkCmdPushDescriptorSetWithTemplate2)load(context, "vkCmdPushDescriptorSetWithTemplate2");
	table->vkCmdSetLineStipple = (PFN_vkCmdSetLineStipple)load(context, "vkCmdSetLineStipple");
	table->vkCmdSetRenderingAttachmentLocations = (PFN_vkCmdSetRenderingAttachmentLocations)load(context, "vkCmdSetRenderingAttachmentLocations");
	table->vkCmdSetRenderingInputAttachmentIndices = (PFN_vkCmdSetRenderingInputAttachmentIndices)load(context, "vkCmdSetRenderingInputAttachmentIndices");
	table->vkCopyImageToImage = (PFN_vkCopyImageToImage)load(context, "vkCopyImageToImage");
	table->vkCopyImageToMemory = (PFN_vkCopyImageToMemory)load(context, "vkCopyImageToMemory");
	table->vkCopyMemoryToImage = (PFN_vkCopyMemoryToImage)load(context, "vkCopyMemoryToImage");
	table->vkGetDeviceImageSubresourceLayout = (PFN_vkGetDeviceImageSubresourceLayout)load(context, "vkGetDeviceImageSubresourceLayout");
	table->vkGetImageSubresourceLayout2 = (PFN_vkGetImageSubresourceLayout2)load(context, "vkGetImageSubresourceLayout2");
	table->vkGetRenderingAreaGranularity = (PFN_vkGetRenderingAreaGranularity)load(context, "vkGetRenderingAreaGranularity");
	table->vkMapMemory2 = (PFN_vkMapMemory2)load(context, "vkMapMemory2");
	table->vkTransitionImageLayout = (PFN_vkTransitionImageLayout)load(context, "vkTransitionImageLayout");
	table->vkUnmapMemory2 = (PFN_vkUnmapMemory2)load(context, "vkUnmapMemory2");
#endif /* defined(VK_VERSION_1_4) */
#if defined(VK_AMDX_shader_enqueue)
	table->vkCmdDispatchGraphAMDX = (PFN_vkCmdDispatchGraphAMDX)load(context, "vkCmdDispatchGraphAMDX");
	table->vkCmdDispatchGraphIndirectAMDX = (PFN_vkCmdDispatchGraphIndirectAMDX)load(context, "vkCmdDispatchGraphIndirectAMDX");
	table->vkCmdDispatchGraphIndirectCountAMDX = (PFN_vkCmdDispatchGraphIndirectCountAMDX)load(context, "vkCmdDispatchGraphIndirectCountAMDX");
	table->vkCmdInitializeGraphScratchMemoryAMDX = (PFN_vkCmdInitializeGraphScratchMemoryAMDX)load(context, "vkCmdInitializeGraphScratchMemoryAMDX");
	table->vkCreateExecutionGraphPipelinesAMDX = (PFN_vkCreateExecutionGraphPipelinesAMDX)load(context, "vkCreateExecutionGraphPipelinesAMDX");
	table->vkGetExecutionGraphPipelineNodeIndexAMDX = (PFN_vkGetExecutionGraphPipelineNodeIndexAMDX)load(context, "vkGetExecutionGraphPipelineNodeIndexAMDX");
	table->vkGetExecutionGraphPipelineScratchSizeAMDX = (PFN_vkGetExecutionGraphPipelineScratchSizeAMDX)load(context, "vkGetExecutionGraphPipelineScratchSizeAMDX");
#endif /* defined(VK_AMDX_shader_enqueue) */
#if defined(VK_AMD_anti_lag)
	table->vkAntiLagUpdateAMD = (PFN_vkAntiLagUpdateAMD)load(context, "vkAntiLagUpdateAMD");
#endif /* defined(VK_AMD_anti_lag) */
#if defined(VK_AMD_buffer_marker)
	table->vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)load(context, "vkCmdWriteBufferMarkerAMD");
#endif /* defined(VK_AMD_buffer_marker) */
#if defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
	table->vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)load(context, "vkCmdWriteBufferMarker2AMD");
#endif /* defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_AMD_display_native_hdr)
	table->vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)load(context, "vkSetLocalDimmingAMD");
#endif /* defined(VK_AMD_display_native_hdr) */
#if defined(VK_AMD_draw_indirect_count)
	table->vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)load(context, "vkCmdDrawIndexedIndirectCountAMD");
	table->vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)load(context, "vkCmdDrawIndirectCountAMD");
#endif /* defined(VK_AMD_draw_indirect_count) */
#if defined(VK_AMD_shader_info)
	table->vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)load(context, "vkGetShaderInfoAMD");
#endif /* defined(VK_AMD_shader_info) */
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
	table->vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)load(context, "vkGetAndroidHardwareBufferPropertiesANDROID");
	table->vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)load(context, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
#if defined(VK_ARM_data_graph)
	table->vkBindDataGraphPipelineSessionMemoryARM = (PFN_vkBindDataGraphPipelineSessionMemoryARM)load(context, "vkBindDataGraphPipelineSessionMemoryARM");
	table->vkCmdDispatchDataGraphARM = (PFN_vkCmdDispatchDataGraphARM)load(context, "vkCmdDispatchDataGraphARM");
	table->vkCreateDataGraphPipelineSessionARM = (PFN_vkCreateDataGraphPipelineSessionARM)load(context, "vkCreateDataGraphPipelineSessionARM");
	table->vkCreateDataGraphPipelinesARM = (PFN_vkCreateDataGraphPipelinesARM)load(context, "vkCreateDataGraphPipelinesARM");
	table->vkDestroyDataGraphPipelineSessionARM = (PFN_vkDestroyDataGraphPipelineSessionARM)load(context, "vkDestroyDataGraphPipelineSessionARM");
	table->vkGetDataGraphPipelineAvailablePropertiesARM = (PFN_vkGetDataGraphPipelineAvailablePropertiesARM)load(context, "vkGetDataGraphPipelineAvailablePropertiesARM");
	table->vkGetDataGraphPipelinePropertiesARM = (PFN_vkGetDataGraphPipelinePropertiesARM)load(context, "vkGetDataGraphPipelinePropertiesARM");
	table->vkGetDataGraphPipelineSessionBindPointRequirementsARM = (PFN_vkGetDataGraphPipelineSessionBindPointRequirementsARM)load(context, "vkGetDataGraphPipelineSessionBindPointRequirementsARM");
	table->vkGetDataGraphPipelineSessionMemoryRequirementsARM = (PFN_vkGetDataGraphPipelineSessionMemoryRequirementsARM)load(context, "vkGetDataGraphPipelineSessionMemoryRequirementsARM");
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_tensors)
	table->vkBindTensorMemoryARM = (PFN_vkBindTensorMemoryARM)load(context, "vkBindTensorMemoryARM");
	table->vkCmdCopyTensorARM = (PFN_vkCmdCopyTensorARM)load(context, "vkCmdCopyTensorARM");
	table->vkCreateTensorARM = (PFN_vkCreateTensorARM)load(context, "vkCreateTensorARM");
	table->vkCreateTensorViewARM = (PFN_vkCreateTensorViewARM)load(context, "vkCreateTensorViewARM");
	table->vkDestroyTensorARM = (PFN_vkDestroyTensorARM)load(context, "vkDestroyTensorARM");
	table->vkDestroyTensorViewARM = (PFN_vkDestroyTensorViewARM)load(context, "vkDestroyTensorViewARM");
	table->vkGetDeviceTensorMemoryRequirementsARM = (PFN_vkGetDeviceTensorMemoryRequirementsARM)load(context, "vkGetDeviceTensorMemoryRequirementsARM");
	table->vkGetTensorMemoryRequirementsARM = (PFN_vkGetTensorMemoryRequirementsARM)load(context, "vkGetTensorMemoryRequirementsARM");
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer)
	table->vkGetTensorOpaqueCaptureDescriptorDataARM = (PFN_vkGetTensorOpaqueCaptureDescriptorDataARM)load(context, "vkGetTensorOpaqueCaptureDescriptorDataARM");
	table->vkGetTensorViewOpaqueCaptureDescriptorDataARM = (PFN_vkGetTensorViewOpaqueCaptureDescriptorDataARM)load(context, "vkGetTensorViewOpaqueCaptureDescriptorDataARM");
#endif /* defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
	table->vkCmdSetAttachmentFeedbackLoopEnableEXT = (PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT)load(context, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
#endif /* defined(VK_EXT_attachment_feedback_loop_dynamic_state) */
#if defined(VK_EXT_buffer_device_address)
	table->vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)load(context, "vkGetBufferDeviceAddressEXT");
#endif /* defined(VK_EXT_buffer_device_address) */
#if defined(VK_EXT_calibrated_timestamps)
	table->vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)load(context, "vkGetCalibratedTimestampsEXT");
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_color_write_enable)
	table->vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)load(context, "vkCmdSetColorWriteEnableEXT");
#endif /* defined(VK_EXT_color_write_enable) */
#if defined(VK_EXT_conditional_rendering)
	table->vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)load(context, "vkCmdBeginConditionalRenderingEXT");
	table->vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)load(context, "vkCmdEndConditionalRenderingEXT");
#endif /* defined(VK_EXT_conditional_rendering) */
#if defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3))
	table->vkCmdBeginCustomResolveEXT = (PFN_vkCmdBeginCustomResolveEXT)load(context, "vkCmdBeginCustomResolveEXT");
#endif /* defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3)) */
#if defined(VK_EXT_debug_marker)
	table->vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)load(context, "vkCmdDebugMarkerBeginEXT");
	table->vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)load(context, "vkCmdDebugMarkerEndEXT");
	table->vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)load(context, "vkCmdDebugMarkerInsertEXT");
	table->vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)load(context, "vkDebugMarkerSetObjectNameEXT");
	table->vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)load(context, "vkDebugMarkerSetObjectTagEXT");
#endif /* defined(VK_EXT_debug_marker) */
#if defined(VK_EXT_depth_bias_control)
	table->vkCmdSetDepthBias2EXT = (PFN_vkCmdSetDepthBias2EXT)load(context, "vkCmdSetDepthBias2EXT");
#endif /* defined(VK_EXT_depth_bias_control) */
#if defined(VK_EXT_descriptor_buffer)
	table->vkCmdBindDescriptorBufferEmbeddedSamplersEXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT)load(context, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
	table->vkCmdBindDescriptorBuffersEXT = (PFN_vkCmdBindDescriptorBuffersEXT)load(context, "vkCmdBindDescriptorBuffersEXT");
	table->vkCmdSetDescriptorBufferOffsetsEXT = (PFN_vkCmdSetDescriptorBufferOffsetsEXT)load(context, "vkCmdSetDescriptorBufferOffsetsEXT");
	table->vkGetBufferOpaqueCaptureDescriptorDataEXT = (PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT)load(context, "vkGetBufferOpaqueCaptureDescriptorDataEXT");
	table->vkGetDescriptorEXT = (PFN_vkGetDescriptorEXT)load(context, "vkGetDescriptorEXT");
	table->vkGetDescriptorSetLayoutBindingOffsetEXT = (PFN_vkGetDescriptorSetLayoutBindingOffsetEXT)load(context, "vkGetDescriptorSetLayoutBindingOffsetEXT");
	table->vkGetDescriptorSetLayoutSizeEXT = (PFN_vkGetDescriptorSetLayoutSizeEXT)load(context, "vkGetDescriptorSetLayoutSizeEXT");
	table->vkGetImageOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageOpaqueCaptureDescriptorDataEXT)load(context, "vkGetImageOpaqueCaptureDescriptorDataEXT");
	table->vkGetImageViewOpaqueCaptureDescriptorDataEXT = (PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT)load(context, "vkGetImageViewOpaqueCaptureDescriptorDataEXT");
	table->vkGetSamplerOpaqueCaptureDescriptorDataEXT = (PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT)load(context, "vkGetSamplerOpaqueCaptureDescriptorDataEXT");
#endif /* defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing))
	table->vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = (PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT)load(context, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT");
#endif /* defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing)) */
#if defined(VK_EXT_device_fault)
	table->vkGetDeviceFaultInfoEXT = (PFN_vkGetDeviceFaultInfoEXT)load(context, "vkGetDeviceFaultInfoEXT");
#endif /* defined(VK_EXT_device_fault) */
#if defined(VK_EXT_device_generated_commands)
	table->vkCmdExecuteGeneratedCommandsEXT = (PFN_vkCmdExecuteGeneratedCommandsEXT)load(context, "vkCmdExecuteGeneratedCommandsEXT");
	table->vkCmdPreprocessGeneratedCommandsEXT = (PFN_vkCmdPreprocessGeneratedCommandsEXT)load(context, "vkCmdPreprocessGeneratedCommandsEXT");
	table->vkCreateIndirectCommandsLayoutEXT = (PFN_vkCreateIndirectCommandsLayoutEXT)load(context, "vkCreateIndirectCommandsLayoutEXT");
	table->vkCreateIndirectExecutionSetEXT = (PFN_vkCreateIndirectExecutionSetEXT)load(context, "vkCreateIndirectExecutionSetEXT");
	table->vkDestroyIndirectCommandsLayoutEXT = (PFN_vkDestroyIndirectCommandsLayoutEXT)load(context, "vkDestroyIndirectCommandsLayoutEXT");
	table->vkDestroyIndirectExecutionSetEXT = (PFN_vkDestroyIndirectExecutionSetEXT)load(context, "vkDestroyIndirectExecutionSetEXT");
	table->vkGetGeneratedCommandsMemoryRequirementsEXT = (PFN_vkGetGeneratedCommandsMemoryRequirementsEXT)load(context, "vkGetGeneratedCommandsMemoryRequirementsEXT");
	table->vkUpdateIndirectExecutionSetPipelineEXT = (PFN_vkUpdateIndirectExecutionSetPipelineEXT)load(context, "vkUpdateIndirectExecutionSetPipelineEXT");
	table->vkUpdateIndirectExecutionSetShaderEXT = (PFN_vkUpdateIndirectExecutionSetShaderEXT)load(context, "vkUpdateIndirectExecutionSetShaderEXT");
#endif /* defined(VK_EXT_device_generated_commands) */
#if defined(VK_EXT_discard_rectangles)
	table->vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)load(context, "vkCmdSetDiscardRectangleEXT");
#endif /* defined(VK_EXT_discard_rectangles) */
#if defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2
	table->vkCmdSetDiscardRectangleEnableEXT = (PFN_vkCmdSetDiscardRectangleEnableEXT)load(context, "vkCmdSetDiscardRectangleEnableEXT");
	table->vkCmdSetDiscardRectangleModeEXT = (PFN_vkCmdSetDiscardRectangleModeEXT)load(context, "vkCmdSetDiscardRectangleModeEXT");
#endif /* defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2 */
#if defined(VK_EXT_display_control)
	table->vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)load(context, "vkDisplayPowerControlEXT");
	table->vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)load(context, "vkGetSwapchainCounterEXT");
	table->vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)load(context, "vkRegisterDeviceEventEXT");
	table->vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)load(context, "vkRegisterDisplayEventEXT");
#endif /* defined(VK_EXT_display_control) */
#if defined(VK_EXT_external_memory_host)
	table->vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)load(context, "vkGetMemoryHostPointerPropertiesEXT");
#endif /* defined(VK_EXT_external_memory_host) */
#if defined(VK_EXT_external_memory_metal)
	table->vkGetMemoryMetalHandleEXT = (PFN_vkGetMemoryMetalHandleEXT)load(context, "vkGetMemoryMetalHandleEXT");
	table->vkGetMemoryMetalHandlePropertiesEXT = (PFN_vkGetMemoryMetalHandlePropertiesEXT)load(context, "vkGetMemoryMetalHandlePropertiesEXT");
#endif /* defined(VK_EXT_external_memory_metal) */
#if defined(VK_EXT_fragment_density_map_offset)
	table->vkCmdEndRendering2EXT = (PFN_vkCmdEndRendering2EXT)load(context, "vkCmdEndRendering2EXT");
#endif /* defined(VK_EXT_fragment_density_map_offset) */
#if defined(VK_EXT_full_screen_exclusive)
	table->vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)load(context, "vkAcquireFullScreenExclusiveModeEXT");
	table->vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)load(context, "vkReleaseFullScreenExclusiveModeEXT");
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1))
	table->vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)load(context, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif /* defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1)) */
#if defined(VK_EXT_hdr_metadata)
	table->vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)load(context, "vkSetHdrMetadataEXT");
#endif /* defined(VK_EXT_hdr_metadata) */
#if defined(VK_EXT_host_image_copy)
	table->vkCopyImageToImageEXT = (PFN_vkCopyImageToImageEXT)load(context, "vkCopyImageToImageEXT");
	table->vkCopyImageToMemoryEXT = (PFN_vkCopyImageToMemoryEXT)load(context, "vkCopyImageToMemoryEXT");
	table->vkCopyMemoryToImageEXT = (PFN_vkCopyMemoryToImageEXT)load(context, "vkCopyMemoryToImageEXT");
	table->vkTransitionImageLayoutEXT = (PFN_vkTransitionImageLayoutEXT)load(context, "vkTransitionImageLayoutEXT");
#endif /* defined(VK_EXT_host_image_copy) */
#if defined(VK_EXT_host_query_reset)
	table->vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)load(context, "vkResetQueryPoolEXT");
#endif /* defined(VK_EXT_host_query_reset) */
#if defined(VK_EXT_image_drm_format_modifier)
	table->vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)load(context, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif /* defined(VK_EXT_image_drm_format_modifier) */
#if defined(VK_EXT_line_rasterization)
	table->vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)load(context, "vkCmdSetLineStippleEXT");
#endif /* defined(VK_EXT_line_rasterization) */
#if defined(VK_EXT_memory_decompression)
	table->vkCmdDecompressMemoryEXT = (PFN_vkCmdDecompressMemoryEXT)load(context, "vkCmdDecompressMemoryEXT");
	table->vkCmdDecompressMemoryIndirectCountEXT = (PFN_vkCmdDecompressMemoryIndirectCountEXT)load(context, "vkCmdDecompressMemoryIndirectCountEXT");
#endif /* defined(VK_EXT_memory_decompression) */
#if defined(VK_EXT_mesh_shader)
	table->vkCmdDrawMeshTasksEXT = (PFN_vkCmdDrawMeshTasksEXT)load(context, "vkCmdDrawMeshTasksEXT");
	table->vkCmdDrawMeshTasksIndirectEXT = (PFN_vkCmdDrawMeshTasksIndirectEXT)load(context, "vkCmdDrawMeshTasksIndirectEXT");
#endif /* defined(VK_EXT_mesh_shader) */
#if defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
	table->vkCmdDrawMeshTasksIndirectCountEXT = (PFN_vkCmdDrawMeshTasksIndirectCountEXT)load(context, "vkCmdDrawMeshTasksIndirectCountEXT");
#endif /* defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_EXT_metal_objects)
	table->vkExportMetalObjectsEXT = (PFN_vkExportMetalObjectsEXT)load(context, "vkExportMetalObjectsEXT");
#endif /* defined(VK_EXT_metal_objects) */
#if defined(VK_EXT_multi_draw)
	table->vkCmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT)load(context, "vkCmdDrawMultiEXT");
	table->vkCmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT)load(context, "vkCmdDrawMultiIndexedEXT");
#endif /* defined(VK_EXT_multi_draw) */
#if defined(VK_EXT_opacity_micromap)
	table->vkBuildMicromapsEXT = (PFN_vkBuildMicromapsEXT)load(context, "vkBuildMicromapsEXT");
	table->vkCmdBuildMicromapsEXT = (PFN_vkCmdBuildMicromapsEXT)load(context, "vkCmdBuildMicromapsEXT");
	table->vkCmdCopyMemoryToMicromapEXT = (PFN_vkCmdCopyMemoryToMicromapEXT)load(context, "vkCmdCopyMemoryToMicromapEXT");
	table->vkCmdCopyMicromapEXT = (PFN_vkCmdCopyMicromapEXT)load(context, "vkCmdCopyMicromapEXT");
	table->vkCmdCopyMicromapToMemoryEXT = (PFN_vkCmdCopyMicromapToMemoryEXT)load(context, "vkCmdCopyMicromapToMemoryEXT");
	table->vkCmdWriteMicromapsPropertiesEXT = (PFN_vkCmdWriteMicromapsPropertiesEXT)load(context, "vkCmdWriteMicromapsPropertiesEXT");
	table->vkCopyMemoryToMicromapEXT = (PFN_vkCopyMemoryToMicromapEXT)load(context, "vkCopyMemoryToMicromapEXT");
	table->vkCopyMicromapEXT = (PFN_vkCopyMicromapEXT)load(context, "vkCopyMicromapEXT");
	table->vkCopyMicromapToMemoryEXT = (PFN_vkCopyMicromapToMemoryEXT)load(context, "vkCopyMicromapToMemoryEXT");
	table->vkCreateMicromapEXT = (PFN_vkCreateMicromapEXT)load(context, "vkCreateMicromapEXT");
	table->vkDestroyMicromapEXT = (PFN_vkDestroyMicromapEXT)load(context, "vkDestroyMicromapEXT");
	table->vkGetDeviceMicromapCompatibilityEXT = (PFN_vkGetDeviceMicromapCompatibilityEXT)load(context, "vkGetDeviceMicromapCompatibilityEXT");
	table->vkGetMicromapBuildSizesEXT = (PFN_vkGetMicromapBuildSizesEXT)load(context, "vkGetMicromapBuildSizesEXT");
	table->vkWriteMicromapsPropertiesEXT = (PFN_vkWriteMicromapsPropertiesEXT)load(context, "vkWriteMicromapsPropertiesEXT");
#endif /* defined(VK_EXT_opacity_micromap) */
#if defined(VK_EXT_pageable_device_local_memory)
	table->vkSetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT)load(context, "vkSetDeviceMemoryPriorityEXT");
#endif /* defined(VK_EXT_pageable_device_local_memory) */
#if defined(VK_EXT_pipeline_properties)
	table->vkGetPipelinePropertiesEXT = (PFN_vkGetPipelinePropertiesEXT)load(context, "vkGetPipelinePropertiesEXT");
#endif /* defined(VK_EXT_pipeline_properties) */
#if defined(VK_EXT_present_timing)
	table->vkGetPastPresentationTimingEXT = (PFN_vkGetPastPresentationTimingEXT)load(context, "vkGetPastPresentationTimingEXT");
	table->vkGetSwapchainTimeDomainPropertiesEXT = (PFN_vkGetSwapchainTimeDomainPropertiesEXT)load(context, "vkGetSwapchainTimeDomainPropertiesEXT");
	table->vkGetSwapchainTimingPropertiesEXT = (PFN_vkGetSwapchainTimingPropertiesEXT)load(context, "vkGetSwapchainTimingPropertiesEXT");
	table->vkSetSwapchainPresentTimingQueueSizeEXT = (PFN_vkSetSwapchainPresentTimingQueueSizeEXT)load(context, "vkSetSwapchainPresentTimingQueueSizeEXT");
#endif /* defined(VK_EXT_present_timing) */
#if defined(VK_EXT_private_data)
	table->vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)load(context, "vkCreatePrivateDataSlotEXT");
	table->vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)load(context, "vkDestroyPrivateDataSlotEXT");
	table->vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)load(context, "vkGetPrivateDataEXT");
	table->vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)load(context, "vkSetPrivateDataEXT");
#endif /* defined(VK_EXT_private_data) */
#if defined(VK_EXT_sample_locations)
	table->vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)load(context, "vkCmdSetSampleLocationsEXT");
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_shader_module_identifier)
	table->vkGetShaderModuleCreateInfoIdentifierEXT = (PFN_vkGetShaderModuleCreateInfoIdentifierEXT)load(context, "vkGetShaderModuleCreateInfoIdentifierEXT");
	table->vkGetShaderModuleIdentifierEXT = (PFN_vkGetShaderModuleIdentifierEXT)load(context, "vkGetShaderModuleIdentifierEXT");
#endif /* defined(VK_EXT_shader_module_identifier) */
#if defined(VK_EXT_shader_object)
	table->vkCmdBindShadersEXT = (PFN_vkCmdBindShadersEXT)load(context, "vkCmdBindShadersEXT");
	table->vkCreateShadersEXT = (PFN_vkCreateShadersEXT)load(context, "vkCreateShadersEXT");
	table->vkDestroyShaderEXT = (PFN_vkDestroyShaderEXT)load(context, "vkDestroyShaderEXT");
	table->vkGetShaderBinaryDataEXT = (PFN_vkGetShaderBinaryDataEXT)load(context, "vkGetShaderBinaryDataEXT");
#endif /* defined(VK_EXT_shader_object) */
#if defined(VK_EXT_swapchain_maintenance1)
	table->vkReleaseSwapchainImagesEXT = (PFN_vkReleaseSwapchainImagesEXT)load(context, "vkReleaseSwapchainImagesEXT");
#endif /* defined(VK_EXT_swapchain_maintenance1) */
#if defined(VK_EXT_transform_feedback)
	table->vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)load(context, "vkCmdBeginQueryIndexedEXT");
	table->vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)load(context, "vkCmdBeginTransformFeedbackEXT");
	table->vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)load(context, "vkCmdBindTransformFeedbackBuffersEXT");
	table->vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)load(context, "vkCmdDrawIndirectByteCountEXT");
	table->vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)load(context, "vkCmdEndQueryIndexedEXT");
	table->vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)load(context, "vkCmdEndTransformFeedbackEXT");
#endif /* defined(VK_EXT_transform_feedback) */
#if defined(VK_EXT_validation_cache)
	table->vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)load(context, "vkCreateValidationCacheEXT");
	table->vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)load(context, "vkDestroyValidationCacheEXT");
	table->vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)load(context, "vkGetValidationCacheDataEXT");
	table->vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)load(context, "vkMergeValidationCachesEXT");
#endif /* defined(VK_EXT_validation_cache) */
#if defined(VK_FUCHSIA_buffer_collection)
	table->vkCreateBufferCollectionFUCHSIA = (PFN_vkCreateBufferCollectionFUCHSIA)load(context, "vkCreateBufferCollectionFUCHSIA");
	table->vkDestroyBufferCollectionFUCHSIA = (PFN_vkDestroyBufferCollectionFUCHSIA)load(context, "vkDestroyBufferCollectionFUCHSIA");
	table->vkGetBufferCollectionPropertiesFUCHSIA = (PFN_vkGetBufferCollectionPropertiesFUCHSIA)load(context, "vkGetBufferCollectionPropertiesFUCHSIA");
	table->vkSetBufferCollectionBufferConstraintsFUCHSIA = (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)load(context, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
	table->vkSetBufferCollectionImageConstraintsFUCHSIA = (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)load(context, "vkSetBufferCollectionImageConstraintsFUCHSIA");
#endif /* defined(VK_FUCHSIA_buffer_collection) */
#if defined(VK_FUCHSIA_external_memory)
	table->vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)load(context, "vkGetMemoryZirconHandleFUCHSIA");
	table->vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)load(context, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif /* defined(VK_FUCHSIA_external_memory) */
#if defined(VK_FUCHSIA_external_semaphore)
	table->vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)load(context, "vkGetSemaphoreZirconHandleFUCHSIA");
	table->vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)load(context, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif /* defined(VK_FUCHSIA_external_semaphore) */
#if defined(VK_GOOGLE_display_timing)
	table->vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)load(context, "vkGetPastPresentationTimingGOOGLE");
	table->vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)load(context, "vkGetRefreshCycleDurationGOOGLE");
#endif /* defined(VK_GOOGLE_display_timing) */
#if defined(VK_HUAWEI_cluster_culling_shader)
	table->vkCmdDrawClusterHUAWEI = (PFN_vkCmdDrawClusterHUAWEI)load(context, "vkCmdDrawClusterHUAWEI");
	table->vkCmdDrawClusterIndirectHUAWEI = (PFN_vkCmdDrawClusterIndirectHUAWEI)load(context, "vkCmdDrawClusterIndirectHUAWEI");
#endif /* defined(VK_HUAWEI_cluster_culling_shader) */
#if defined(VK_HUAWEI_invocation_mask)
	table->vkCmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI)load(context, "vkCmdBindInvocationMaskHUAWEI");
#endif /* defined(VK_HUAWEI_invocation_mask) */
#if defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2
	table->vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = (PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI)load(context, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI");
#endif /* defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2 */
#if defined(VK_HUAWEI_subpass_shading)
	table->vkCmdSubpassShadingHUAWEI = (PFN_vkCmdSubpassShadingHUAWEI)load(context, "vkCmdSubpassShadingHUAWEI");
#endif /* defined(VK_HUAWEI_subpass_shading) */
#if defined(VK_INTEL_performance_query)
	table->vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)load(context, "vkAcquirePerformanceConfigurationINTEL");
	table->vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)load(context, "vkCmdSetPerformanceMarkerINTEL");
	table->vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)load(context, "vkCmdSetPerformanceOverrideINTEL");
	table->vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)load(context, "vkCmdSetPerformanceStreamMarkerINTEL");
	table->vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)load(context, "vkGetPerformanceParameterINTEL");
	table->vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)load(context, "vkInitializePerformanceApiINTEL");
	table->vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)load(context, "vkQueueSetPerformanceConfigurationINTEL");
	table->vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)load(context, "vkReleasePerformanceConfigurationINTEL");
	table->vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)load(context, "vkUninitializePerformanceApiINTEL");
#endif /* defined(VK_INTEL_performance_query) */
#if defined(VK_KHR_acceleration_structure)
	table->vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)load(context, "vkBuildAccelerationStructuresKHR");
	table->vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)load(context, "vkCmdBuildAccelerationStructuresIndirectKHR");
	table->vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)load(context, "vkCmdBuildAccelerationStructuresKHR");
	table->vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)load(context, "vkCmdCopyAccelerationStructureKHR");
	table->vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)load(context, "vkCmdCopyAccelerationStructureToMemoryKHR");
	table->vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)load(context, "vkCmdCopyMemoryToAccelerationStructureKHR");
	table->vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)load(context, "vkCmdWriteAccelerationStructuresPropertiesKHR");
	table->vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)load(context, "vkCopyAccelerationStructureKHR");
	table->vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)load(context, "vkCopyAccelerationStructureToMemoryKHR");
	table->vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)load(context, "vkCopyMemoryToAccelerationStructureKHR");
	table->vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)load(context, "vkCreateAccelerationStructureKHR");
	table->vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)load(context, "vkDestroyAccelerationStructureKHR");
	table->vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)load(context, "vkGetAccelerationStructureBuildSizesKHR");
	table->vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)load(context, "vkGetAccelerationStructureDeviceAddressKHR");
	table->vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)load(context, "vkGetDeviceAccelerationStructureCompatibilityKHR");
	table->vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)load(context, "vkWriteAccelerationStructuresPropertiesKHR");
#endif /* defined(VK_KHR_acceleration_structure) */
#if defined(VK_KHR_bind_memory2)
	table->vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)load(context, "vkBindBufferMemory2KHR");
	table->vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)load(context, "vkBindImageMemory2KHR");
#endif /* defined(VK_KHR_bind_memory2) */
#if defined(VK_KHR_buffer_device_address)
	table->vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)load(context, "vkGetBufferDeviceAddressKHR");
	table->vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)load(context, "vkGetBufferOpaqueCaptureAddressKHR");
	table->vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)load(context, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif /* defined(VK_KHR_buffer_device_address) */
#if defined(VK_KHR_calibrated_timestamps)
	table->vkGetCalibratedTimestampsKHR = (PFN_vkGetCalibratedTimestampsKHR)load(context, "vkGetCalibratedTimestampsKHR");
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_copy_commands2)
	table->vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)load(context, "vkCmdBlitImage2KHR");
	table->vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)load(context, "vkCmdCopyBuffer2KHR");
	table->vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)load(context, "vkCmdCopyBufferToImage2KHR");
	table->vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)load(context, "vkCmdCopyImage2KHR");
	table->vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)load(context, "vkCmdCopyImageToBuffer2KHR");
	table->vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)load(context, "vkCmdResolveImage2KHR");
#endif /* defined(VK_KHR_copy_commands2) */
#if defined(VK_KHR_copy_memory_indirect)
	table->vkCmdCopyMemoryIndirectKHR = (PFN_vkCmdCopyMemoryIndirectKHR)load(context, "vkCmdCopyMemoryIndirectKHR");
	table->vkCmdCopyMemoryToImageIndirectKHR = (PFN_vkCmdCopyMemoryToImageIndirectKHR)load(context, "vkCmdCopyMemoryToImageIndirectKHR");
#endif /* defined(VK_KHR_copy_memory_indirect) */
#if defined(VK_KHR_create_renderpass2)
	table->vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)load(context, "vkCmdBeginRenderPass2KHR");
	table->vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)load(context, "vkCmdEndRenderPass2KHR");
	table->vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)load(context, "vkCmdNextSubpass2KHR");
	table->vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)load(context, "vkCreateRenderPass2KHR");
#endif /* defined(VK_KHR_create_renderpass2) */
#if defined(VK_KHR_deferred_host_operations)
	table->vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)load(context, "vkCreateDeferredOperationKHR");
	table->vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)load(context, "vkDeferredOperationJoinKHR");
	table->vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)load(context, "vkDestroyDeferredOperationKHR");
	table->vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)load(context, "vkGetDeferredOperationMaxConcurrencyKHR");
	table->vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)load(context, "vkGetDeferredOperationResultKHR");
#endif /* defined(VK_KHR_deferred_host_operations) */
#if defined(VK_KHR_descriptor_update_template)
	table->vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)load(context, "vkCreateDescriptorUpdateTemplateKHR");
	table->vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)load(context, "vkDestroyDescriptorUpdateTemplateKHR");
	table->vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)load(context, "vkUpdateDescriptorSetWithTemplateKHR");
#endif /* defined(VK_KHR_descriptor_update_template) */
#if defined(VK_KHR_device_group)
	table->vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)load(context, "vkCmdDispatchBaseKHR");
	table->vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)load(context, "vkCmdSetDeviceMaskKHR");
	table->vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)load(context, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif /* defined(VK_KHR_device_group) */
#if defined(VK_KHR_display_swapchain)
	table->vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)load(context, "vkCreateSharedSwapchainsKHR");
#endif /* defined(VK_KHR_display_swapchain) */
#if defined(VK_KHR_draw_indirect_count)
	table->vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)load(context, "vkCmdDrawIndexedIndirectCountKHR");
	table->vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)load(context, "vkCmdDrawIndirectCountKHR");
#endif /* defined(VK_KHR_draw_indirect_count) */
#if defined(VK_KHR_dynamic_rendering)
	table->vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR)load(context, "vkCmdBeginRenderingKHR");
	table->vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR)load(context, "vkCmdEndRenderingKHR");
#endif /* defined(VK_KHR_dynamic_rendering) */
#if defined(VK_KHR_dynamic_rendering_local_read)
	table->vkCmdSetRenderingAttachmentLocationsKHR = (PFN_vkCmdSetRenderingAttachmentLocationsKHR)load(context, "vkCmdSetRenderingAttachmentLocationsKHR");
	table->vkCmdSetRenderingInputAttachmentIndicesKHR = (PFN_vkCmdSetRenderingInputAttachmentIndicesKHR)load(context, "vkCmdSetRenderingInputAttachmentIndicesKHR");
#endif /* defined(VK_KHR_dynamic_rendering_local_read) */
#if defined(VK_KHR_external_fence_fd)
	table->vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)load(context, "vkGetFenceFdKHR");
	table->vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)load(context, "vkImportFenceFdKHR");
#endif /* defined(VK_KHR_external_fence_fd) */
#if defined(VK_KHR_external_fence_win32)
	table->vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)load(context, "vkGetFenceWin32HandleKHR");
	table->vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)load(context, "vkImportFenceWin32HandleKHR");
#endif /* defined(VK_KHR_external_fence_win32) */
#if defined(VK_KHR_external_memory_fd)
	table->vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)load(context, "vkGetMemoryFdKHR");
	table->vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)load(context, "vkGetMemoryFdPropertiesKHR");
#endif /* defined(VK_KHR_external_memory_fd) */
#if defined(VK_KHR_external_memory_win32)
	table->vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)load(context, "vkGetMemoryWin32HandleKHR");
	table->vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)load(context, "vkGetMemoryWin32HandlePropertiesKHR");
#endif /* defined(VK_KHR_external_memory_win32) */
#if defined(VK_KHR_external_semaphore_fd)
	table->vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)load(context, "vkGetSemaphoreFdKHR");
	table->vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)load(context, "vkImportSemaphoreFdKHR");
#endif /* defined(VK_KHR_external_semaphore_fd) */
#if defined(VK_KHR_external_semaphore_win32)
	table->vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)load(context, "vkGetSemaphoreWin32HandleKHR");
	table->vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)load(context, "vkImportSemaphoreWin32HandleKHR");
#endif /* defined(VK_KHR_external_semaphore_win32) */
#if defined(VK_KHR_fragment_shading_rate)
	table->vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)load(context, "vkCmdSetFragmentShadingRateKHR");
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_memory_requirements2)
	table->vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)load(context, "vkGetBufferMemoryRequirements2KHR");
	table->vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)load(context, "vkGetImageMemoryRequirements2KHR");
	table->vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)load(context, "vkGetImageSparseMemoryRequirements2KHR");
#endif /* defined(VK_KHR_get_memory_requirements2) */
#if defined(VK_KHR_line_rasterization)
	table->vkCmdSetLineStippleKHR = (PFN_vkCmdSetLineStippleKHR)load(context, "vkCmdSetLineStippleKHR");
#endif /* defined(VK_KHR_line_rasterization) */
#if defined(VK_KHR_maintenance1)
	table->vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)load(context, "vkTrimCommandPoolKHR");
#endif /* defined(VK_KHR_maintenance1) */
#if defined(VK_KHR_maintenance10)
	table->vkCmdEndRendering2KHR = (PFN_vkCmdEndRendering2KHR)load(context, "vkCmdEndRendering2KHR");
#endif /* defined(VK_KHR_maintenance10) */
#if defined(VK_KHR_maintenance3)
	table->vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)load(context, "vkGetDescriptorSetLayoutSupportKHR");
#endif /* defined(VK_KHR_maintenance3) */
#if defined(VK_KHR_maintenance4)
	table->vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR)load(context, "vkGetDeviceBufferMemoryRequirementsKHR");
	table->vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR)load(context, "vkGetDeviceImageMemoryRequirementsKHR");
	table->vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR)load(context, "vkGetDeviceImageSparseMemoryRequirementsKHR");
#endif /* defined(VK_KHR_maintenance4) */
#if defined(VK_KHR_maintenance5)
	table->vkCmdBindIndexBuffer2KHR = (PFN_vkCmdBindIndexBuffer2KHR)load(context, "vkCmdBindIndexBuffer2KHR");
	table->vkGetDeviceImageSubresourceLayoutKHR = (PFN_vkGetDeviceImageSubresourceLayoutKHR)load(context, "vkGetDeviceImageSubresourceLayoutKHR");
	table->vkGetImageSubresourceLayout2KHR = (PFN_vkGetImageSubresourceLayout2KHR)load(context, "vkGetImageSubresourceLayout2KHR");
	table->vkGetRenderingAreaGranularityKHR = (PFN_vkGetRenderingAreaGranularityKHR)load(context, "vkGetRenderingAreaGranularityKHR");
#endif /* defined(VK_KHR_maintenance5) */
#if defined(VK_KHR_maintenance6)
	table->vkCmdBindDescriptorSets2KHR = (PFN_vkCmdBindDescriptorSets2KHR)load(context, "vkCmdBindDescriptorSets2KHR");
	table->vkCmdPushConstants2KHR = (PFN_vkCmdPushConstants2KHR)load(context, "vkCmdPushConstants2KHR");
#endif /* defined(VK_KHR_maintenance6) */
#if defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor)
	table->vkCmdPushDescriptorSet2KHR = (PFN_vkCmdPushDescriptorSet2KHR)load(context, "vkCmdPushDescriptorSet2KHR");
	table->vkCmdPushDescriptorSetWithTemplate2KHR = (PFN_vkCmdPushDescriptorSetWithTemplate2KHR)load(context, "vkCmdPushDescriptorSetWithTemplate2KHR");
#endif /* defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer)
	table->vkCmdBindDescriptorBufferEmbeddedSamplers2EXT = (PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT)load(context, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
	table->vkCmdSetDescriptorBufferOffsets2EXT = (PFN_vkCmdSetDescriptorBufferOffsets2EXT)load(context, "vkCmdSetDescriptorBufferOffsets2EXT");
#endif /* defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_KHR_map_memory2)
	table->vkMapMemory2KHR = (PFN_vkMapMemory2KHR)load(context, "vkMapMemory2KHR");
	table->vkUnmapMemory2KHR = (PFN_vkUnmapMemory2KHR)load(context, "vkUnmapMemory2KHR");
#endif /* defined(VK_KHR_map_memory2) */
#if defined(VK_KHR_performance_query)
	table->vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)load(context, "vkAcquireProfilingLockKHR");
	table->vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)load(context, "vkReleaseProfilingLockKHR");
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_pipeline_binary)
	table->vkCreatePipelineBinariesKHR = (PFN_vkCreatePipelineBinariesKHR)load(context, "vkCreatePipelineBinariesKHR");
	table->vkDestroyPipelineBinaryKHR = (PFN_vkDestroyPipelineBinaryKHR)load(context, "vkDestroyPipelineBinaryKHR");
	table->vkGetPipelineBinaryDataKHR = (PFN_vkGetPipelineBinaryDataKHR)load(context, "vkGetPipelineBinaryDataKHR");
	table->vkGetPipelineKeyKHR = (PFN_vkGetPipelineKeyKHR)load(context, "vkGetPipelineKeyKHR");
	table->vkReleaseCapturedPipelineDataKHR = (PFN_vkReleaseCapturedPipelineDataKHR)load(context, "vkReleaseCapturedPipelineDataKHR");
#endif /* defined(VK_KHR_pipeline_binary) */
#if defined(VK_KHR_pipeline_executable_properties)
	table->vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)load(context, "vkGetPipelineExecutableInternalRepresentationsKHR");
	table->vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)load(context, "vkGetPipelineExecutablePropertiesKHR");
	table->vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)load(context, "vkGetPipelineExecutableStatisticsKHR");
#endif /* defined(VK_KHR_pipeline_executable_properties) */
#if defined(VK_KHR_present_wait)
	table->vkWaitForPresentKHR = (PFN_vkWaitForPresentKHR)load(context, "vkWaitForPresentKHR");
#endif /* defined(VK_KHR_present_wait) */
#if defined(VK_KHR_present_wait2)
	table->vkWaitForPresent2KHR = (PFN_vkWaitForPresent2KHR)load(context, "vkWaitForPresent2KHR");
#endif /* defined(VK_KHR_present_wait2) */
#if defined(VK_KHR_push_descriptor)
	table->vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)load(context, "vkCmdPushDescriptorSetKHR");
#endif /* defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
	table->vkCmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR)load(context, "vkCmdTraceRaysIndirect2KHR");
#endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_ray_tracing_pipeline)
	table->vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)load(context, "vkCmdSetRayTracingPipelineStackSizeKHR");
	table->vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)load(context, "vkCmdTraceRaysIndirectKHR");
	table->vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)load(context, "vkCmdTraceRaysKHR");
	table->vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)load(context, "vkCreateRayTracingPipelinesKHR");
	table->vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)load(context, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
	table->vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)load(context, "vkGetRayTracingShaderGroupHandlesKHR");
	table->vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)load(context, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif /* defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_sampler_ycbcr_conversion)
	table->vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)load(context, "vkCreateSamplerYcbcrConversionKHR");
	table->vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)load(context, "vkDestroySamplerYcbcrConversionKHR");
#endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
#if defined(VK_KHR_shared_presentable_image)
	table->vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)load(context, "vkGetSwapchainStatusKHR");
#endif /* defined(VK_KHR_shared_presentable_image) */
#if defined(VK_KHR_swapchain)
	table->vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)load(context, "vkAcquireNextImageKHR");
	table->vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)load(context, "vkCreateSwapchainKHR");
	table->vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)load(context, "vkDestroySwapchainKHR");
	table->vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)load(context, "vkGetSwapchainImagesKHR");
	table->vkQueuePresentKHR = (PFN_vkQueuePresentKHR)load(context, "vkQueuePresentKHR");
#endif /* defined(VK_KHR_swapchain) */
#if defined(VK_KHR_swapchain_maintenance1)
	table->vkReleaseSwapchainImagesKHR = (PFN_vkReleaseSwapchainImagesKHR)load(context, "vkReleaseSwapchainImagesKHR");
#endif /* defined(VK_KHR_swapchain_maintenance1) */
#if defined(VK_KHR_synchronization2)
	table->vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)load(context, "vkCmdPipelineBarrier2KHR");
	table->vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)load(context, "vkCmdResetEvent2KHR");
	table->vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)load(context, "vkCmdSetEvent2KHR");
	table->vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)load(context, "vkCmdWaitEvents2KHR");
	table->vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)load(context, "vkCmdWriteTimestamp2KHR");
	table->vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)load(context, "vkQueueSubmit2KHR");
#endif /* defined(VK_KHR_synchronization2) */
#if defined(VK_KHR_timeline_semaphore)
	table->vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)load(context, "vkGetSemaphoreCounterValueKHR");
	table->vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)load(context, "vkSignalSemaphoreKHR");
	table->vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)load(context, "vkWaitSemaphoresKHR");
#endif /* defined(VK_KHR_timeline_semaphore) */
#if defined(VK_KHR_video_decode_queue)
	table->vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)load(context, "vkCmdDecodeVideoKHR");
#endif /* defined(VK_KHR_video_decode_queue) */
#if defined(VK_KHR_video_encode_queue)
	table->vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)load(context, "vkCmdEncodeVideoKHR");
	table->vkGetEncodedVideoSessionParametersKHR = (PFN_vkGetEncodedVideoSessionParametersKHR)load(context, "vkGetEncodedVideoSessionParametersKHR");
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
	table->vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)load(context, "vkBindVideoSessionMemoryKHR");
	table->vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)load(context, "vkCmdBeginVideoCodingKHR");
	table->vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)load(context, "vkCmdControlVideoCodingKHR");
	table->vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)load(context, "vkCmdEndVideoCodingKHR");
	table->vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)load(context, "vkCreateVideoSessionKHR");
	table->vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)load(context, "vkCreateVideoSessionParametersKHR");
	table->vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)load(context, "vkDestroyVideoSessionKHR");
	table->vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)load(context, "vkDestroyVideoSessionParametersKHR");
	table->vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)load(context, "vkGetVideoSessionMemoryRequirementsKHR");
	table->vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)load(context, "vkUpdateVideoSessionParametersKHR");
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_NVX_binary_import)
	table->vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)load(context, "vkCmdCuLaunchKernelNVX");
	table->vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)load(context, "vkCreateCuFunctionNVX");
	table->vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)load(context, "vkCreateCuModuleNVX");
	table->vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)load(context, "vkDestroyCuFunctionNVX");
	table->vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)load(context, "vkDestroyCuModuleNVX");
#endif /* defined(VK_NVX_binary_import) */
#if defined(VK_NVX_image_view_handle)
	table->vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)load(context, "vkGetImageViewHandleNVX");
#endif /* defined(VK_NVX_image_view_handle) */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3
	table->vkGetImageViewHandle64NVX = (PFN_vkGetImageViewHandle64NVX)load(context, "vkGetImageViewHandle64NVX");
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3 */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2
	table->vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)load(context, "vkGetImageViewAddressNVX");
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2 */
#if defined(VK_NV_clip_space_w_scaling)
	table->vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)load(context, "vkCmdSetViewportWScalingNV");
#endif /* defined(VK_NV_clip_space_w_scaling) */
#if defined(VK_NV_cluster_acceleration_structure)
	table->vkCmdBuildClusterAccelerationStructureIndirectNV = (PFN_vkCmdBuildClusterAccelerationStructureIndirectNV)load(context, "vkCmdBuildClusterAccelerationStructureIndirectNV");
	table->vkGetClusterAccelerationStructureBuildSizesNV = (PFN_vkGetClusterAccelerationStructureBuildSizesNV)load(context, "vkGetClusterAccelerationStructureBuildSizesNV");
#endif /* defined(VK_NV_cluster_acceleration_structure) */
#if defined(VK_NV_compute_occupancy_priority)
	table->vkCmdSetComputeOccupancyPriorityNV = (PFN_vkCmdSetComputeOccupancyPriorityNV)load(context, "vkCmdSetComputeOccupancyPriorityNV");
#endif /* defined(VK_NV_compute_occupancy_priority) */
#if defined(VK_NV_cooperative_vector)
	table->vkCmdConvertCooperativeVectorMatrixNV = (PFN_vkCmdConvertCooperativeVectorMatrixNV)load(context, "vkCmdConvertCooperativeVectorMatrixNV");
	table->vkConvertCooperativeVectorMatrixNV = (PFN_vkConvertCooperativeVectorMatrixNV)load(context, "vkConvertCooperativeVectorMatrixNV");
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_copy_memory_indirect)
	table->vkCmdCopyMemoryIndirectNV = (PFN_vkCmdCopyMemoryIndirectNV)load(context, "vkCmdCopyMemoryIndirectNV");
	table->vkCmdCopyMemoryToImageIndirectNV = (PFN_vkCmdCopyMemoryToImageIndirectNV)load(context, "vkCmdCopyMemoryToImageIndirectNV");
#endif /* defined(VK_NV_copy_memory_indirect) */
#if defined(VK_NV_cuda_kernel_launch)
	table->vkCmdCudaLaunchKernelNV = (PFN_vkCmdCudaLaunchKernelNV)load(context, "vkCmdCudaLaunchKernelNV");
	table->vkCreateCudaFunctionNV = (PFN_vkCreateCudaFunctionNV)load(context, "vkCreateCudaFunctionNV");
	table->vkCreateCudaModuleNV = (PFN_vkCreateCudaModuleNV)load(context, "vkCreateCudaModuleNV");
	table->vkDestroyCudaFunctionNV = (PFN_vkDestroyCudaFunctionNV)load(context, "vkDestroyCudaFunctionNV");
	table->vkDestroyCudaModuleNV = (PFN_vkDestroyCudaModuleNV)load(context, "vkDestroyCudaModuleNV");
	table->vkGetCudaModuleCacheNV = (PFN_vkGetCudaModuleCacheNV)load(context, "vkGetCudaModuleCacheNV");
#endif /* defined(VK_NV_cuda_kernel_launch) */
#if defined(VK_NV_device_diagnostic_checkpoints)
	table->vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)load(context, "vkCmdSetCheckpointNV");
	table->vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)load(context, "vkGetQueueCheckpointDataNV");
#endif /* defined(VK_NV_device_diagnostic_checkpoints) */
#if defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
	table->vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)load(context, "vkGetQueueCheckpointData2NV");
#endif /* defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_NV_device_generated_commands)
	table->vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)load(context, "vkCmdBindPipelineShaderGroupNV");
	table->vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)load(context, "vkCmdExecuteGeneratedCommandsNV");
	table->vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)load(context, "vkCmdPreprocessGeneratedCommandsNV");
	table->vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)load(context, "vkCreateIndirectCommandsLayoutNV");
	table->vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)load(context, "vkDestroyIndirectCommandsLayoutNV");
	table->vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)load(context, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif /* defined(VK_NV_device_generated_commands) */
#if defined(VK_NV_device_generated_commands_compute)
	table->vkCmdUpdatePipelineIndirectBufferNV = (PFN_vkCmdUpdatePipelineIndirectBufferNV)load(context, "vkCmdUpdatePipelineIndirectBufferNV");
	table->vkGetPipelineIndirectDeviceAddressNV = (PFN_vkGetPipelineIndirectDeviceAddressNV)load(context, "vkGetPipelineIndirectDeviceAddressNV");
	table->vkGetPipelineIndirectMemoryRequirementsNV = (PFN_vkGetPipelineIndirectMemoryRequirementsNV)load(context, "vkGetPipelineIndirectMemoryRequirementsNV");
#endif /* defined(VK_NV_device_generated_commands_compute) */
#if defined(VK_NV_external_compute_queue)
	table->vkCreateExternalComputeQueueNV = (PFN_vkCreateExternalComputeQueueNV)load(context, "vkCreateExternalComputeQueueNV");
	table->vkDestroyExternalComputeQueueNV = (PFN_vkDestroyExternalComputeQueueNV)load(context, "vkDestroyExternalComputeQueueNV");
	table->vkGetExternalComputeQueueDataNV = (PFN_vkGetExternalComputeQueueDataNV)load(context, "vkGetExternalComputeQueueDataNV");
#endif /* defined(VK_NV_external_compute_queue) */
#if defined(VK_NV_external_memory_rdma)
	table->vkGetMemoryRemoteAddressNV = (PFN_vkGetMemoryRemoteAddressNV)load(context, "vkGetMemoryRemoteAddressNV");
#endif /* defined(VK_NV_external_memory_rdma) */
#if defined(VK_NV_external_memory_win32)
	table->vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)load(context, "vkGetMemoryWin32HandleNV");
#endif /* defined(VK_NV_external_memory_win32) */
#if defined(VK_NV_fragment_shading_rate_enums)
	table->vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)load(context, "vkCmdSetFragmentShadingRateEnumNV");
#endif /* defined(VK_NV_fragment_shading_rate_enums) */
#if defined(VK_NV_low_latency2)
	table->vkGetLatencyTimingsNV = (PFN_vkGetLatencyTimingsNV)load(context, "vkGetLatencyTimingsNV");
	table->vkLatencySleepNV = (PFN_vkLatencySleepNV)load(context, "vkLatencySleepNV");
	table->vkQueueNotifyOutOfBandNV = (PFN_vkQueueNotifyOutOfBandNV)load(context, "vkQueueNotifyOutOfBandNV");
	table->vkSetLatencyMarkerNV = (PFN_vkSetLatencyMarkerNV)load(context, "vkSetLatencyMarkerNV");
	table->vkSetLatencySleepModeNV = (PFN_vkSetLatencySleepModeNV)load(context, "vkSetLatencySleepModeNV");
#endif /* defined(VK_NV_low_latency2) */
#if defined(VK_NV_memory_decompression)
	table->vkCmdDecompressMemoryIndirectCountNV = (PFN_vkCmdDecompressMemoryIndirectCountNV)load(context, "vkCmdDecompressMemoryIndirectCountNV");
	table->vkCmdDecompressMemoryNV = (PFN_vkCmdDecompressMemoryNV)load(context, "vkCmdDecompressMemoryNV");
#endif /* defined(VK_NV_memory_decompression) */
#if defined(VK_NV_mesh_shader)
	table->vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)load(context, "vkCmdDrawMeshTasksIndirectNV");
	table->vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)load(context, "vkCmdDrawMeshTasksNV");
#endif /* defined(VK_NV_mesh_shader) */
#if defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
	table->vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)load(context, "vkCmdDrawMeshTasksIndirectCountNV");
#endif /* defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_NV_optical_flow)
	table->vkBindOpticalFlowSessionImageNV = (PFN_vkBindOpticalFlowSessionImageNV)load(context, "vkBindOpticalFlowSessionImageNV");
	table->vkCmdOpticalFlowExecuteNV = (PFN_vkCmdOpticalFlowExecuteNV)load(context, "vkCmdOpticalFlowExecuteNV");
	table->vkCreateOpticalFlowSessionNV = (PFN_vkCreateOpticalFlowSessionNV)load(context, "vkCreateOpticalFlowSessionNV");
	table->vkDestroyOpticalFlowSessionNV = (PFN_vkDestroyOpticalFlowSessionNV)load(context, "vkDestroyOpticalFlowSessionNV");
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_NV_partitioned_acceleration_structure)
	table->vkCmdBuildPartitionedAccelerationStructuresNV = (PFN_vkCmdBuildPartitionedAccelerationStructuresNV)load(context, "vkCmdBuildPartitionedAccelerationStructuresNV");
	table->vkGetPartitionedAccelerationStructuresBuildSizesNV = (PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV)load(context, "vkGetPartitionedAccelerationStructuresBuildSizesNV");
#endif /* defined(VK_NV_partitioned_acceleration_structure) */
#if defined(VK_NV_ray_tracing)
	table->vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)load(context, "vkBindAccelerationStructureMemoryNV");
	table->vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)load(context, "vkCmdBuildAccelerationStructureNV");
	table->vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)load(context, "vkCmdCopyAccelerationStructureNV");
	table->vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)load(context, "vkCmdTraceRaysNV");
	table->vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)load(context, "vkCmdWriteAccelerationStructuresPropertiesNV");
	table->vkCompileDeferredNV = (PFN_vkCompileDeferredNV)load(context, "vkCompileDeferredNV");
	table->vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)load(context, "vkCreateAccelerationStructureNV");
	table->vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)load(context, "vkCreateRayTracingPipelinesNV");
	table->vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)load(context, "vkDestroyAccelerationStructureNV");
	table->vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)load(context, "vkGetAccelerationStructureHandleNV");
	table->vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)load(context, "vkGetAccelerationStructureMemoryRequirementsNV");
	table->vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)load(context, "vkGetRayTracingShaderGroupHandlesNV");
#endif /* defined(VK_NV_ray_tracing) */
#if defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2
	table->vkCmdSetExclusiveScissorEnableNV = (PFN_vkCmdSetExclusiveScissorEnableNV)load(context, "vkCmdSetExclusiveScissorEnableNV");
#endif /* defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2 */
#if defined(VK_NV_scissor_exclusive)
	table->vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)load(context, "vkCmdSetExclusiveScissorNV");
#endif /* defined(VK_NV_scissor_exclusive) */
#if defined(VK_NV_shading_rate_image)
	table->vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)load(context, "vkCmdBindShadingRateImageNV");
	table->vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)load(context, "vkCmdSetCoarseSampleOrderNV");
	table->vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)load(context, "vkCmdSetViewportShadingRatePaletteNV");
#endif /* defined(VK_NV_shading_rate_image) */
#if defined(VK_OHOS_external_memory)
	table->vkGetMemoryNativeBufferOHOS = (PFN_vkGetMemoryNativeBufferOHOS)load(context, "vkGetMemoryNativeBufferOHOS");
	table->vkGetNativeBufferPropertiesOHOS = (PFN_vkGetNativeBufferPropertiesOHOS)load(context, "vkGetNativeBufferPropertiesOHOS");
#endif /* defined(VK_OHOS_external_memory) */
#if defined(VK_QCOM_tile_memory_heap)
	table->vkCmdBindTileMemoryQCOM = (PFN_vkCmdBindTileMemoryQCOM)load(context, "vkCmdBindTileMemoryQCOM");
#endif /* defined(VK_QCOM_tile_memory_heap) */
#if defined(VK_QCOM_tile_properties)
	table->vkGetDynamicRenderingTilePropertiesQCOM = (PFN_vkGetDynamicRenderingTilePropertiesQCOM)load(context, "vkGetDynamicRenderingTilePropertiesQCOM");
	table->vkGetFramebufferTilePropertiesQCOM = (PFN_vkGetFramebufferTilePropertiesQCOM)load(context, "vkGetFramebufferTilePropertiesQCOM");
#endif /* defined(VK_QCOM_tile_properties) */
#if defined(VK_QCOM_tile_shading)
	table->vkCmdBeginPerTileExecutionQCOM = (PFN_vkCmdBeginPerTileExecutionQCOM)load(context, "vkCmdBeginPerTileExecutionQCOM");
	table->vkCmdDispatchTileQCOM = (PFN_vkCmdDispatchTileQCOM)load(context, "vkCmdDispatchTileQCOM");
	table->vkCmdEndPerTileExecutionQCOM = (PFN_vkCmdEndPerTileExecutionQCOM)load(context, "vkCmdEndPerTileExecutionQCOM");
#endif /* defined(VK_QCOM_tile_shading) */
#if defined(VK_QNX_external_memory_screen_buffer)
	table->vkGetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX)load(context, "vkGetScreenBufferPropertiesQNX");
#endif /* defined(VK_QNX_external_memory_screen_buffer) */
#if defined(VK_VALVE_descriptor_set_host_mapping)
	table->vkGetDescriptorSetHostMappingVALVE = (PFN_vkGetDescriptorSetHostMappingVALVE)load(context, "vkGetDescriptorSetHostMappingVALVE");
	table->vkGetDescriptorSetLayoutHostMappingInfoVALVE = (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE)load(context, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
#endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
#if (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control))
	table->vkCmdSetDepthClampRangeEXT = (PFN_vkCmdSetDepthClampRangeEXT)load(context, "vkCmdSetDepthClampRangeEXT");
#endif /* (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control)) */
#if (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object))
	table->vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)load(context, "vkCmdBindVertexBuffers2EXT");
	table->vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)load(context, "vkCmdSetCullModeEXT");
	table->vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)load(context, "vkCmdSetDepthBoundsTestEnableEXT");
	table->vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)load(context, "vkCmdSetDepthCompareOpEXT");
	table->vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)load(context, "vkCmdSetDepthTestEnableEXT");
	table->vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)load(context, "vkCmdSetDepthWriteEnableEXT");
	table->vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)load(context, "vkCmdSetFrontFaceEXT");
	table->vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)load(context, "vkCmdSetPrimitiveTopologyEXT");
	table->vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)load(context, "vkCmdSetScissorWithCountEXT");
	table->vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)load(context, "vkCmdSetStencilOpEXT");
	table->vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)load(context, "vkCmdSetStencilTestEnableEXT");
	table->vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)load(context, "vkCmdSetViewportWithCountEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object))
	table->vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)load(context, "vkCmdSetDepthBiasEnableEXT");
	table->vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)load(context, "vkCmdSetLogicOpEXT");
	table->vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)load(context, "vkCmdSetPatchControlPointsEXT");
	table->vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)load(context, "vkCmdSetPrimitiveRestartEnableEXT");
	table->vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)load(context, "vkCmdSetRasterizerDiscardEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object))
	table->vkCmdSetAlphaToCoverageEnableEXT = (PFN_vkCmdSetAlphaToCoverageEnableEXT)load(context, "vkCmdSetAlphaToCoverageEnableEXT");
	table->vkCmdSetAlphaToOneEnableEXT = (PFN_vkCmdSetAlphaToOneEnableEXT)load(context, "vkCmdSetAlphaToOneEnableEXT");
	table->vkCmdSetColorBlendEnableEXT = (PFN_vkCmdSetColorBlendEnableEXT)load(context, "vkCmdSetColorBlendEnableEXT");
	table->vkCmdSetColorBlendEquationEXT = (PFN_vkCmdSetColorBlendEquationEXT)load(context, "vkCmdSetColorBlendEquationEXT");
	table->vkCmdSetColorWriteMaskEXT = (PFN_vkCmdSetColorWriteMaskEXT)load(context, "vkCmdSetColorWriteMaskEXT");
	table->vkCmdSetDepthClampEnableEXT = (PFN_vkCmdSetDepthClampEnableEXT)load(context, "vkCmdSetDepthClampEnableEXT");
	table->vkCmdSetLogicOpEnableEXT = (PFN_vkCmdSetLogicOpEnableEXT)load(context, "vkCmdSetLogicOpEnableEXT");
	table->vkCmdSetPolygonModeEXT = (PFN_vkCmdSetPolygonModeEXT)load(context, "vkCmdSetPolygonModeEXT");
	table->vkCmdSetRasterizationSamplesEXT = (PFN_vkCmdSetRasterizationSamplesEXT)load(context, "vkCmdSetRasterizationSamplesEXT");
	table->vkCmdSetSampleMaskEXT = (PFN_vkCmdSetSampleMaskEXT)load(context, "vkCmdSetSampleMaskEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object))
	table->vkCmdSetTessellationDomainOriginEXT = (PFN_vkCmdSetTessellationDomainOriginEXT)load(context, "vkCmdSetTessellationDomainOriginEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback))
	table->vkCmdSetRasterizationStreamEXT = (PFN_vkCmdSetRasterizationStreamEXT)load(context, "vkCmdSetRasterizationStreamEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization))
	table->vkCmdSetConservativeRasterizationModeEXT = (PFN_vkCmdSetConservativeRasterizationModeEXT)load(context, "vkCmdSetConservativeRasterizationModeEXT");
	table->vkCmdSetExtraPrimitiveOverestimationSizeEXT = (PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT)load(context, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable))
	table->vkCmdSetDepthClipEnableEXT = (PFN_vkCmdSetDepthClipEnableEXT)load(context, "vkCmdSetDepthClipEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations))
	table->vkCmdSetSampleLocationsEnableEXT = (PFN_vkCmdSetSampleLocationsEnableEXT)load(context, "vkCmdSetSampleLocationsEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced))
	table->vkCmdSetColorBlendAdvancedEXT = (PFN_vkCmdSetColorBlendAdvancedEXT)load(context, "vkCmdSetColorBlendAdvancedEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex))
	table->vkCmdSetProvokingVertexModeEXT = (PFN_vkCmdSetProvokingVertexModeEXT)load(context, "vkCmdSetProvokingVertexModeEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization))
	table->vkCmdSetLineRasterizationModeEXT = (PFN_vkCmdSetLineRasterizationModeEXT)load(context, "vkCmdSetLineRasterizationModeEXT");
	table->vkCmdSetLineStippleEnableEXT = (PFN_vkCmdSetLineStippleEnableEXT)load(context, "vkCmdSetLineStippleEnableEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control))
	table->vkCmdSetDepthClipNegativeOneToOneEXT = (PFN_vkCmdSetDepthClipNegativeOneToOneEXT)load(context, "vkCmdSetDepthClipNegativeOneToOneEXT");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling))
	table->vkCmdSetViewportWScalingEnableNV = (PFN_vkCmdSetViewportWScalingEnableNV)load(context, "vkCmdSetViewportWScalingEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle))
	table->vkCmdSetViewportSwizzleNV = (PFN_vkCmdSetViewportSwizzleNV)load(context, "vkCmdSetViewportSwizzleNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color))
	table->vkCmdSetCoverageToColorEnableNV = (PFN_vkCmdSetCoverageToColorEnableNV)load(context, "vkCmdSetCoverageToColorEnableNV");
	table->vkCmdSetCoverageToColorLocationNV = (PFN_vkCmdSetCoverageToColorLocationNV)load(context, "vkCmdSetCoverageToColorLocationNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples))
	table->vkCmdSetCoverageModulationModeNV = (PFN_vkCmdSetCoverageModulationModeNV)load(context, "vkCmdSetCoverageModulationModeNV");
	table->vkCmdSetCoverageModulationTableEnableNV = (PFN_vkCmdSetCoverageModulationTableEnableNV)load(context, "vkCmdSetCoverageModulationTableEnableNV");
	table->vkCmdSetCoverageModulationTableNV = (PFN_vkCmdSetCoverageModulationTableNV)load(context, "vkCmdSetCoverageModulationTableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image))
	table->vkCmdSetShadingRateImageEnableNV = (PFN_vkCmdSetShadingRateImageEnableNV)load(context, "vkCmdSetShadingRateImageEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test))
	table->vkCmdSetRepresentativeFragmentTestEnableNV = (PFN_vkCmdSetRepresentativeFragmentTestEnableNV)load(context, "vkCmdSetRepresentativeFragmentTestEnableNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode))
	table->vkCmdSetCoverageReductionModeNV = (PFN_vkCmdSetCoverageReductionModeNV)load(context, "vkCmdSetCoverageReductionModeNV");
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode)) */
#if (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control))
	table->vkGetImageSubresourceLayout2EXT = (PFN_vkGetImageSubresourceLayout2EXT)load(context, "vkGetImageSubresourceLayout2EXT");
#endif /* (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control)) */
#if (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state))
	table->vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)load(context, "vkCmdSetVertexInputEXT");
#endif /* (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state)) */
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)))
	table->vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)load(context, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template))) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	table->vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)load(context, "vkGetDeviceGroupPresentCapabilitiesKHR");
	table->vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)load(context, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
	table->vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)load(context, "vkAcquireNextImage2KHR");
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
	/* VOLK_GENERATE_LOAD_DEVICE_TABLE */
}

#ifdef __GNUC__
#ifdef VOLK_DEFAULT_VISIBILITY
#	pragma GCC visibility push(default)
#else
#	pragma GCC visibility push(hidden)
#endif
#endif

#ifdef VOLK_IN_LOADERS_CLOTH

/* VOLK_GENERATE_PROTOTYPES_C_VILC */
#if defined(VK_VERSION_1_0)
VkResult vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) {
	vilc_initOnce();
	return vilc_vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
}
VkResult vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) {
	vilc_initOnce();
	return vilc_vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}
VkResult vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
	vilc_initOnce();
	return vilc_vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}
VkResult vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
	vilc_initOnce();
	return vilc_vkBeginCommandBuffer(commandBuffer, pBeginInfo);
}
VkResult vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
	vilc_initOnce();
	return vilc_vkBindBufferMemory(device, buffer, memory, memoryOffset);
}
VkResult vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
	vilc_initOnce();
	return vilc_vkBindImageMemory(device, image, memory, memoryOffset);
}
void vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) {
	vilc_initOnce();
	vilc_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
}
void vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) {
	vilc_initOnce();
	vilc_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
void vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) {
	vilc_initOnce();
	vilc_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
void vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
	vilc_initOnce();
	vilc_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
void vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
	vilc_initOnce();
	vilc_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}
void vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
	vilc_initOnce();
	vilc_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
void vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) {
	vilc_initOnce();
	vilc_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
void vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) {
	vilc_initOnce();
	vilc_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
void vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
	vilc_initOnce();
	vilc_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
void vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
	vilc_initOnce();
	vilc_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
void vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) {
	vilc_initOnce();
	vilc_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
void vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
	vilc_initOnce();
	vilc_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
void vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) {
	vilc_initOnce();
	vilc_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
	vilc_initOnce();
	vilc_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
void vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
	vilc_initOnce();
	vilc_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
void vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	vilc_initOnce();
	vilc_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
	vilc_initOnce();
	vilc_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
}
void vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
	vilc_initOnce();
	vilc_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
void vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
	vilc_initOnce();
	vilc_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
void vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
	vilc_initOnce();
	vilc_vkCmdEndQuery(commandBuffer, queryPool, query);
}
void vkCmdEndRenderPass(VkCommandBuffer commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdEndRenderPass(commandBuffer);
}
void vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
	vilc_initOnce();
	vilc_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
void vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
	vilc_initOnce();
	vilc_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
void vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
	vilc_initOnce();
	vilc_vkCmdNextSubpass(commandBuffer, contents);
}
void vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
	vilc_initOnce();
	vilc_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
void vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) {
	vilc_initOnce();
	vilc_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
void vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
	vilc_initOnce();
	vilc_vkCmdResetEvent(commandBuffer, event, stageMask);
}
void vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
	vilc_initOnce();
	vilc_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
void vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) {
	vilc_initOnce();
	vilc_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
	vilc_initOnce();
	vilc_vkCmdSetBlendConstants(commandBuffer, blendConstants);
}
void vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
void vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
void vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
	vilc_initOnce();
	vilc_vkCmdSetEvent(commandBuffer, event, stageMask);
}
void vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
	vilc_initOnce();
	vilc_vkCmdSetLineWidth(commandBuffer, lineWidth);
}
void vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) {
	vilc_initOnce();
	vilc_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
void vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) {
	vilc_initOnce();
	vilc_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
void vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
	vilc_initOnce();
	vilc_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
}
void vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
	vilc_initOnce();
	vilc_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
void vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) {
	vilc_initOnce();
	vilc_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
void vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) {
	vilc_initOnce();
	vilc_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
void vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
	vilc_initOnce();
	vilc_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
void vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) {
	vilc_initOnce();
	vilc_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
VkResult vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) {
	vilc_initOnce();
	return vilc_vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}
VkResult vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
	vilc_initOnce();
	return vilc_vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
}
VkResult vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
	vilc_initOnce();
	return vilc_vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}
VkResult vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
	vilc_initOnce();
	return vilc_vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
VkResult vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
	vilc_initOnce();
	return vilc_vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}
VkResult vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) {
	vilc_initOnce();
	return vilc_vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}
VkResult vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
	vilc_initOnce();
	VkResult result = vilc_vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
	if(result == VK_SUCCESS) {
		loadedDevice = *pDevice;
		volkGenLoadDevice(loadedDevice, vkGetDeviceProcAddrStub);
	}
	return result;
}
VkResult vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
	vilc_initOnce();
	return vilc_vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
}
VkResult vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
	vilc_initOnce();
	return vilc_vkCreateFence(device, pCreateInfo, pAllocator, pFence);
}
VkResult vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
	vilc_initOnce();
	return vilc_vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}
VkResult vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
	vilc_initOnce();
	return vilc_vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
VkResult vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) {
	vilc_initOnce();
	return vilc_vkCreateImage(device, pCreateInfo, pAllocator, pImage);
}
VkResult vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
	vilc_initOnce();
	return vilc_vkCreateImageView(device, pCreateInfo, pAllocator, pView);
}
VkResult vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
	vilc_initOnce();
	VkResult result = vilc_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
	if(result == VK_SUCCESS) {
		loadedInstance = *pInstance;
		volkGenLoadInstance(loadedInstance, vkGetInstanceProcAddrStub);
		volkGenLoadDevice(loadedInstance, vkGetInstanceProcAddrStub);
	}
	return result;
}
VkResult vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) {
	vilc_initOnce();
	return vilc_vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
}
VkResult vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) {
	vilc_initOnce();
	return vilc_vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}
VkResult vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
	vilc_initOnce();
	return vilc_vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
}
VkResult vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
	vilc_initOnce();
	return vilc_vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}
VkResult vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
	vilc_initOnce();
	return vilc_vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
}
VkResult vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
	vilc_initOnce();
	return vilc_vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
}
VkResult vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
	vilc_initOnce();
	return vilc_vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}
void vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyBuffer(device, buffer, pAllocator);
}
void vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyBufferView(device, bufferView, pAllocator);
}
void vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyCommandPool(device, commandPool, pAllocator);
}
void vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
}
void vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}
void vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDevice(device, pAllocator);
}
void vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyEvent(device, event, pAllocator);
}
void vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyFence(device, fence, pAllocator);
}
void vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyFramebuffer(device, framebuffer, pAllocator);
}
void vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyImage(device, image, pAllocator);
}
void vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyImageView(device, imageView, pAllocator);
}
void vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyInstance(instance, pAllocator);
}
void vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyPipeline(device, pipeline, pAllocator);
}
void vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
}
void vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
}
void vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyQueryPool(device, queryPool, pAllocator);
}
void vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyRenderPass(device, renderPass, pAllocator);
}
void vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroySampler(device, sampler, pAllocator);
}
void vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroySemaphore(device, semaphore, pAllocator);
}
void vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyShaderModule(device, shaderModule, pAllocator);
}
VkResult vkDeviceWaitIdle(VkDevice device) {
	vilc_initOnce();
	return vilc_vkDeviceWaitIdle(device);
}
VkResult vkEndCommandBuffer(VkCommandBuffer commandBuffer) {
	vilc_initOnce();
	return vilc_vkEndCommandBuffer(commandBuffer);
}
VkResult vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) {
	vilc_initOnce();
	return vilc_vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
}
VkResult vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) {
	vilc_initOnce();
	return vilc_vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
}
VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) {
	vilc_initOnce();
	return vilc_vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}
VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) {
	vilc_initOnce();
	return vilc_vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}
VkResult vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) {
	vilc_initOnce();
	return vilc_vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
}
VkResult vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
	vilc_initOnce();
	return vilc_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}
void vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
	vilc_initOnce();
	vilc_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}
VkResult vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
	vilc_initOnce();
	return vilc_vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}
void vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkFreeMemory(device, memory, pAllocator);
}
void vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}
void vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) {
	vilc_initOnce();
	vilc_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}
PFN_vkVoidFunction vkGetDeviceProcAddr(VkDevice device, const char* pName) {
	vilc_initOnce();
	return vilc_vkGetDeviceProcAddr(device, pName);
}
void vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
	vilc_initOnce();
	vilc_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}
VkResult vkGetEventStatus(VkDevice device, VkEvent event) {
	vilc_initOnce();
	return vilc_vkGetEventStatus(device, event);
}
VkResult vkGetFenceStatus(VkDevice device, VkFence fence) {
	vilc_initOnce();
	return vilc_vkGetFenceStatus(device, fence);
}
void vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
}
void vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
void vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) {
	vilc_initOnce();
	vilc_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
}
PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char* pName) {
	vilc_initOnce();
	return vilc_vkGetInstanceProcAddr(instance, pName);
}
void vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}
void vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}
VkResult vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
}
void vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}
void vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
}
void vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
void vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}
VkResult vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
}
VkResult vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
	vilc_initOnce();
	return vilc_vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}
void vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) {
	vilc_initOnce();
	vilc_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
}
VkResult vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
	vilc_initOnce();
	return vilc_vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}
VkResult vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) {
	vilc_initOnce();
	return vilc_vkMapMemory(device, memory, offset, size, flags, ppData);
}
VkResult vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) {
	vilc_initOnce();
	return vilc_vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
}
VkResult vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) {
	vilc_initOnce();
	return vilc_vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}
VkResult vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
	vilc_initOnce();
	return vilc_vkQueueSubmit(queue, submitCount, pSubmits, fence);
}
VkResult vkQueueWaitIdle(VkQueue queue) {
	vilc_initOnce();
	return vilc_vkQueueWaitIdle(queue);
}
VkResult vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
	vilc_initOnce();
	return vilc_vkResetCommandBuffer(commandBuffer, flags);
}
VkResult vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
	vilc_initOnce();
	return vilc_vkResetCommandPool(device, commandPool, flags);
}
VkResult vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) {
	vilc_initOnce();
	return vilc_vkResetDescriptorPool(device, descriptorPool, flags);
}
VkResult vkResetEvent(VkDevice device, VkEvent event) {
	vilc_initOnce();
	return vilc_vkResetEvent(device, event);
}
VkResult vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) {
	vilc_initOnce();
	return vilc_vkResetFences(device, fenceCount, pFences);
}
VkResult vkSetEvent(VkDevice device, VkEvent event) {
	vilc_initOnce();
	return vilc_vkSetEvent(device, event);
}
void vkUnmapMemory(VkDevice device, VkDeviceMemory memory) {
	vilc_initOnce();
	vilc_vkUnmapMemory(device, memory);
}
void vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) {
	vilc_initOnce();
	vilc_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}
VkResult vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) {
	vilc_initOnce();
	return vilc_vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
VkResult vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
}
VkResult vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindImageMemory2(device, bindInfoCount, pBindInfos);
}
void vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	vilc_initOnce();
	vilc_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
	vilc_initOnce();
	vilc_vkCmdSetDeviceMask(commandBuffer, deviceMask);
}
VkResult vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
	vilc_initOnce();
	return vilc_vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}
VkResult vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
	vilc_initOnce();
	return vilc_vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
}
void vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
}
void vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
}
VkResult vkEnumerateInstanceVersion(uint32_t* pApiVersion) {
	vilc_initOnce();
	return vilc_vkEnumerateInstanceVersion(pApiVersion);
}
VkResult vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
	vilc_initOnce();
	return vilc_vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
}
void vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
void vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
	vilc_initOnce();
	vilc_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
}
void vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
	vilc_initOnce();
	vilc_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
void vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
	vilc_initOnce();
	vilc_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
}
void vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
void vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
void vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
void vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
void vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
void vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}
void vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}
VkResult vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}
void vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
}
void vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
}
void vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
void vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}
void vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
	vilc_initOnce();
	vilc_vkTrimCommandPool(device, commandPool, flags);
}
void vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
	vilc_initOnce();
	vilc_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
}
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_2)
void vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) {
	vilc_initOnce();
	vilc_vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
void vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) {
	vilc_initOnce();
	vilc_vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
VkResult vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
	vilc_initOnce();
	return vilc_vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
}
VkDeviceAddress vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetBufferDeviceAddress(device, pInfo);
}
uint64_t vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetBufferOpaqueCaptureAddress(device, pInfo);
}
uint64_t vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
}
VkResult vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
	vilc_initOnce();
	return vilc_vkGetSemaphoreCounterValue(device, semaphore, pValue);
}
void vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
	vilc_initOnce();
	vilc_vkResetQueryPool(device, queryPool, firstQuery, queryCount);
}
VkResult vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
	vilc_initOnce();
	return vilc_vkSignalSemaphore(device, pSignalInfo);
}
VkResult vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
	vilc_initOnce();
	return vilc_vkWaitSemaphores(device, pWaitInfo, timeout);
}
#endif /* defined(VK_VERSION_1_2) */
#if defined(VK_VERSION_1_3)
void vkCmdBeginRendering(VkCommandBuffer                   commandBuffer, const VkRenderingInfo*                              pRenderingInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginRendering(commandBuffer, pRenderingInfo);
}
void vkCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
	vilc_initOnce();
	vilc_vkCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void vkCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
	vilc_initOnce();
	vilc_vkCmdBlitImage2(commandBuffer, pBlitImageInfo);
}
void vkCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}
void vkCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}
void vkCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyImage2(commandBuffer, pCopyImageInfo);
}
void vkCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}
void vkCmdEndRendering(VkCommandBuffer                   commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdEndRendering(commandBuffer);
}
void vkCmdPipelineBarrier2(VkCommandBuffer                   commandBuffer, const VkDependencyInfo*                             pDependencyInfo) {
	vilc_initOnce();
	vilc_vkCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}
void vkCmdResetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, VkPipelineStageFlags2               stageMask) {
	vilc_initOnce();
	vilc_vkCmdResetEvent2(commandBuffer, event, stageMask);
}
void vkCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
	vilc_initOnce();
	vilc_vkCmdResolveImage2(commandBuffer, pResolveImageInfo);
}
void vkCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
	vilc_initOnce();
	vilc_vkCmdSetCullMode(commandBuffer, cullMode);
}
void vkCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}
void vkCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}
void vkCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
	vilc_initOnce();
	vilc_vkCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}
void vkCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}
void vkCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}
void vkCmdSetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, const VkDependencyInfo*                             pDependencyInfo) {
	vilc_initOnce();
	vilc_vkCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}
void vkCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
	vilc_initOnce();
	vilc_vkCmdSetFrontFace(commandBuffer, frontFace);
}
void vkCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
	vilc_initOnce();
	vilc_vkCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}
void vkCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
	vilc_initOnce();
	vilc_vkCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}
void vkCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
	vilc_initOnce();
	vilc_vkCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}
void vkCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
	vilc_initOnce();
	vilc_vkCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}
void vkCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
	vilc_initOnce();
	vilc_vkCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void vkCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}
void vkCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
	vilc_initOnce();
	vilc_vkCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}
void vkCmdWaitEvents2(VkCommandBuffer                   commandBuffer, uint32_t                                            eventCount, const VkEvent*                     pEvents, const VkDependencyInfo*            pDependencyInfos) {
	vilc_initOnce();
	vilc_vkCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void vkCmdWriteTimestamp2(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkQueryPool                                         queryPool, uint32_t                                            query) {
	vilc_initOnce();
	vilc_vkCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}
VkResult vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
	vilc_initOnce();
	return vilc_vkCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
}
void vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
}
void vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
}
void vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
}
void vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
VkResult vkGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
}
void vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
	vilc_initOnce();
	vilc_vkGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
}
VkResult vkQueueSubmit2(VkQueue                           queue, uint32_t                            submitCount, const VkSubmitInfo2*              pSubmits, VkFence           fence) {
	vilc_initOnce();
	return vilc_vkQueueSubmit2(queue, submitCount, pSubmits, fence);
}
VkResult vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
	vilc_initOnce();
	return vilc_vkSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
}
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_VERSION_1_4)
void vkCmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo*   pBindDescriptorSetsInfo) {
	vilc_initOnce();
	vilc_vkCmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo);
}
void vkCmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
	vilc_initOnce();
	vilc_vkCmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType);
}
void vkCmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo*        pPushConstantsInfo) {
	vilc_initOnce();
	vilc_vkCmdPushConstants2(commandBuffer, pPushConstantsInfo);
}
void vkCmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
void vkCmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo*    pPushDescriptorSetInfo) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo);
}
void vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
void vkCmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSetWithTemplate2(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
void vkCmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
	vilc_initOnce();
	vilc_vkCmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
}
void vkCmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) {
	vilc_initOnce();
	vilc_vkCmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo);
}
void vkCmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
	vilc_initOnce();
	vilc_vkCmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo);
}
VkResult vkCopyImageToImage(VkDevice device, const VkCopyImageToImageInfo*    pCopyImageToImageInfo) {
	vilc_initOnce();
	return vilc_vkCopyImageToImage(device, pCopyImageToImageInfo);
}
VkResult vkCopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo*    pCopyImageToMemoryInfo) {
	vilc_initOnce();
	return vilc_vkCopyImageToMemory(device, pCopyImageToMemoryInfo);
}
VkResult vkCopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo*    pCopyMemoryToImageInfo) {
	vilc_initOnce();
	return vilc_vkCopyMemoryToImage(device, pCopyMemoryToImageInfo);
}
void vkGetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) {
	vilc_initOnce();
	vilc_vkGetDeviceImageSubresourceLayout(device, pInfo, pLayout);
}
void vkGetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
	vilc_initOnce();
	vilc_vkGetImageSubresourceLayout2(device, image, pSubresource, pLayout);
}
void vkGetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) {
	vilc_initOnce();
	vilc_vkGetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity);
}
VkResult vkMapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
	vilc_initOnce();
	return vilc_vkMapMemory2(device, pMemoryMapInfo, ppData);
}
VkResult vkTransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo*    pTransitions) {
	vilc_initOnce();
	return vilc_vkTransitionImageLayout(device, transitionCount, pTransitions);
}
VkResult vkUnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
	vilc_initOnce();
	return vilc_vkUnmapMemory2(device, pMemoryUnmapInfo);
}
#endif /* defined(VK_VERSION_1_4) */
#if defined(VK_AMDX_shader_enqueue)
void vkCmdDispatchGraphAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, const VkDispatchGraphCountInfoAMDX*             pCountInfo) {
	vilc_initOnce();
	vilc_vkCmdDispatchGraphAMDX(commandBuffer, scratch, scratchSize, pCountInfo);
}
void vkCmdDispatchGraphIndirectAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, const VkDispatchGraphCountInfoAMDX*             pCountInfo) {
	vilc_initOnce();
	vilc_vkCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, scratchSize, pCountInfo);
}
void vkCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, VkDeviceAddress                                 countInfo) {
	vilc_initOnce();
	vilc_vkCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, scratchSize, countInfo);
}
void vkCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer                                 commandBuffer, VkPipeline                                      executionGraph, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize) {
	vilc_initOnce();
	vilc_vkCmdInitializeGraphScratchMemoryAMDX(commandBuffer, executionGraph, scratch, scratchSize);
}
VkResult vkCreateExecutionGraphPipelinesAMDX(VkDevice                                        device, VkPipelineCache pipelineCache, uint32_t                                        createInfoCount, const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos, const VkAllocationCallbacks*    pAllocator, VkPipeline*               pPipelines) {
	vilc_initOnce();
	return vilc_vkCreateExecutionGraphPipelinesAMDX(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
VkResult vkGetExecutionGraphPipelineNodeIndexAMDX(VkDevice                                        device, VkPipeline                                      executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX*  pNodeInfo, uint32_t*                                       pNodeIndex) {
	vilc_initOnce();
	return vilc_vkGetExecutionGraphPipelineNodeIndexAMDX(device, executionGraph, pNodeInfo, pNodeIndex);
}
VkResult vkGetExecutionGraphPipelineScratchSizeAMDX(VkDevice                                        device, VkPipeline                                      executionGraph, VkExecutionGraphPipelineScratchSizeAMDX*        pSizeInfo) {
	vilc_initOnce();
	return vilc_vkGetExecutionGraphPipelineScratchSizeAMDX(device, executionGraph, pSizeInfo);
}
#endif /* defined(VK_AMDX_shader_enqueue) */
#if defined(VK_AMD_anti_lag)
void vkAntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) {
	vilc_initOnce();
	vilc_vkAntiLagUpdateAMD(device, pData);
}
#endif /* defined(VK_AMD_anti_lag) */
#if defined(VK_AMD_buffer_marker)
void vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
	vilc_initOnce();
	vilc_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
#endif /* defined(VK_AMD_buffer_marker) */
#if defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
void vkCmdWriteBufferMarker2AMD(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkBuffer                                            dstBuffer, VkDeviceSize                                        dstOffset, uint32_t                                            marker) {
	vilc_initOnce();
	vilc_vkCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}
#endif /* defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_AMD_display_native_hdr)
void vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) {
	vilc_initOnce();
	vilc_vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
}
#endif /* defined(VK_AMD_display_native_hdr) */
#if defined(VK_AMD_draw_indirect_count)
void vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void vkCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
#endif /* defined(VK_AMD_draw_indirect_count) */
#if defined(VK_AMD_shader_info)
VkResult vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) {
	vilc_initOnce();
	return vilc_vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
}
#endif /* defined(VK_AMD_shader_info) */
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
VkResult vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) {
	vilc_initOnce();
	return vilc_vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
}
VkResult vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) {
	vilc_initOnce();
	return vilc_vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
}
#endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
#if defined(VK_ARM_data_graph)
VkResult vkBindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindDataGraphPipelineSessionMemoryARM(device, bindInfoCount, pBindInfos);
}
void vkCmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) {
	vilc_initOnce();
	vilc_vkCmdDispatchDataGraphARM(commandBuffer, session, pInfo);
}
VkResult vkCreateDataGraphPipelineSessionARM(VkDevice                                     device, const VkDataGraphPipelineSessionCreateInfoARM*   pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM*                   pSession) {
	vilc_initOnce();
	return vilc_vkCreateDataGraphPipelineSessionARM(device, pCreateInfo, pAllocator, pSession);
}
VkResult vkCreateDataGraphPipelinesARM(VkDevice               device, VkDeferredOperationKHR deferredOperation, VkPipelineCache        pipelineCache, uint32_t               createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline*     pPipelines) {
	vilc_initOnce();
	return vilc_vkCreateDataGraphPipelinesARM(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
void vkDestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDataGraphPipelineSessionARM(device, session, pAllocator);
}
VkResult vkGetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) {
	vilc_initOnce();
	return vilc_vkGetDataGraphPipelineAvailablePropertiesARM(device, pPipelineInfo, pPropertiesCount, pProperties);
}
VkResult vkGetDataGraphPipelinePropertiesARM(VkDevice                          device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t                          propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) {
	vilc_initOnce();
	return vilc_vkGetDataGraphPipelinePropertiesARM(device, pPipelineInfo, propertiesCount, pProperties);
}
VkResult vkGetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) {
	vilc_initOnce();
	return vilc_vkGetDataGraphPipelineSessionBindPointRequirementsARM(device, pInfo, pBindPointRequirementCount, pBindPointRequirements);
}
void vkGetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDataGraphPipelineSessionMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
void vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice                                 physicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* pQueueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM*               pQueueFamilyDataGraphProcessingEngineProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(physicalDevice, pQueueFamilyDataGraphProcessingEngineInfo, pQueueFamilyDataGraphProcessingEngineProperties);
}
VkResult vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice                     physicalDevice, uint32_t                             queueFamilyIndex, uint32_t*                            pQueueFamilyDataGraphPropertyCount, VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphPropertyCount, pQueueFamilyDataGraphProperties);
}
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_performance_counters_by_region)
VkResult vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterARM* pCounters, VkPerformanceCounterDescriptionARM* pCounterDescriptions) {
	vilc_initOnce();
	return vilc_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
}
#endif /* defined(VK_ARM_performance_counters_by_region) */
#if defined(VK_ARM_tensors)
VkResult vkBindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindTensorMemoryARM(device, bindInfoCount, pBindInfos);
}
void vkCmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyTensorARM(commandBuffer, pCopyTensorInfo);
}
VkResult vkCreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) {
	vilc_initOnce();
	return vilc_vkCreateTensorARM(device, pCreateInfo, pAllocator, pTensor);
}
VkResult vkCreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) {
	vilc_initOnce();
	return vilc_vkCreateTensorViewARM(device, pCreateInfo, pAllocator, pView);
}
void vkDestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyTensorARM(device, tensor, pAllocator);
}
void vkDestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyTensorViewARM(device, tensorView, pAllocator);
}
void vkGetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceTensorMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
void vkGetPhysicalDeviceExternalTensorPropertiesARM(VkPhysicalDevice                             physicalDevice, const VkPhysicalDeviceExternalTensorInfoARM* pExternalTensorInfo, VkExternalTensorPropertiesARM*               pExternalTensorProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalTensorPropertiesARM(physicalDevice, pExternalTensorInfo, pExternalTensorProperties);
}
void vkGetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetTensorMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer)
VkResult vkGetTensorOpaqueCaptureDescriptorDataARM(VkDevice                                    device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void*                                       pData) {
	vilc_initOnce();
	return vilc_vkGetTensorOpaqueCaptureDescriptorDataARM(device, pInfo, pData);
}
VkResult vkGetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice                                        device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void*                                           pData) {
	vilc_initOnce();
	return vilc_vkGetTensorViewOpaqueCaptureDescriptorDataARM(device, pInfo, pData);
}
#endif /* defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_acquire_drm_display)
VkResult vkAcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) {
	vilc_initOnce();
	return vilc_vkAcquireDrmDisplayEXT(physicalDevice, drmFd, display);
}
VkResult vkGetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) {
	vilc_initOnce();
	return vilc_vkGetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
}
#endif /* defined(VK_EXT_acquire_drm_display) */
#if defined(VK_EXT_acquire_xlib_display)
VkResult vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) {
	vilc_initOnce();
	return vilc_vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
}
VkResult vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) {
	vilc_initOnce();
	return vilc_vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
}
#endif /* defined(VK_EXT_acquire_xlib_display) */
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
void vkCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
	vilc_initOnce();
	vilc_vkCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}
#endif /* defined(VK_EXT_attachment_feedback_loop_dynamic_state) */
#if defined(VK_EXT_buffer_device_address)
VkDeviceAddress vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetBufferDeviceAddressEXT(device, pInfo);
}
#endif /* defined(VK_EXT_buffer_device_address) */
#if defined(VK_EXT_calibrated_timestamps)
VkResult vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
	vilc_initOnce();
	return vilc_vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
}
VkResult vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
}
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_color_write_enable)
void vkCmdSetColorWriteEnableEXT(VkCommandBuffer       commandBuffer, uint32_t                                attachmentCount, const VkBool32*   pColorWriteEnables) {
	vilc_initOnce();
	vilc_vkCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}
#endif /* defined(VK_EXT_color_write_enable) */
#if defined(VK_EXT_conditional_rendering)
void vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
	vilc_initOnce();
	vilc_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
void vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdEndConditionalRenderingEXT(commandBuffer);
}
#endif /* defined(VK_EXT_conditional_rendering) */
#if defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3))
void vkCmdBeginCustomResolveEXT(VkCommandBuffer commandBuffer, const VkBeginCustomResolveInfoEXT* pBeginCustomResolveInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginCustomResolveEXT(commandBuffer, pBeginCustomResolveInfo);
}
#endif /* defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3)) */
#if defined(VK_EXT_debug_marker)
void vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
	vilc_initOnce();
	vilc_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}
void vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdDebugMarkerEndEXT(commandBuffer);
}
void vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
	vilc_initOnce();
	vilc_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}
VkResult vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
	vilc_initOnce();
	return vilc_vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
}
VkResult vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) {
	vilc_initOnce();
	return vilc_vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
}
#endif /* defined(VK_EXT_debug_marker) */
#if defined(VK_EXT_debug_report)
VkResult vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) {
	vilc_initOnce();
	return vilc_vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
}
void vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) {
	vilc_initOnce();
	vilc_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}
void vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
}
#endif /* defined(VK_EXT_debug_report) */
#if defined(VK_EXT_debug_utils)
void vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
}
void vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
	vilc_initOnce();
	vilc_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
VkResult vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) {
	vilc_initOnce();
	return vilc_vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
}
void vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
}
void vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
	vilc_initOnce();
	vilc_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
}
void vkQueueEndDebugUtilsLabelEXT(VkQueue queue) {
	vilc_initOnce();
	vilc_vkQueueEndDebugUtilsLabelEXT(queue);
}
void vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
	vilc_initOnce();
	vilc_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
}
VkResult vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
	vilc_initOnce();
	return vilc_vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
}
VkResult vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
	vilc_initOnce();
	return vilc_vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
}
void vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {
	vilc_initOnce();
	vilc_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
}
#endif /* defined(VK_EXT_debug_utils) */
#if defined(VK_EXT_depth_bias_control)
void vkCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT*         pDepthBiasInfo) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}
#endif /* defined(VK_EXT_depth_bias_control) */
#if defined(VK_EXT_descriptor_buffer)
void vkCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) {
	vilc_initOnce();
	vilc_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}
void vkCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
	vilc_initOnce();
	vilc_vkCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}
void vkCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
	vilc_initOnce();
	vilc_vkCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}
VkResult vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
	vilc_initOnce();
	return vilc_vkGetBufferOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
}
void vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) {
	vilc_initOnce();
	vilc_vkGetDescriptorEXT(device, pDescriptorInfo, dataSize, pDescriptor);
}
void vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) {
	vilc_initOnce();
	vilc_vkGetDescriptorSetLayoutBindingOffsetEXT(device, layout, binding, pOffset);
}
void vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) {
	vilc_initOnce();
	vilc_vkGetDescriptorSetLayoutSizeEXT(device, layout, pLayoutSizeInBytes);
}
VkResult vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
	vilc_initOnce();
	return vilc_vkGetImageOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
}
VkResult vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
	vilc_initOnce();
	return vilc_vkGetImageViewOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
}
VkResult vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
	vilc_initOnce();
	return vilc_vkGetSamplerOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
}
#endif /* defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing))
VkResult vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
	vilc_initOnce();
	return vilc_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
}
#endif /* defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing)) */
#if defined(VK_EXT_device_fault)
VkResult vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) {
	vilc_initOnce();
	return vilc_vkGetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
}
#endif /* defined(VK_EXT_device_fault) */
#if defined(VK_EXT_device_generated_commands)
void vkCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
	vilc_initOnce();
	vilc_vkCmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
void vkCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) {
	vilc_initOnce();
	vilc_vkCmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
}
VkResult vkCreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) {
	vilc_initOnce();
	return vilc_vkCreateIndirectCommandsLayoutEXT(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
}
VkResult vkCreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) {
	vilc_initOnce();
	return vilc_vkCreateIndirectExecutionSetEXT(device, pCreateInfo, pAllocator, pIndirectExecutionSet);
}
void vkDestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyIndirectCommandsLayoutEXT(device, indirectCommandsLayout, pAllocator);
}
void vkDestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyIndirectExecutionSetEXT(device, indirectExecutionSet, pAllocator);
}
void vkGetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetGeneratedCommandsMemoryRequirementsEXT(device, pInfo, pMemoryRequirements);
}
void vkUpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) {
	vilc_initOnce();
	vilc_vkUpdateIndirectExecutionSetPipelineEXT(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites);
}
void vkUpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) {
	vilc_initOnce();
	vilc_vkUpdateIndirectExecutionSetShaderEXT(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites);
}
#endif /* defined(VK_EXT_device_generated_commands) */
#if defined(VK_EXT_direct_mode_display)
VkResult vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
	vilc_initOnce();
	return vilc_vkReleaseDisplayEXT(physicalDevice, display);
}
#endif /* defined(VK_EXT_direct_mode_display) */
#if defined(VK_EXT_directfb_surface)
VkResult vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
}
#endif /* defined(VK_EXT_directfb_surface) */
#if defined(VK_EXT_discard_rectangles)
void vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
	vilc_initOnce();
	vilc_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}
#endif /* defined(VK_EXT_discard_rectangles) */
#if defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2
void vkCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}
void vkCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) {
	vilc_initOnce();
	vilc_vkCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}
#endif /* defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2 */
#if defined(VK_EXT_display_control)
VkResult vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
	vilc_initOnce();
	return vilc_vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
}
VkResult vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
	vilc_initOnce();
	return vilc_vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
}
VkResult vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
	vilc_initOnce();
	return vilc_vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
}
VkResult vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
	vilc_initOnce();
	return vilc_vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
}
#endif /* defined(VK_EXT_display_control) */
#if defined(VK_EXT_display_surface_counter)
VkResult vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
}
#endif /* defined(VK_EXT_display_surface_counter) */
#if defined(VK_EXT_external_memory_host)
VkResult vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) {
	vilc_initOnce();
	return vilc_vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
}
#endif /* defined(VK_EXT_external_memory_host) */
#if defined(VK_EXT_external_memory_metal)
VkResult vkGetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) {
	vilc_initOnce();
	return vilc_vkGetMemoryMetalHandleEXT(device, pGetMetalHandleInfo, pHandle);
}
VkResult vkGetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) {
	vilc_initOnce();
	return vilc_vkGetMemoryMetalHandlePropertiesEXT(device, handleType, pHandle, pMemoryMetalHandleProperties);
}
#endif /* defined(VK_EXT_external_memory_metal) */
#if defined(VK_EXT_fragment_density_map_offset)
void vkCmdEndRendering2EXT(VkCommandBuffer                   commandBuffer, const VkRenderingEndInfoKHR*        pRenderingEndInfo) {
	vilc_initOnce();
	vilc_vkCmdEndRendering2EXT(commandBuffer, pRenderingEndInfo);
}
#endif /* defined(VK_EXT_fragment_density_map_offset) */
#if defined(VK_EXT_full_screen_exclusive)
VkResult vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
	vilc_initOnce();
	return vilc_vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
}
VkResult vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
}
VkResult vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
	vilc_initOnce();
	return vilc_vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
}
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1))
VkResult vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) {
	vilc_initOnce();
	return vilc_vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
}
#endif /* defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1)) */
#if defined(VK_EXT_hdr_metadata)
void vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) {
	vilc_initOnce();
	vilc_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
}
#endif /* defined(VK_EXT_hdr_metadata) */
#if defined(VK_EXT_headless_surface)
VkResult vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_EXT_headless_surface) */
#if defined(VK_EXT_host_image_copy)
VkResult vkCopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo*    pCopyImageToImageInfo) {
	vilc_initOnce();
	return vilc_vkCopyImageToImageEXT(device, pCopyImageToImageInfo);
}
VkResult vkCopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo*    pCopyImageToMemoryInfo) {
	vilc_initOnce();
	return vilc_vkCopyImageToMemoryEXT(device, pCopyImageToMemoryInfo);
}
VkResult vkCopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo*    pCopyMemoryToImageInfo) {
	vilc_initOnce();
	return vilc_vkCopyMemoryToImageEXT(device, pCopyMemoryToImageInfo);
}
VkResult vkTransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo*    pTransitions) {
	vilc_initOnce();
	return vilc_vkTransitionImageLayoutEXT(device, transitionCount, pTransitions);
}
#endif /* defined(VK_EXT_host_image_copy) */
#if defined(VK_EXT_host_query_reset)
void vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
	vilc_initOnce();
	vilc_vkResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
}
#endif /* defined(VK_EXT_host_query_reset) */
#if defined(VK_EXT_image_drm_format_modifier)
VkResult vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) {
	vilc_initOnce();
	return vilc_vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
}
#endif /* defined(VK_EXT_image_drm_format_modifier) */
#if defined(VK_EXT_line_rasterization)
void vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
	vilc_initOnce();
	vilc_vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}
#endif /* defined(VK_EXT_line_rasterization) */
#if defined(VK_EXT_memory_decompression)
void vkCmdDecompressMemoryEXT(VkCommandBuffer commandBuffer, const VkDecompressMemoryInfoEXT* pDecompressMemoryInfoEXT) {
	vilc_initOnce();
	vilc_vkCmdDecompressMemoryEXT(commandBuffer, pDecompressMemoryInfoEXT);
}
void vkCmdDecompressMemoryIndirectCountEXT(VkCommandBuffer commandBuffer, VkMemoryDecompressionMethodFlagsEXT decompressionMethod, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t maxDecompressionCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDecompressMemoryIndirectCountEXT(commandBuffer, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
}
#endif /* defined(VK_EXT_memory_decompression) */
#if defined(VK_EXT_mesh_shader)
void vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	vilc_initOnce();
	vilc_vkCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void vkCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}
#endif /* defined(VK_EXT_mesh_shader) */
#if defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
void vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
#endif /* defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_EXT_metal_objects)
void vkExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) {
	vilc_initOnce();
	vilc_vkExportMetalObjectsEXT(device, pMetalObjectsInfo);
}
#endif /* defined(VK_EXT_metal_objects) */
#if defined(VK_EXT_metal_surface)
VkResult vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_EXT_metal_surface) */
#if defined(VK_EXT_multi_draw)
void vkCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}
void vkCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
	vilc_initOnce();
	vilc_vkCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}
#endif /* defined(VK_EXT_multi_draw) */
#if defined(VK_EXT_opacity_micromap)
VkResult vkBuildMicromapsEXT(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) {
	vilc_initOnce();
	return vilc_vkBuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
}
void vkCmdBuildMicromapsEXT(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) {
	vilc_initOnce();
	vilc_vkCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}
void vkCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}
void vkCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyMicromapEXT(commandBuffer, pInfo);
}
void vkCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}
void vkCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
	vilc_initOnce();
	vilc_vkCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}
VkResult vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
	vilc_initOnce();
	return vilc_vkCopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
}
VkResult vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) {
	vilc_initOnce();
	return vilc_vkCopyMicromapEXT(device, deferredOperation, pInfo);
}
VkResult vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
	vilc_initOnce();
	return vilc_vkCopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
}
VkResult vkCreateMicromapEXT(VkDevice                                           device, const VkMicromapCreateInfoEXT*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkMicromapEXT*                        pMicromap) {
	vilc_initOnce();
	return vilc_vkCreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
}
void vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyMicromapEXT(device, micromap, pAllocator);
}
void vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
	vilc_initOnce();
	vilc_vkGetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
}
void vkGetMicromapBuildSizesEXT(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkMicromapBuildInfoEXT*  pBuildInfo, VkMicromapBuildSizesInfoEXT*           pSizeInfo) {
	vilc_initOnce();
	vilc_vkGetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
}
VkResult vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride) {
	vilc_initOnce();
	return vilc_vkWriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
}
#endif /* defined(VK_EXT_opacity_micromap) */
#if defined(VK_EXT_pageable_device_local_memory)
void vkSetDeviceMemoryPriorityEXT(VkDevice       device, VkDeviceMemory memory, float          priority) {
	vilc_initOnce();
	vilc_vkSetDeviceMemoryPriorityEXT(device, memory, priority);
}
#endif /* defined(VK_EXT_pageable_device_local_memory) */
#if defined(VK_EXT_pipeline_properties)
VkResult vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) {
	vilc_initOnce();
	return vilc_vkGetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
}
#endif /* defined(VK_EXT_pipeline_properties) */
#if defined(VK_EXT_present_timing)
VkResult vkGetPastPresentationTimingEXT(VkDevice device, const VkPastPresentationTimingInfoEXT* pPastPresentationTimingInfo, VkPastPresentationTimingPropertiesEXT* pPastPresentationTimingProperties) {
	vilc_initOnce();
	return vilc_vkGetPastPresentationTimingEXT(device, pPastPresentationTimingInfo, pPastPresentationTimingProperties);
}
VkResult vkGetSwapchainTimeDomainPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimeDomainPropertiesEXT* pSwapchainTimeDomainProperties, uint64_t* pTimeDomainsCounter) {
	vilc_initOnce();
	return vilc_vkGetSwapchainTimeDomainPropertiesEXT(device, swapchain, pSwapchainTimeDomainProperties, pTimeDomainsCounter);
}
VkResult vkGetSwapchainTimingPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimingPropertiesEXT* pSwapchainTimingProperties, uint64_t* pSwapchainTimingPropertiesCounter) {
	vilc_initOnce();
	return vilc_vkGetSwapchainTimingPropertiesEXT(device, swapchain, pSwapchainTimingProperties, pSwapchainTimingPropertiesCounter);
}
VkResult vkSetSwapchainPresentTimingQueueSizeEXT(VkDevice device, VkSwapchainKHR swapchain, uint32_t size) {
	vilc_initOnce();
	return vilc_vkSetSwapchainPresentTimingQueueSizeEXT(device, swapchain, size);
}
#endif /* defined(VK_EXT_present_timing) */
#if defined(VK_EXT_private_data)
VkResult vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
	vilc_initOnce();
	return vilc_vkCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
}
void vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
}
void vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
	vilc_initOnce();
	vilc_vkGetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
}
VkResult vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
	vilc_initOnce();
	return vilc_vkSetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
}
#endif /* defined(VK_EXT_private_data) */
#if defined(VK_EXT_sample_locations)
void vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
	vilc_initOnce();
	vilc_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
void vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
}
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_shader_module_identifier)
void vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) {
	vilc_initOnce();
	vilc_vkGetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
}
void vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) {
	vilc_initOnce();
	vilc_vkGetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
}
#endif /* defined(VK_EXT_shader_module_identifier) */
#if defined(VK_EXT_shader_object)
void vkCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
	vilc_initOnce();
	vilc_vkCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}
VkResult vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) {
	vilc_initOnce();
	return vilc_vkCreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders);
}
void vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyShaderEXT(device, shader, pAllocator);
}
VkResult vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetShaderBinaryDataEXT(device, shader, pDataSize, pData);
}
#endif /* defined(VK_EXT_shader_object) */
#if defined(VK_EXT_swapchain_maintenance1)
VkResult vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) {
	vilc_initOnce();
	return vilc_vkReleaseSwapchainImagesEXT(device, pReleaseInfo);
}
#endif /* defined(VK_EXT_swapchain_maintenance1) */
#if defined(VK_EXT_tooling_info)
VkResult vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
}
#endif /* defined(VK_EXT_tooling_info) */
#if defined(VK_EXT_transform_feedback)
void vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {
	vilc_initOnce();
	vilc_vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
void vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
	vilc_initOnce();
	vilc_vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
void vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
	vilc_initOnce();
	vilc_vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
void vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
void vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) {
	vilc_initOnce();
	vilc_vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
void vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
	vilc_initOnce();
	vilc_vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
#endif /* defined(VK_EXT_transform_feedback) */
#if defined(VK_EXT_validation_cache)
VkResult vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) {
	vilc_initOnce();
	return vilc_vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
}
void vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
}
VkResult vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
}
VkResult vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) {
	vilc_initOnce();
	return vilc_vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
}
#endif /* defined(VK_EXT_validation_cache) */
#if defined(VK_FUCHSIA_buffer_collection)
VkResult vkCreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) {
	vilc_initOnce();
	return vilc_vkCreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
}
void vkDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
}
VkResult vkGetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) {
	vilc_initOnce();
	return vilc_vkGetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
}
VkResult vkSetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) {
	vilc_initOnce();
	return vilc_vkSetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
}
VkResult vkSetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) {
	vilc_initOnce();
	return vilc_vkSetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
}
#endif /* defined(VK_FUCHSIA_buffer_collection) */
#if defined(VK_FUCHSIA_external_memory)
VkResult vkGetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
	vilc_initOnce();
	return vilc_vkGetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
}
VkResult vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) {
	vilc_initOnce();
	return vilc_vkGetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
}
#endif /* defined(VK_FUCHSIA_external_memory) */
#if defined(VK_FUCHSIA_external_semaphore)
VkResult vkGetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
	vilc_initOnce();
	return vilc_vkGetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
}
VkResult vkImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) {
	vilc_initOnce();
	return vilc_vkImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
}
#endif /* defined(VK_FUCHSIA_external_semaphore) */
#if defined(VK_FUCHSIA_imagepipe_surface)
VkResult vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_FUCHSIA_imagepipe_surface) */
#if defined(VK_GGP_stream_descriptor_surface)
VkResult vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_GGP_stream_descriptor_surface) */
#if defined(VK_GOOGLE_display_timing)
VkResult vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) {
	vilc_initOnce();
	return vilc_vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
}
VkResult vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) {
	vilc_initOnce();
	return vilc_vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
}
#endif /* defined(VK_GOOGLE_display_timing) */
#if defined(VK_HUAWEI_cluster_culling_shader)
void vkCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	vilc_initOnce();
	vilc_vkCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void vkCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
	vilc_initOnce();
	vilc_vkCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}
#endif /* defined(VK_HUAWEI_cluster_culling_shader) */
#if defined(VK_HUAWEI_invocation_mask)
void vkCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
	vilc_initOnce();
	vilc_vkCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}
#endif /* defined(VK_HUAWEI_invocation_mask) */
#if defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2
VkResult vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) {
	vilc_initOnce();
	return vilc_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
}
#endif /* defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2 */
#if defined(VK_HUAWEI_subpass_shading)
void vkCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdSubpassShadingHUAWEI(commandBuffer);
}
#endif /* defined(VK_HUAWEI_subpass_shading) */
#if defined(VK_INTEL_performance_query)
VkResult vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) {
	vilc_initOnce();
	return vilc_vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
}
VkResult vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
	vilc_initOnce();
	return vilc_vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
	vilc_initOnce();
	return vilc_vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
}
VkResult vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
	vilc_initOnce();
	return vilc_vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) {
	vilc_initOnce();
	return vilc_vkGetPerformanceParameterINTEL(device, parameter, pValue);
}
VkResult vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) {
	vilc_initOnce();
	return vilc_vkInitializePerformanceApiINTEL(device, pInitializeInfo);
}
VkResult vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) {
	vilc_initOnce();
	return vilc_vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
}
VkResult vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) {
	vilc_initOnce();
	return vilc_vkReleasePerformanceConfigurationINTEL(device, configuration);
}
void vkUninitializePerformanceApiINTEL(VkDevice device) {
	vilc_initOnce();
	vilc_vkUninitializePerformanceApiINTEL(device);
}
#endif /* defined(VK_INTEL_performance_query) */
#if defined(VK_KHR_acceleration_structure)
VkResult vkBuildAccelerationStructuresKHR(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
	vilc_initOnce();
	return vilc_vkBuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
}
void vkCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts) {
	vilc_initOnce();
	vilc_vkCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}
void vkCmdBuildAccelerationStructuresKHR(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
	vilc_initOnce();
	vilc_vkCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}
void vkCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}
void vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}
void vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}
void vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
	vilc_initOnce();
	vilc_vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
VkResult vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) {
	vilc_initOnce();
	return vilc_vkCopyAccelerationStructureKHR(device, deferredOperation, pInfo);
}
VkResult vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
	vilc_initOnce();
	return vilc_vkCopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
}
VkResult vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
	vilc_initOnce();
	return vilc_vkCopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
}
VkResult vkCreateAccelerationStructureKHR(VkDevice                                           device, const VkAccelerationStructureCreateInfoKHR*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkAccelerationStructureKHR*                        pAccelerationStructure) {
	vilc_initOnce();
	return vilc_vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
}
void vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
}
void vkGetAccelerationStructureBuildSizesKHR(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkAccelerationStructureBuildGeometryInfoKHR*  pBuildInfo, const uint32_t*  pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR*           pSizeInfo) {
	vilc_initOnce();
	vilc_vkGetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}
VkDeviceAddress vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) {
	vilc_initOnce();
	return vilc_vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
}
void vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
	vilc_initOnce();
	vilc_vkGetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
}
VkResult vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride) {
	vilc_initOnce();
	return vilc_vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
}
#endif /* defined(VK_KHR_acceleration_structure) */
#if defined(VK_KHR_android_surface)
VkResult vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_KHR_android_surface) */
#if defined(VK_KHR_bind_memory2)
VkResult vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
}
VkResult vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindImageMemory2KHR(device, bindInfoCount, pBindInfos);
}
#endif /* defined(VK_KHR_bind_memory2) */
#if defined(VK_KHR_buffer_device_address)
VkDeviceAddress vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetBufferDeviceAddressKHR(device, pInfo);
}
uint64_t vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetBufferOpaqueCaptureAddressKHR(device, pInfo);
}
uint64_t vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
	vilc_initOnce();
	return vilc_vkGetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
}
#endif /* defined(VK_KHR_buffer_device_address) */
#if defined(VK_KHR_calibrated_timestamps)
VkResult vkGetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
	vilc_initOnce();
	return vilc_vkGetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
}
VkResult vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains);
}
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_cooperative_matrix)
VkResult vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesKHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}
#endif /* defined(VK_KHR_cooperative_matrix) */
#if defined(VK_KHR_copy_commands2)
void vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
	vilc_initOnce();
	vilc_vkCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
void vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
void vkCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
void vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
void vkCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
void vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
	vilc_initOnce();
	vilc_vkCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}
#endif /* defined(VK_KHR_copy_commands2) */
#if defined(VK_KHR_copy_memory_indirect)
void vkCmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyMemoryIndirectKHR(commandBuffer, pCopyMemoryIndirectInfo);
}
void vkCmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) {
	vilc_initOnce();
	vilc_vkCmdCopyMemoryToImageIndirectKHR(commandBuffer, pCopyMemoryToImageIndirectInfo);
}
#endif /* defined(VK_KHR_copy_memory_indirect) */
#if defined(VK_KHR_create_renderpass2)
void vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) {
	vilc_initOnce();
	vilc_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}
void vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) {
	vilc_initOnce();
	vilc_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
VkResult vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
	vilc_initOnce();
	return vilc_vkCreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
}
#endif /* defined(VK_KHR_create_renderpass2) */
#if defined(VK_KHR_deferred_host_operations)
VkResult vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) {
	vilc_initOnce();
	return vilc_vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
}
VkResult vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) {
	vilc_initOnce();
	return vilc_vkDeferredOperationJoinKHR(device, operation);
}
void vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDeferredOperationKHR(device, operation, pAllocator);
}
uint32_t vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) {
	vilc_initOnce();
	return vilc_vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
}
VkResult vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) {
	vilc_initOnce();
	return vilc_vkGetDeferredOperationResultKHR(device, operation);
}
#endif /* defined(VK_KHR_deferred_host_operations) */
#if defined(VK_KHR_descriptor_update_template)
VkResult vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
	vilc_initOnce();
	return vilc_vkCreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}
void vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
}
void vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
	vilc_initOnce();
	vilc_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
}
#endif /* defined(VK_KHR_descriptor_update_template) */
#if defined(VK_KHR_device_group)
void vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	vilc_initOnce();
	vilc_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
	vilc_initOnce();
	vilc_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}
void vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
	vilc_initOnce();
	vilc_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
#endif /* defined(VK_KHR_device_group) */
#if defined(VK_KHR_device_group_creation)
VkResult vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
	vilc_initOnce();
	return vilc_vkEnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
}
#endif /* defined(VK_KHR_device_group_creation) */
#if defined(VK_KHR_display)
VkResult vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) {
	vilc_initOnce();
	return vilc_vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
}
VkResult vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VkResult vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
}
VkResult vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) {
	vilc_initOnce();
	return vilc_vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
}
VkResult vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) {
	vilc_initOnce();
	return vilc_vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
}
VkResult vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}
VkResult vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}
#endif /* defined(VK_KHR_display) */
#if defined(VK_KHR_display_swapchain)
VkResult vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) {
	vilc_initOnce();
	return vilc_vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
}
#endif /* defined(VK_KHR_display_swapchain) */
#if defined(VK_KHR_draw_indirect_count)
void vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
#endif /* defined(VK_KHR_draw_indirect_count) */
#if defined(VK_KHR_dynamic_rendering)
void vkCmdBeginRenderingKHR(VkCommandBuffer                   commandBuffer, const VkRenderingInfo*                              pRenderingInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}
void vkCmdEndRenderingKHR(VkCommandBuffer                   commandBuffer) {
	vilc_initOnce();
	vilc_vkCmdEndRenderingKHR(commandBuffer);
}
#endif /* defined(VK_KHR_dynamic_rendering) */
#if defined(VK_KHR_dynamic_rendering_local_read)
void vkCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) {
	vilc_initOnce();
	vilc_vkCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}
void vkCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
	vilc_initOnce();
	vilc_vkCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
}
#endif /* defined(VK_KHR_dynamic_rendering_local_read) */
#if defined(VK_KHR_external_fence_capabilities)
void vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
#endif /* defined(VK_KHR_external_fence_capabilities) */
#if defined(VK_KHR_external_fence_fd)
VkResult vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) {
	vilc_initOnce();
	return vilc_vkGetFenceFdKHR(device, pGetFdInfo, pFd);
}
VkResult vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
	vilc_initOnce();
	return vilc_vkImportFenceFdKHR(device, pImportFenceFdInfo);
}
#endif /* defined(VK_KHR_external_fence_fd) */
#if defined(VK_KHR_external_fence_win32)
VkResult vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
	vilc_initOnce();
	return vilc_vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}
VkResult vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) {
	vilc_initOnce();
	return vilc_vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
}
#endif /* defined(VK_KHR_external_fence_win32) */
#if defined(VK_KHR_external_memory_capabilities)
void vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
#endif /* defined(VK_KHR_external_memory_capabilities) */
#if defined(VK_KHR_external_memory_fd)
VkResult vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) {
	vilc_initOnce();
	return vilc_vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
}
VkResult vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
	vilc_initOnce();
	return vilc_vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
}
#endif /* defined(VK_KHR_external_memory_fd) */
#if defined(VK_KHR_external_memory_win32)
VkResult vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
	vilc_initOnce();
	return vilc_vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}
VkResult vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) {
	vilc_initOnce();
	return vilc_vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
}
#endif /* defined(VK_KHR_external_memory_win32) */
#if defined(VK_KHR_external_semaphore_capabilities)
void vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
#endif /* defined(VK_KHR_external_semaphore_capabilities) */
#if defined(VK_KHR_external_semaphore_fd)
VkResult vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
	vilc_initOnce();
	return vilc_vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
}
VkResult vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
	vilc_initOnce();
	return vilc_vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
}
#endif /* defined(VK_KHR_external_semaphore_fd) */
#if defined(VK_KHR_external_semaphore_win32)
VkResult vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
	vilc_initOnce();
	return vilc_vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}
VkResult vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) {
	vilc_initOnce();
	return vilc_vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
}
#endif /* defined(VK_KHR_external_semaphore_win32) */
#if defined(VK_KHR_fragment_shading_rate)
void vkCmdSetFragmentShadingRateKHR(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
	vilc_initOnce();
	vilc_vkCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}
VkResult vkGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
}
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_display_properties2)
VkResult vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
}
VkResult vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) {
	vilc_initOnce();
	return vilc_vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
}
VkResult vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
}
VkResult vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
}
#endif /* defined(VK_KHR_get_display_properties2) */
#if defined(VK_KHR_get_memory_requirements2)
void vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}
void vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}
void vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
#endif /* defined(VK_KHR_get_memory_requirements2) */
#if defined(VK_KHR_get_physical_device_properties2)
void vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
}
void vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
}
VkResult vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}
void vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
}
void vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
}
void vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
void vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}
#endif /* defined(VK_KHR_get_physical_device_properties2) */
#if defined(VK_KHR_get_surface_capabilities2)
VkResult vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
}
VkResult vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
}
#endif /* defined(VK_KHR_get_surface_capabilities2) */
#if defined(VK_KHR_line_rasterization)
void vkCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
	vilc_initOnce();
	vilc_vkCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}
#endif /* defined(VK_KHR_line_rasterization) */
#if defined(VK_KHR_maintenance1)
void vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
	vilc_initOnce();
	vilc_vkTrimCommandPoolKHR(device, commandPool, flags);
}
#endif /* defined(VK_KHR_maintenance1) */
#if defined(VK_KHR_maintenance10)
void vkCmdEndRendering2KHR(VkCommandBuffer                   commandBuffer, const VkRenderingEndInfoKHR*        pRenderingEndInfo) {
	vilc_initOnce();
	vilc_vkCmdEndRendering2KHR(commandBuffer, pRenderingEndInfo);
}
#endif /* defined(VK_KHR_maintenance10) */
#if defined(VK_KHR_maintenance3)
void vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
	vilc_initOnce();
	vilc_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
}
#endif /* defined(VK_KHR_maintenance3) */
#if defined(VK_KHR_maintenance4)
void vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceBufferMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
}
void vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceImageMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
}
void vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetDeviceImageSparseMemoryRequirementsKHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
#endif /* defined(VK_KHR_maintenance4) */
#if defined(VK_KHR_maintenance5)
void vkCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
	vilc_initOnce();
	vilc_vkCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}
void vkGetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) {
	vilc_initOnce();
	vilc_vkGetDeviceImageSubresourceLayoutKHR(device, pInfo, pLayout);
}
void vkGetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
	vilc_initOnce();
	vilc_vkGetImageSubresourceLayout2KHR(device, image, pSubresource, pLayout);
}
void vkGetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) {
	vilc_initOnce();
	vilc_vkGetRenderingAreaGranularityKHR(device, pRenderingAreaInfo, pGranularity);
}
#endif /* defined(VK_KHR_maintenance5) */
#if defined(VK_KHR_maintenance6)
void vkCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo*   pBindDescriptorSetsInfo) {
	vilc_initOnce();
	vilc_vkCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}
void vkCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo*        pPushConstantsInfo) {
	vilc_initOnce();
	vilc_vkCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}
#endif /* defined(VK_KHR_maintenance6) */
#if defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor)
void vkCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo*    pPushDescriptorSetInfo) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}
void vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
#endif /* defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer)
void vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
	vilc_initOnce();
	vilc_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}
void vkCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
	vilc_initOnce();
	vilc_vkCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}
#endif /* defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_KHR_map_memory2)
VkResult vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
	vilc_initOnce();
	return vilc_vkMapMemory2KHR(device, pMemoryMapInfo, ppData);
}
VkResult vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
	vilc_initOnce();
	return vilc_vkUnmapMemory2KHR(device, pMemoryUnmapInfo);
}
#endif /* defined(VK_KHR_map_memory2) */
#if defined(VK_KHR_performance_query)
VkResult vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) {
	vilc_initOnce();
	return vilc_vkAcquireProfilingLockKHR(device, pInfo);
}
VkResult vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) {
	vilc_initOnce();
	return vilc_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
}
void vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) {
	vilc_initOnce();
	vilc_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}
void vkReleaseProfilingLockKHR(VkDevice device) {
	vilc_initOnce();
	vilc_vkReleaseProfilingLockKHR(device);
}
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_pipeline_binary)
VkResult vkCreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) {
	vilc_initOnce();
	return vilc_vkCreatePipelineBinariesKHR(device, pCreateInfo, pAllocator, pBinaries);
}
void vkDestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyPipelineBinaryKHR(device, pipelineBinary, pAllocator);
}
VkResult vkGetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) {
	vilc_initOnce();
	return vilc_vkGetPipelineBinaryDataKHR(device, pInfo, pPipelineBinaryKey, pPipelineBinaryDataSize, pPipelineBinaryData);
}
VkResult vkGetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) {
	vilc_initOnce();
	return vilc_vkGetPipelineKeyKHR(device, pPipelineCreateInfo, pPipelineKey);
}
VkResult vkReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	return vilc_vkReleaseCapturedPipelineDataKHR(device, pInfo, pAllocator);
}
#endif /* defined(VK_KHR_pipeline_binary) */
#if defined(VK_KHR_pipeline_executable_properties)
VkResult vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) {
	vilc_initOnce();
	return vilc_vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
}
VkResult vkGetPipelineExecutablePropertiesKHR(VkDevice                        device, const VkPipelineInfoKHR*        pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
}
VkResult vkGetPipelineExecutableStatisticsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) {
	vilc_initOnce();
	return vilc_vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
}
#endif /* defined(VK_KHR_pipeline_executable_properties) */
#if defined(VK_KHR_present_wait)
VkResult vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) {
	vilc_initOnce();
	return vilc_vkWaitForPresentKHR(device, swapchain, presentId, timeout);
}
#endif /* defined(VK_KHR_present_wait) */
#if defined(VK_KHR_present_wait2)
VkResult vkWaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) {
	vilc_initOnce();
	return vilc_vkWaitForPresent2KHR(device, swapchain, pPresentWait2Info);
}
#endif /* defined(VK_KHR_present_wait2) */
#if defined(VK_KHR_push_descriptor)
void vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
#endif /* defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
void vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
	vilc_initOnce();
	vilc_vkCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}
#endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_ray_tracing_pipeline)
void vkCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
	vilc_initOnce();
	vilc_vkCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}
void vkCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
	vilc_initOnce();
	vilc_vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}
void vkCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) {
	vilc_initOnce();
	vilc_vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}
VkResult vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
	vilc_initOnce();
	return vilc_vkCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
VkResult vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
}
VkResult vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
}
VkDeviceSize vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) {
	vilc_initOnce();
	return vilc_vkGetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
}
#endif /* defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_sampler_ycbcr_conversion)
VkResult vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
	vilc_initOnce();
	return vilc_vkCreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
}
void vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
}
#endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
#if defined(VK_KHR_shared_presentable_image)
VkResult vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) {
	vilc_initOnce();
	return vilc_vkGetSwapchainStatusKHR(device, swapchain);
}
#endif /* defined(VK_KHR_shared_presentable_image) */
#if defined(VK_KHR_surface)
void vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroySurfaceKHR(instance, surface, pAllocator);
}
VkResult vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
}
VkResult vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
}
VkResult vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
}
VkResult vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
}
#endif /* defined(VK_KHR_surface) */
#if defined(VK_KHR_swapchain)
VkResult vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
	vilc_initOnce();
	return vilc_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
}
VkResult vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
	vilc_initOnce();
	return vilc_vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
}
void vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroySwapchainKHR(device, swapchain, pAllocator);
}
VkResult vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) {
	vilc_initOnce();
	return vilc_vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
}
VkResult vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
	vilc_initOnce();
	return vilc_vkQueuePresentKHR(queue, pPresentInfo);
}
#endif /* defined(VK_KHR_swapchain) */
#if defined(VK_KHR_swapchain_maintenance1)
VkResult vkReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) {
	vilc_initOnce();
	return vilc_vkReleaseSwapchainImagesKHR(device, pReleaseInfo);
}
#endif /* defined(VK_KHR_swapchain_maintenance1) */
#if defined(VK_KHR_synchronization2)
void vkCmdPipelineBarrier2KHR(VkCommandBuffer                   commandBuffer, const VkDependencyInfo*                             pDependencyInfo) {
	vilc_initOnce();
	vilc_vkCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}
void vkCmdResetEvent2KHR(VkCommandBuffer                   commandBuffer, VkEvent                                             event, VkPipelineStageFlags2               stageMask) {
	vilc_initOnce();
	vilc_vkCmdResetEvent2KHR(commandBuffer, event, stageMask);
}
void vkCmdSetEvent2KHR(VkCommandBuffer                   commandBuffer, VkEvent                                             event, const VkDependencyInfo*                             pDependencyInfo) {
	vilc_initOnce();
	vilc_vkCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}
void vkCmdWaitEvents2KHR(VkCommandBuffer                   commandBuffer, uint32_t                                            eventCount, const VkEvent*                     pEvents, const VkDependencyInfo*            pDependencyInfos) {
	vilc_initOnce();
	vilc_vkCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void vkCmdWriteTimestamp2KHR(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkQueryPool                                         queryPool, uint32_t                                            query) {
	vilc_initOnce();
	vilc_vkCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}
VkResult vkQueueSubmit2KHR(VkQueue                           queue, uint32_t                            submitCount, const VkSubmitInfo2*              pSubmits, VkFence           fence) {
	vilc_initOnce();
	return vilc_vkQueueSubmit2KHR(queue, submitCount, pSubmits, fence);
}
#endif /* defined(VK_KHR_synchronization2) */
#if defined(VK_KHR_timeline_semaphore)
VkResult vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
	vilc_initOnce();
	return vilc_vkGetSemaphoreCounterValueKHR(device, semaphore, pValue);
}
VkResult vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
	vilc_initOnce();
	return vilc_vkSignalSemaphoreKHR(device, pSignalInfo);
}
VkResult vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
	vilc_initOnce();
	return vilc_vkWaitSemaphoresKHR(device, pWaitInfo, timeout);
}
#endif /* defined(VK_KHR_timeline_semaphore) */
#if defined(VK_KHR_video_decode_queue)
void vkCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
	vilc_initOnce();
	vilc_vkCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}
#endif /* defined(VK_KHR_video_decode_queue) */
#if defined(VK_KHR_video_encode_queue)
void vkCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
	vilc_initOnce();
	vilc_vkCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
VkResult vkGetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetEncodedVideoSessionParametersKHR(device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
}
VkResult vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR* pQualityLevelProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
}
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
VkResult vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) {
	vilc_initOnce();
	return vilc_vkBindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
}
void vkCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}
void vkCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
	vilc_initOnce();
	vilc_vkCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}
void vkCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
	vilc_initOnce();
	vilc_vkCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}
VkResult vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) {
	vilc_initOnce();
	return vilc_vkCreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
}
VkResult vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) {
	vilc_initOnce();
	return vilc_vkCreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
}
void vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyVideoSessionKHR(device, videoSession, pAllocator);
}
void vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
}
VkResult vkGetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
}
VkResult vkGetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
}
VkResult vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) {
	vilc_initOnce();
	return vilc_vkGetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
}
VkResult vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) {
	vilc_initOnce();
	return vilc_vkUpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
}
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_KHR_wayland_surface)
VkResult vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
}
#endif /* defined(VK_KHR_wayland_surface) */
#if defined(VK_KHR_win32_surface)
VkResult vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
}
#endif /* defined(VK_KHR_win32_surface) */
#if defined(VK_KHR_xcb_surface)
VkResult vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
}
#endif /* defined(VK_KHR_xcb_surface) */
#if defined(VK_KHR_xlib_surface)
VkResult vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
}
#endif /* defined(VK_KHR_xlib_surface) */
#if defined(VK_MVK_ios_surface)
VkResult vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_MVK_ios_surface) */
#if defined(VK_MVK_macos_surface)
VkResult vkCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_MVK_macos_surface) */
#if defined(VK_NN_vi_surface)
VkResult vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_NN_vi_surface) */
#if defined(VK_NVX_binary_import)
void vkCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
	vilc_initOnce();
	vilc_vkCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}
VkResult vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) {
	vilc_initOnce();
	return vilc_vkCreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
}
VkResult vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) {
	vilc_initOnce();
	return vilc_vkCreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
}
void vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyCuFunctionNVX(device, function, pAllocator);
}
void vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyCuModuleNVX(device, module, pAllocator);
}
#endif /* defined(VK_NVX_binary_import) */
#if defined(VK_NVX_image_view_handle)
uint32_t vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) {
	vilc_initOnce();
	return vilc_vkGetImageViewHandleNVX(device, pInfo);
}
#endif /* defined(VK_NVX_image_view_handle) */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3
uint64_t vkGetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) {
	vilc_initOnce();
	return vilc_vkGetImageViewHandle64NVX(device, pInfo);
}
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3 */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2
VkResult vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) {
	vilc_initOnce();
	return vilc_vkGetImageViewAddressNVX(device, imageView, pProperties);
}
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2 */
#if defined(VK_NV_acquire_winrt_display)
VkResult vkAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
	vilc_initOnce();
	return vilc_vkAcquireWinrtDisplayNV(physicalDevice, display);
}
VkResult vkGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) {
	vilc_initOnce();
	return vilc_vkGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
}
#endif /* defined(VK_NV_acquire_winrt_display) */
#if defined(VK_NV_clip_space_w_scaling)
void vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {
	vilc_initOnce();
	vilc_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}
#endif /* defined(VK_NV_clip_space_w_scaling) */
#if defined(VK_NV_cluster_acceleration_structure)
void vkCmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer                     commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV*  pCommandInfos) {
	vilc_initOnce();
	vilc_vkCmdBuildClusterAccelerationStructureIndirectNV(commandBuffer, pCommandInfos);
}
void vkGetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
	vilc_initOnce();
	vilc_vkGetClusterAccelerationStructureBuildSizesNV(device, pInfo, pSizeInfo);
}
#endif /* defined(VK_NV_cluster_acceleration_structure) */
#if defined(VK_NV_compute_occupancy_priority)
void vkCmdSetComputeOccupancyPriorityNV(VkCommandBuffer commandBuffer, const VkComputeOccupancyPriorityParametersNV* pParameters) {
	vilc_initOnce();
	vilc_vkCmdSetComputeOccupancyPriorityNV(commandBuffer, pParameters);
}
#endif /* defined(VK_NV_compute_occupancy_priority) */
#if defined(VK_NV_cooperative_matrix)
VkResult vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
}
#endif /* defined(VK_NV_cooperative_matrix) */
#if defined(VK_NV_cooperative_matrix2)
VkResult vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixFlexibleDimensionsPropertiesNV* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(physicalDevice, pPropertyCount, pProperties);
}
#endif /* defined(VK_NV_cooperative_matrix2) */
#if defined(VK_NV_cooperative_vector)
void vkCmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) {
	vilc_initOnce();
	vilc_vkCmdConvertCooperativeVectorMatrixNV(commandBuffer, infoCount, pInfos);
}
VkResult vkConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) {
	vilc_initOnce();
	return vilc_vkConvertCooperativeVectorMatrixNV(device, pInfo);
}
VkResult vkGetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeVectorPropertiesNV* pProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(physicalDevice, pPropertyCount, pProperties);
}
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_copy_memory_indirect)
void vkCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}
void vkCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) {
	vilc_initOnce();
	vilc_vkCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}
#endif /* defined(VK_NV_copy_memory_indirect) */
#if defined(VK_NV_coverage_reduction_mode)
VkResult vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
}
#endif /* defined(VK_NV_coverage_reduction_mode) */
#if defined(VK_NV_cuda_kernel_launch)
void vkCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
	vilc_initOnce();
	vilc_vkCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}
VkResult vkCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction) {
	vilc_initOnce();
	return vilc_vkCreateCudaFunctionNV(device, pCreateInfo, pAllocator, pFunction);
}
VkResult vkCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule) {
	vilc_initOnce();
	return vilc_vkCreateCudaModuleNV(device, pCreateInfo, pAllocator, pModule);
}
void vkDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyCudaFunctionNV(device, function, pAllocator);
}
void vkDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyCudaModuleNV(device, module, pAllocator);
}
VkResult vkGetCudaModuleCacheNV(VkDevice device, VkCudaModuleNV module, size_t* pCacheSize, void* pCacheData) {
	vilc_initOnce();
	return vilc_vkGetCudaModuleCacheNV(device, module, pCacheSize, pCacheData);
}
#endif /* defined(VK_NV_cuda_kernel_launch) */
#if defined(VK_NV_device_diagnostic_checkpoints)
void vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
	vilc_initOnce();
	vilc_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
void vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) {
	vilc_initOnce();
	vilc_vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
}
#endif /* defined(VK_NV_device_diagnostic_checkpoints) */
#if defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
void vkGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) {
	vilc_initOnce();
	vilc_vkGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
}
#endif /* defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_NV_device_generated_commands)
void vkCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) {
	vilc_initOnce();
	vilc_vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
void vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
	vilc_initOnce();
	vilc_vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
void vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
	vilc_initOnce();
	vilc_vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
VkResult vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) {
	vilc_initOnce();
	return vilc_vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
}
void vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
}
void vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
#endif /* defined(VK_NV_device_generated_commands) */
#if defined(VK_NV_device_generated_commands_compute)
void vkCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint           pipelineBindPoint, VkPipeline                    pipeline) {
	vilc_initOnce();
	vilc_vkCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}
VkDeviceAddress vkGetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) {
	vilc_initOnce();
	return vilc_vkGetPipelineIndirectDeviceAddressNV(device, pInfo);
}
void vkGetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetPipelineIndirectMemoryRequirementsNV(device, pCreateInfo, pMemoryRequirements);
}
#endif /* defined(VK_NV_device_generated_commands_compute) */
#if defined(VK_NV_external_compute_queue)
VkResult vkCreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) {
	vilc_initOnce();
	return vilc_vkCreateExternalComputeQueueNV(device, pCreateInfo, pAllocator, pExternalQueue);
}
void vkDestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyExternalComputeQueueNV(device, externalQueue, pAllocator);
}
void vkGetExternalComputeQueueDataNV(VkExternalComputeQueueNV externalQueue, VkExternalComputeQueueDataParamsNV* params, void* pData) {
	vilc_initOnce();
	vilc_vkGetExternalComputeQueueDataNV(externalQueue, params, pData);
}
#endif /* defined(VK_NV_external_compute_queue) */
#if defined(VK_NV_external_memory_capabilities)
VkResult vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
}
#endif /* defined(VK_NV_external_memory_capabilities) */
#if defined(VK_NV_external_memory_rdma)
VkResult vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) {
	vilc_initOnce();
	return vilc_vkGetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
}
#endif /* defined(VK_NV_external_memory_rdma) */
#if defined(VK_NV_external_memory_win32)
VkResult vkGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) {
	vilc_initOnce();
	return vilc_vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
}
#endif /* defined(VK_NV_external_memory_win32) */
#if defined(VK_NV_fragment_shading_rate_enums)
void vkCmdSetFragmentShadingRateEnumNV(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
	vilc_initOnce();
	vilc_vkCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}
#endif /* defined(VK_NV_fragment_shading_rate_enums) */
#if defined(VK_NV_low_latency2)
void vkGetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) {
	vilc_initOnce();
	vilc_vkGetLatencyTimingsNV(device, swapchain, pLatencyMarkerInfo);
}
VkResult vkLatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) {
	vilc_initOnce();
	return vilc_vkLatencySleepNV(device, swapchain, pSleepInfo);
}
void vkQueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) {
	vilc_initOnce();
	vilc_vkQueueNotifyOutOfBandNV(queue, pQueueTypeInfo);
}
void vkSetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) {
	vilc_initOnce();
	vilc_vkSetLatencyMarkerNV(device, swapchain, pLatencyMarkerInfo);
}
VkResult vkSetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) {
	vilc_initOnce();
	return vilc_vkSetLatencySleepModeNV(device, swapchain, pSleepModeInfo);
}
#endif /* defined(VK_NV_low_latency2) */
#if defined(VK_NV_memory_decompression)
void vkCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}
void vkCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
	vilc_initOnce();
	vilc_vkCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}
#endif /* defined(VK_NV_memory_decompression) */
#if defined(VK_NV_mesh_shader)
void vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
void vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
	vilc_initOnce();
	vilc_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}
#endif /* defined(VK_NV_mesh_shader) */
#if defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
void vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	vilc_initOnce();
	vilc_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
#endif /* defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_NV_optical_flow)
VkResult vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) {
	vilc_initOnce();
	return vilc_vkBindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
}
void vkCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
	vilc_initOnce();
	vilc_vkCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}
VkResult vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) {
	vilc_initOnce();
	return vilc_vkCreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
}
void vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyOpticalFlowSessionNV(device, session, pAllocator);
}
VkResult vkGetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
}
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_NV_partitioned_acceleration_structure)
void vkCmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer                     commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV*  pBuildInfo) {
	vilc_initOnce();
	vilc_vkCmdBuildPartitionedAccelerationStructuresNV(commandBuffer, pBuildInfo);
}
void vkGetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR*                  pSizeInfo) {
	vilc_initOnce();
	vilc_vkGetPartitionedAccelerationStructuresBuildSizesNV(device, pInfo, pSizeInfo);
}
#endif /* defined(VK_NV_partitioned_acceleration_structure) */
#if defined(VK_NV_ray_tracing)
VkResult vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) {
	vilc_initOnce();
	return vilc_vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
}
void vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) {
	vilc_initOnce();
	vilc_vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
void vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
	vilc_initOnce();
	vilc_vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
void vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
	vilc_initOnce();
	vilc_vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
void vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
	vilc_initOnce();
	vilc_vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
VkResult vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) {
	vilc_initOnce();
	return vilc_vkCompileDeferredNV(device, pipeline, shader);
}
VkResult vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) {
	vilc_initOnce();
	return vilc_vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
}
VkResult vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
	vilc_initOnce();
	return vilc_vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
void vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) {
	vilc_initOnce();
	vilc_vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
}
VkResult vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
}
void vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) {
	vilc_initOnce();
	vilc_vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
VkResult vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
	vilc_initOnce();
	return vilc_vkGetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
}
#endif /* defined(VK_NV_ray_tracing) */
#if defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2
void vkCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) {
	vilc_initOnce();
	vilc_vkCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}
#endif /* defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2 */
#if defined(VK_NV_scissor_exclusive)
void vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
	vilc_initOnce();
	vilc_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}
#endif /* defined(VK_NV_scissor_exclusive) */
#if defined(VK_NV_shading_rate_image)
void vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
	vilc_initOnce();
	vilc_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
void vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
	vilc_initOnce();
	vilc_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
void vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) {
	vilc_initOnce();
	vilc_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}
#endif /* defined(VK_NV_shading_rate_image) */
#if defined(VK_OHOS_external_memory)
VkResult vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer) {
	vilc_initOnce();
	return vilc_vkGetMemoryNativeBufferOHOS(device, pInfo, pBuffer);
}
VkResult vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties) {
	vilc_initOnce();
	return vilc_vkGetNativeBufferPropertiesOHOS(device, buffer, pProperties);
}
#endif /* defined(VK_OHOS_external_memory) */
#if defined(VK_OHOS_surface)
VkResult vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateSurfaceOHOS(instance, pCreateInfo, pAllocator, pSurface);
}
#endif /* defined(VK_OHOS_surface) */
#if defined(VK_QCOM_tile_memory_heap)
void vkCmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) {
	vilc_initOnce();
	vilc_vkCmdBindTileMemoryQCOM(commandBuffer, pTileMemoryBindInfo);
}
#endif /* defined(VK_QCOM_tile_memory_heap) */
#if defined(VK_QCOM_tile_properties)
VkResult vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) {
	vilc_initOnce();
	return vilc_vkGetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
}
VkResult vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) {
	vilc_initOnce();
	return vilc_vkGetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
}
#endif /* defined(VK_QCOM_tile_properties) */
#if defined(VK_QCOM_tile_shading)
void vkCmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) {
	vilc_initOnce();
	vilc_vkCmdBeginPerTileExecutionQCOM(commandBuffer, pPerTileBeginInfo);
}
void vkCmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) {
	vilc_initOnce();
	vilc_vkCmdDispatchTileQCOM(commandBuffer, pDispatchTileInfo);
}
void vkCmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) {
	vilc_initOnce();
	vilc_vkCmdEndPerTileExecutionQCOM(commandBuffer, pPerTileEndInfo);
}
#endif /* defined(VK_QCOM_tile_shading) */
#if defined(VK_QNX_external_memory_screen_buffer)
VkResult vkGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) {
	vilc_initOnce();
	return vilc_vkGetScreenBufferPropertiesQNX(device, buffer, pProperties);
}
#endif /* defined(VK_QNX_external_memory_screen_buffer) */
#if defined(VK_QNX_screen_surface)
VkResult vkCreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	vilc_initOnce();
	return vilc_vkCreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
}
VkBool32 vkGetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
}
#endif /* defined(VK_QNX_screen_surface) */
#if defined(VK_VALVE_descriptor_set_host_mapping)
void vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) {
	vilc_initOnce();
	vilc_vkGetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
}
void vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) {
	vilc_initOnce();
	vilc_vkGetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
}
#endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
#if (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control))
void vkCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) {
	vilc_initOnce();
	vilc_vkCmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
}
#endif /* (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control)) */
#if (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object))
void vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
	vilc_initOnce();
	vilc_vkCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
	vilc_initOnce();
	vilc_vkCmdSetCullModeEXT(commandBuffer, cullMode);
}
void vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
void vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
	vilc_initOnce();
	vilc_vkCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
void vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
void vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
void vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
	vilc_initOnce();
	vilc_vkCmdSetFrontFaceEXT(commandBuffer, frontFace);
}
void vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
	vilc_initOnce();
	vilc_vkCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
void vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
	vilc_initOnce();
	vilc_vkCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
void vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
	vilc_initOnce();
	vilc_vkCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
void vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
	vilc_initOnce();
	vilc_vkCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}
#endif /* (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object))
void vkCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}
void vkCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
	vilc_initOnce();
	vilc_vkCmdSetLogicOpEXT(commandBuffer, logicOp);
}
void vkCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
	vilc_initOnce();
	vilc_vkCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}
void vkCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
	vilc_initOnce();
	vilc_vkCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}
void vkCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
	vilc_initOnce();
	vilc_vkCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object))
void vkCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
	vilc_initOnce();
	vilc_vkCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}
void vkCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
	vilc_initOnce();
	vilc_vkCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}
void vkCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
	vilc_initOnce();
	vilc_vkCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}
void vkCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) {
	vilc_initOnce();
	vilc_vkCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}
void vkCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {
	vilc_initOnce();
	vilc_vkCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}
void vkCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}
void vkCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
	vilc_initOnce();
	vilc_vkCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}
void vkCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
	vilc_initOnce();
	vilc_vkCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}
void vkCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  rasterizationSamples) {
	vilc_initOnce();
	vilc_vkCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}
void vkCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  samples, const VkSampleMask*    pSampleMask) {
	vilc_initOnce();
	vilc_vkCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object))
void vkCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) {
	vilc_initOnce();
	vilc_vkCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback))
void vkCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
	vilc_initOnce();
	vilc_vkCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization))
void vkCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
	vilc_initOnce();
	vilc_vkCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}
void vkCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) {
	vilc_initOnce();
	vilc_vkCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable))
void vkCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
	vilc_initOnce();
	vilc_vkCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations))
void vkCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
	vilc_initOnce();
	vilc_vkCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced))
void vkCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
	vilc_initOnce();
	vilc_vkCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex))
void vkCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) {
	vilc_initOnce();
	vilc_vkCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization))
void vkCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) {
	vilc_initOnce();
	vilc_vkCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}
void vkCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
	vilc_initOnce();
	vilc_vkCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control))
void vkCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
	vilc_initOnce();
	vilc_vkCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling))
void vkCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
	vilc_initOnce();
	vilc_vkCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle))
void vkCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
	vilc_initOnce();
	vilc_vkCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color))
void vkCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
	vilc_initOnce();
	vilc_vkCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}
void vkCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
	vilc_initOnce();
	vilc_vkCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples))
void vkCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) {
	vilc_initOnce();
	vilc_vkCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}
void vkCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) {
	vilc_initOnce();
	vilc_vkCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}
void vkCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) {
	vilc_initOnce();
	vilc_vkCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image))
void vkCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
	vilc_initOnce();
	vilc_vkCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test))
void vkCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) {
	vilc_initOnce();
	vilc_vkCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode))
void vkCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) {
	vilc_initOnce();
	vilc_vkCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode)) */
#if (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control))
void vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
	vilc_initOnce();
	vilc_vkGetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
}
#endif /* (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control)) */
#if (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state))
void vkCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
	vilc_initOnce();
	vilc_vkCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}
#endif /* (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state)) */
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)))
void vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
	vilc_initOnce();
	vilc_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
#endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template))) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
VkResult vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
	vilc_initOnce();
	return vilc_vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
}
VkResult vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) {
	vilc_initOnce();
	return vilc_vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
}
VkResult vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) {
	vilc_initOnce();
	return vilc_vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
}
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
VkResult vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) {
	vilc_initOnce();
	return vilc_vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
}
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
/* VOLK_GENERATE_PROTOTYPES_C_VILC */

#else /* VOLK_IN_LOADERS_CLOTH */

/* VOLK_GENERATE_PROTOTYPES_C */
#if defined(VK_VERSION_1_0)
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
PFN_vkAllocateMemory vkAllocateMemory;
PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
PFN_vkBindBufferMemory vkBindBufferMemory;
PFN_vkBindImageMemory vkBindImageMemory;
PFN_vkCmdBeginQuery vkCmdBeginQuery;
PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
PFN_vkCmdBindPipeline vkCmdBindPipeline;
PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
PFN_vkCmdBlitImage vkCmdBlitImage;
PFN_vkCmdClearAttachments vkCmdClearAttachments;
PFN_vkCmdClearColorImage vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
PFN_vkCmdCopyImage vkCmdCopyImage;
PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
PFN_vkCmdDispatch vkCmdDispatch;
PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
PFN_vkCmdDraw vkCmdDraw;
PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
PFN_vkCmdEndQuery vkCmdEndQuery;
PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
PFN_vkCmdFillBuffer vkCmdFillBuffer;
PFN_vkCmdNextSubpass vkCmdNextSubpass;
PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
PFN_vkCmdPushConstants vkCmdPushConstants;
PFN_vkCmdResetEvent vkCmdResetEvent;
PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
PFN_vkCmdResolveImage vkCmdResolveImage;
PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
PFN_vkCmdSetEvent vkCmdSetEvent;
PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
PFN_vkCmdSetScissor vkCmdSetScissor;
PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
PFN_vkCmdSetViewport vkCmdSetViewport;
PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
PFN_vkCmdWaitEvents vkCmdWaitEvents;
PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
PFN_vkCreateBuffer vkCreateBuffer;
PFN_vkCreateBufferView vkCreateBufferView;
PFN_vkCreateCommandPool vkCreateCommandPool;
PFN_vkCreateComputePipelines vkCreateComputePipelines;
PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
PFN_vkCreateDevice vkCreateDevice;
PFN_vkCreateEvent vkCreateEvent;
PFN_vkCreateFence vkCreateFence;
PFN_vkCreateFramebuffer vkCreateFramebuffer;
PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
PFN_vkCreateImage vkCreateImage;
PFN_vkCreateImageView vkCreateImageView;
PFN_vkCreateInstance vkCreateInstance;
PFN_vkCreatePipelineCache vkCreatePipelineCache;
PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
PFN_vkCreateQueryPool vkCreateQueryPool;
PFN_vkCreateRenderPass vkCreateRenderPass;
PFN_vkCreateSampler vkCreateSampler;
PFN_vkCreateSemaphore vkCreateSemaphore;
PFN_vkCreateShaderModule vkCreateShaderModule;
PFN_vkDestroyBuffer vkDestroyBuffer;
PFN_vkDestroyBufferView vkDestroyBufferView;
PFN_vkDestroyCommandPool vkDestroyCommandPool;
PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
PFN_vkDestroyDevice vkDestroyDevice;
PFN_vkDestroyEvent vkDestroyEvent;
PFN_vkDestroyFence vkDestroyFence;
PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
PFN_vkDestroyImage vkDestroyImage;
PFN_vkDestroyImageView vkDestroyImageView;
PFN_vkDestroyInstance vkDestroyInstance;
PFN_vkDestroyPipeline vkDestroyPipeline;
PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
PFN_vkDestroyQueryPool vkDestroyQueryPool;
PFN_vkDestroyRenderPass vkDestroyRenderPass;
PFN_vkDestroySampler vkDestroySampler;
PFN_vkDestroySemaphore vkDestroySemaphore;
PFN_vkDestroyShaderModule vkDestroyShaderModule;
PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
PFN_vkEndCommandBuffer vkEndCommandBuffer;
PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
PFN_vkFreeMemory vkFreeMemory;
PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
PFN_vkGetDeviceQueue vkGetDeviceQueue;
PFN_vkGetEventStatus vkGetEventStatus;
PFN_vkGetFenceStatus vkGetFenceStatus;
PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
PFN_vkMapMemory vkMapMemory;
PFN_vkMergePipelineCaches vkMergePipelineCaches;
PFN_vkQueueBindSparse vkQueueBindSparse;
PFN_vkQueueSubmit vkQueueSubmit;
PFN_vkQueueWaitIdle vkQueueWaitIdle;
PFN_vkResetCommandBuffer vkResetCommandBuffer;
PFN_vkResetCommandPool vkResetCommandPool;
PFN_vkResetDescriptorPool vkResetDescriptorPool;
PFN_vkResetEvent vkResetEvent;
PFN_vkResetFences vkResetFences;
PFN_vkSetEvent vkSetEvent;
PFN_vkUnmapMemory vkUnmapMemory;
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
PFN_vkWaitForFences vkWaitForFences;
#endif /* defined(VK_VERSION_1_0) */
#if defined(VK_VERSION_1_1)
PFN_vkBindBufferMemory2 vkBindBufferMemory2;
PFN_vkBindImageMemory2 vkBindImageMemory2;
PFN_vkCmdDispatchBase vkCmdDispatchBase;
PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
PFN_vkTrimCommandPool vkTrimCommandPool;
PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
#endif /* defined(VK_VERSION_1_1) */
#if defined(VK_VERSION_1_2)
PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
PFN_vkCreateRenderPass2 vkCreateRenderPass2;
PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;
PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
PFN_vkResetQueryPool vkResetQueryPool;
PFN_vkSignalSemaphore vkSignalSemaphore;
PFN_vkWaitSemaphores vkWaitSemaphores;
#endif /* defined(VK_VERSION_1_2) */
#if defined(VK_VERSION_1_3)
PFN_vkCmdBeginRendering vkCmdBeginRendering;
PFN_vkCmdBindVertexBuffers2 vkCmdBindVertexBuffers2;
PFN_vkCmdBlitImage2 vkCmdBlitImage2;
PFN_vkCmdCopyBuffer2 vkCmdCopyBuffer2;
PFN_vkCmdCopyBufferToImage2 vkCmdCopyBufferToImage2;
PFN_vkCmdCopyImage2 vkCmdCopyImage2;
PFN_vkCmdCopyImageToBuffer2 vkCmdCopyImageToBuffer2;
PFN_vkCmdEndRendering vkCmdEndRendering;
PFN_vkCmdPipelineBarrier2 vkCmdPipelineBarrier2;
PFN_vkCmdResetEvent2 vkCmdResetEvent2;
PFN_vkCmdResolveImage2 vkCmdResolveImage2;
PFN_vkCmdSetCullMode vkCmdSetCullMode;
PFN_vkCmdSetDepthBiasEnable vkCmdSetDepthBiasEnable;
PFN_vkCmdSetDepthBoundsTestEnable vkCmdSetDepthBoundsTestEnable;
PFN_vkCmdSetDepthCompareOp vkCmdSetDepthCompareOp;
PFN_vkCmdSetDepthTestEnable vkCmdSetDepthTestEnable;
PFN_vkCmdSetDepthWriteEnable vkCmdSetDepthWriteEnable;
PFN_vkCmdSetEvent2 vkCmdSetEvent2;
PFN_vkCmdSetFrontFace vkCmdSetFrontFace;
PFN_vkCmdSetPrimitiveRestartEnable vkCmdSetPrimitiveRestartEnable;
PFN_vkCmdSetPrimitiveTopology vkCmdSetPrimitiveTopology;
PFN_vkCmdSetRasterizerDiscardEnable vkCmdSetRasterizerDiscardEnable;
PFN_vkCmdSetScissorWithCount vkCmdSetScissorWithCount;
PFN_vkCmdSetStencilOp vkCmdSetStencilOp;
PFN_vkCmdSetStencilTestEnable vkCmdSetStencilTestEnable;
PFN_vkCmdSetViewportWithCount vkCmdSetViewportWithCount;
PFN_vkCmdWaitEvents2 vkCmdWaitEvents2;
PFN_vkCmdWriteTimestamp2 vkCmdWriteTimestamp2;
PFN_vkCreatePrivateDataSlot vkCreatePrivateDataSlot;
PFN_vkDestroyPrivateDataSlot vkDestroyPrivateDataSlot;
PFN_vkGetDeviceBufferMemoryRequirements vkGetDeviceBufferMemoryRequirements;
PFN_vkGetDeviceImageMemoryRequirements vkGetDeviceImageMemoryRequirements;
PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
PFN_vkGetPhysicalDeviceToolProperties vkGetPhysicalDeviceToolProperties;
PFN_vkGetPrivateData vkGetPrivateData;
PFN_vkQueueSubmit2 vkQueueSubmit2;
PFN_vkSetPrivateData vkSetPrivateData;
#endif /* defined(VK_VERSION_1_3) */
#if defined(VK_VERSION_1_4)
PFN_vkCmdBindDescriptorSets2 vkCmdBindDescriptorSets2;
PFN_vkCmdBindIndexBuffer2 vkCmdBindIndexBuffer2;
PFN_vkCmdPushConstants2 vkCmdPushConstants2;
PFN_vkCmdPushDescriptorSet vkCmdPushDescriptorSet;
PFN_vkCmdPushDescriptorSet2 vkCmdPushDescriptorSet2;
PFN_vkCmdPushDescriptorSetWithTemplate vkCmdPushDescriptorSetWithTemplate;
PFN_vkCmdPushDescriptorSetWithTemplate2 vkCmdPushDescriptorSetWithTemplate2;
PFN_vkCmdSetLineStipple vkCmdSetLineStipple;
PFN_vkCmdSetRenderingAttachmentLocations vkCmdSetRenderingAttachmentLocations;
PFN_vkCmdSetRenderingInputAttachmentIndices vkCmdSetRenderingInputAttachmentIndices;
PFN_vkCopyImageToImage vkCopyImageToImage;
PFN_vkCopyImageToMemory vkCopyImageToMemory;
PFN_vkCopyMemoryToImage vkCopyMemoryToImage;
PFN_vkGetDeviceImageSubresourceLayout vkGetDeviceImageSubresourceLayout;
PFN_vkGetImageSubresourceLayout2 vkGetImageSubresourceLayout2;
PFN_vkGetRenderingAreaGranularity vkGetRenderingAreaGranularity;
PFN_vkMapMemory2 vkMapMemory2;
PFN_vkTransitionImageLayout vkTransitionImageLayout;
PFN_vkUnmapMemory2 vkUnmapMemory2;
#endif /* defined(VK_VERSION_1_4) */
#if defined(VK_AMDX_shader_enqueue)
PFN_vkCmdDispatchGraphAMDX vkCmdDispatchGraphAMDX;
PFN_vkCmdDispatchGraphIndirectAMDX vkCmdDispatchGraphIndirectAMDX;
PFN_vkCmdDispatchGraphIndirectCountAMDX vkCmdDispatchGraphIndirectCountAMDX;
PFN_vkCmdInitializeGraphScratchMemoryAMDX vkCmdInitializeGraphScratchMemoryAMDX;
PFN_vkCreateExecutionGraphPipelinesAMDX vkCreateExecutionGraphPipelinesAMDX;
PFN_vkGetExecutionGraphPipelineNodeIndexAMDX vkGetExecutionGraphPipelineNodeIndexAMDX;
PFN_vkGetExecutionGraphPipelineScratchSizeAMDX vkGetExecutionGraphPipelineScratchSizeAMDX;
#endif /* defined(VK_AMDX_shader_enqueue) */
#if defined(VK_AMD_anti_lag)
PFN_vkAntiLagUpdateAMD vkAntiLagUpdateAMD;
#endif /* defined(VK_AMD_anti_lag) */
#if defined(VK_AMD_buffer_marker)
PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;
#endif /* defined(VK_AMD_buffer_marker) */
#if defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
PFN_vkCmdWriteBufferMarker2AMD vkCmdWriteBufferMarker2AMD;
#endif /* defined(VK_AMD_buffer_marker) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_AMD_display_native_hdr)
PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD;
#endif /* defined(VK_AMD_display_native_hdr) */
#if defined(VK_AMD_draw_indirect_count)
PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;
PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
#endif /* defined(VK_AMD_draw_indirect_count) */
#if defined(VK_AMD_shader_info)
PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;
#endif /* defined(VK_AMD_shader_info) */
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID;
PFN_vkGetMemoryAndroidHardwareBufferANDROID vkGetMemoryAndroidHardwareBufferANDROID;
#endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
#if defined(VK_ARM_data_graph)
PFN_vkBindDataGraphPipelineSessionMemoryARM vkBindDataGraphPipelineSessionMemoryARM;
PFN_vkCmdDispatchDataGraphARM vkCmdDispatchDataGraphARM;
PFN_vkCreateDataGraphPipelineSessionARM vkCreateDataGraphPipelineSessionARM;
PFN_vkCreateDataGraphPipelinesARM vkCreateDataGraphPipelinesARM;
PFN_vkDestroyDataGraphPipelineSessionARM vkDestroyDataGraphPipelineSessionARM;
PFN_vkGetDataGraphPipelineAvailablePropertiesARM vkGetDataGraphPipelineAvailablePropertiesARM;
PFN_vkGetDataGraphPipelinePropertiesARM vkGetDataGraphPipelinePropertiesARM;
PFN_vkGetDataGraphPipelineSessionBindPointRequirementsARM vkGetDataGraphPipelineSessionBindPointRequirementsARM;
PFN_vkGetDataGraphPipelineSessionMemoryRequirementsARM vkGetDataGraphPipelineSessionMemoryRequirementsARM;
PFN_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM;
PFN_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM;
#endif /* defined(VK_ARM_data_graph) */
#if defined(VK_ARM_performance_counters_by_region)
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM;
#endif /* defined(VK_ARM_performance_counters_by_region) */
#if defined(VK_ARM_tensors)
PFN_vkBindTensorMemoryARM vkBindTensorMemoryARM;
PFN_vkCmdCopyTensorARM vkCmdCopyTensorARM;
PFN_vkCreateTensorARM vkCreateTensorARM;
PFN_vkCreateTensorViewARM vkCreateTensorViewARM;
PFN_vkDestroyTensorARM vkDestroyTensorARM;
PFN_vkDestroyTensorViewARM vkDestroyTensorViewARM;
PFN_vkGetDeviceTensorMemoryRequirementsARM vkGetDeviceTensorMemoryRequirementsARM;
PFN_vkGetPhysicalDeviceExternalTensorPropertiesARM vkGetPhysicalDeviceExternalTensorPropertiesARM;
PFN_vkGetTensorMemoryRequirementsARM vkGetTensorMemoryRequirementsARM;
#endif /* defined(VK_ARM_tensors) */
#if defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer)
PFN_vkGetTensorOpaqueCaptureDescriptorDataARM vkGetTensorOpaqueCaptureDescriptorDataARM;
PFN_vkGetTensorViewOpaqueCaptureDescriptorDataARM vkGetTensorViewOpaqueCaptureDescriptorDataARM;
#endif /* defined(VK_ARM_tensors) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_acquire_drm_display)
PFN_vkAcquireDrmDisplayEXT vkAcquireDrmDisplayEXT;
PFN_vkGetDrmDisplayEXT vkGetDrmDisplayEXT;
#endif /* defined(VK_EXT_acquire_drm_display) */
#if defined(VK_EXT_acquire_xlib_display)
PFN_vkAcquireXlibDisplayEXT vkAcquireXlibDisplayEXT;
PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT;
#endif /* defined(VK_EXT_acquire_xlib_display) */
#if defined(VK_EXT_attachment_feedback_loop_dynamic_state)
PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT vkCmdSetAttachmentFeedbackLoopEnableEXT;
#endif /* defined(VK_EXT_attachment_feedback_loop_dynamic_state) */
#if defined(VK_EXT_buffer_device_address)
PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT;
#endif /* defined(VK_EXT_buffer_device_address) */
#if defined(VK_EXT_calibrated_timestamps)
PFN_vkGetCalibratedTimestampsEXT vkGetCalibratedTimestampsEXT;
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#endif /* defined(VK_EXT_calibrated_timestamps) */
#if defined(VK_EXT_color_write_enable)
PFN_vkCmdSetColorWriteEnableEXT vkCmdSetColorWriteEnableEXT;
#endif /* defined(VK_EXT_color_write_enable) */
#if defined(VK_EXT_conditional_rendering)
PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT;
PFN_vkCmdEndConditionalRenderingEXT vkCmdEndConditionalRenderingEXT;
#endif /* defined(VK_EXT_conditional_rendering) */
#if defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3))
PFN_vkCmdBeginCustomResolveEXT vkCmdBeginCustomResolveEXT;
#endif /* defined(VK_EXT_custom_resolve) && (defined(VK_KHR_dynamic_rendering) || defined(VK_VERSION_1_3)) */
#if defined(VK_EXT_debug_marker)
PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;
PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
#endif /* defined(VK_EXT_debug_marker) */
#if defined(VK_EXT_debug_report)
PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
#endif /* defined(VK_EXT_debug_report) */
#if defined(VK_EXT_debug_utils)
PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;
PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
#endif /* defined(VK_EXT_debug_utils) */
#if defined(VK_EXT_depth_bias_control)
PFN_vkCmdSetDepthBias2EXT vkCmdSetDepthBias2EXT;
#endif /* defined(VK_EXT_depth_bias_control) */
#if defined(VK_EXT_descriptor_buffer)
PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT vkCmdBindDescriptorBufferEmbeddedSamplersEXT;
PFN_vkCmdBindDescriptorBuffersEXT vkCmdBindDescriptorBuffersEXT;
PFN_vkCmdSetDescriptorBufferOffsetsEXT vkCmdSetDescriptorBufferOffsetsEXT;
PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT vkGetBufferOpaqueCaptureDescriptorDataEXT;
PFN_vkGetDescriptorEXT vkGetDescriptorEXT;
PFN_vkGetDescriptorSetLayoutBindingOffsetEXT vkGetDescriptorSetLayoutBindingOffsetEXT;
PFN_vkGetDescriptorSetLayoutSizeEXT vkGetDescriptorSetLayoutSizeEXT;
PFN_vkGetImageOpaqueCaptureDescriptorDataEXT vkGetImageOpaqueCaptureDescriptorDataEXT;
PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT vkGetImageViewOpaqueCaptureDescriptorDataEXT;
PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT vkGetSamplerOpaqueCaptureDescriptorDataEXT;
#endif /* defined(VK_EXT_descriptor_buffer) */
#if defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing))
PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT;
#endif /* defined(VK_EXT_descriptor_buffer) && (defined(VK_KHR_acceleration_structure) || defined(VK_NV_ray_tracing)) */
#if defined(VK_EXT_device_fault)
PFN_vkGetDeviceFaultInfoEXT vkGetDeviceFaultInfoEXT;
#endif /* defined(VK_EXT_device_fault) */
#if defined(VK_EXT_device_generated_commands)
PFN_vkCmdExecuteGeneratedCommandsEXT vkCmdExecuteGeneratedCommandsEXT;
PFN_vkCmdPreprocessGeneratedCommandsEXT vkCmdPreprocessGeneratedCommandsEXT;
PFN_vkCreateIndirectCommandsLayoutEXT vkCreateIndirectCommandsLayoutEXT;
PFN_vkCreateIndirectExecutionSetEXT vkCreateIndirectExecutionSetEXT;
PFN_vkDestroyIndirectCommandsLayoutEXT vkDestroyIndirectCommandsLayoutEXT;
PFN_vkDestroyIndirectExecutionSetEXT vkDestroyIndirectExecutionSetEXT;
PFN_vkGetGeneratedCommandsMemoryRequirementsEXT vkGetGeneratedCommandsMemoryRequirementsEXT;
PFN_vkUpdateIndirectExecutionSetPipelineEXT vkUpdateIndirectExecutionSetPipelineEXT;
PFN_vkUpdateIndirectExecutionSetShaderEXT vkUpdateIndirectExecutionSetShaderEXT;
#endif /* defined(VK_EXT_device_generated_commands) */
#if defined(VK_EXT_direct_mode_display)
PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
#endif /* defined(VK_EXT_direct_mode_display) */
#if defined(VK_EXT_directfb_surface)
PFN_vkCreateDirectFBSurfaceEXT vkCreateDirectFBSurfaceEXT;
PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif /* defined(VK_EXT_directfb_surface) */
#if defined(VK_EXT_discard_rectangles)
PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
#endif /* defined(VK_EXT_discard_rectangles) */
#if defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2
PFN_vkCmdSetDiscardRectangleEnableEXT vkCmdSetDiscardRectangleEnableEXT;
PFN_vkCmdSetDiscardRectangleModeEXT vkCmdSetDiscardRectangleModeEXT;
#endif /* defined(VK_EXT_discard_rectangles) && VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION >= 2 */
#if defined(VK_EXT_display_control)
PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
#endif /* defined(VK_EXT_display_control) */
#if defined(VK_EXT_display_surface_counter)
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
#endif /* defined(VK_EXT_display_surface_counter) */
#if defined(VK_EXT_external_memory_host)
PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
#endif /* defined(VK_EXT_external_memory_host) */
#if defined(VK_EXT_external_memory_metal)
PFN_vkGetMemoryMetalHandleEXT vkGetMemoryMetalHandleEXT;
PFN_vkGetMemoryMetalHandlePropertiesEXT vkGetMemoryMetalHandlePropertiesEXT;
#endif /* defined(VK_EXT_external_memory_metal) */
#if defined(VK_EXT_fragment_density_map_offset)
PFN_vkCmdEndRendering2EXT vkCmdEndRendering2EXT;
#endif /* defined(VK_EXT_fragment_density_map_offset) */
#if defined(VK_EXT_full_screen_exclusive)
PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT;
PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT;
PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT;
#endif /* defined(VK_EXT_full_screen_exclusive) */
#if defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1))
PFN_vkGetDeviceGroupSurfacePresentModes2EXT vkGetDeviceGroupSurfacePresentModes2EXT;
#endif /* defined(VK_EXT_full_screen_exclusive) && (defined(VK_KHR_device_group) || defined(VK_VERSION_1_1)) */
#if defined(VK_EXT_hdr_metadata)
PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;
#endif /* defined(VK_EXT_hdr_metadata) */
#if defined(VK_EXT_headless_surface)
PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT;
#endif /* defined(VK_EXT_headless_surface) */
#if defined(VK_EXT_host_image_copy)
PFN_vkCopyImageToImageEXT vkCopyImageToImageEXT;
PFN_vkCopyImageToMemoryEXT vkCopyImageToMemoryEXT;
PFN_vkCopyMemoryToImageEXT vkCopyMemoryToImageEXT;
PFN_vkTransitionImageLayoutEXT vkTransitionImageLayoutEXT;
#endif /* defined(VK_EXT_host_image_copy) */
#if defined(VK_EXT_host_query_reset)
PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT;
#endif /* defined(VK_EXT_host_query_reset) */
#if defined(VK_EXT_image_drm_format_modifier)
PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT;
#endif /* defined(VK_EXT_image_drm_format_modifier) */
#if defined(VK_EXT_line_rasterization)
PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT;
#endif /* defined(VK_EXT_line_rasterization) */
#if defined(VK_EXT_memory_decompression)
PFN_vkCmdDecompressMemoryEXT vkCmdDecompressMemoryEXT;
PFN_vkCmdDecompressMemoryIndirectCountEXT vkCmdDecompressMemoryIndirectCountEXT;
#endif /* defined(VK_EXT_memory_decompression) */
#if defined(VK_EXT_mesh_shader)
PFN_vkCmdDrawMeshTasksEXT vkCmdDrawMeshTasksEXT;
PFN_vkCmdDrawMeshTasksIndirectEXT vkCmdDrawMeshTasksIndirectEXT;
#endif /* defined(VK_EXT_mesh_shader) */
#if defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
PFN_vkCmdDrawMeshTasksIndirectCountEXT vkCmdDrawMeshTasksIndirectCountEXT;
#endif /* defined(VK_EXT_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_EXT_metal_objects)
PFN_vkExportMetalObjectsEXT vkExportMetalObjectsEXT;
#endif /* defined(VK_EXT_metal_objects) */
#if defined(VK_EXT_metal_surface)
PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT;
#endif /* defined(VK_EXT_metal_surface) */
#if defined(VK_EXT_multi_draw)
PFN_vkCmdDrawMultiEXT vkCmdDrawMultiEXT;
PFN_vkCmdDrawMultiIndexedEXT vkCmdDrawMultiIndexedEXT;
#endif /* defined(VK_EXT_multi_draw) */
#if defined(VK_EXT_opacity_micromap)
PFN_vkBuildMicromapsEXT vkBuildMicromapsEXT;
PFN_vkCmdBuildMicromapsEXT vkCmdBuildMicromapsEXT;
PFN_vkCmdCopyMemoryToMicromapEXT vkCmdCopyMemoryToMicromapEXT;
PFN_vkCmdCopyMicromapEXT vkCmdCopyMicromapEXT;
PFN_vkCmdCopyMicromapToMemoryEXT vkCmdCopyMicromapToMemoryEXT;
PFN_vkCmdWriteMicromapsPropertiesEXT vkCmdWriteMicromapsPropertiesEXT;
PFN_vkCopyMemoryToMicromapEXT vkCopyMemoryToMicromapEXT;
PFN_vkCopyMicromapEXT vkCopyMicromapEXT;
PFN_vkCopyMicromapToMemoryEXT vkCopyMicromapToMemoryEXT;
PFN_vkCreateMicromapEXT vkCreateMicromapEXT;
PFN_vkDestroyMicromapEXT vkDestroyMicromapEXT;
PFN_vkGetDeviceMicromapCompatibilityEXT vkGetDeviceMicromapCompatibilityEXT;
PFN_vkGetMicromapBuildSizesEXT vkGetMicromapBuildSizesEXT;
PFN_vkWriteMicromapsPropertiesEXT vkWriteMicromapsPropertiesEXT;
#endif /* defined(VK_EXT_opacity_micromap) */
#if defined(VK_EXT_pageable_device_local_memory)
PFN_vkSetDeviceMemoryPriorityEXT vkSetDeviceMemoryPriorityEXT;
#endif /* defined(VK_EXT_pageable_device_local_memory) */
#if defined(VK_EXT_pipeline_properties)
PFN_vkGetPipelinePropertiesEXT vkGetPipelinePropertiesEXT;
#endif /* defined(VK_EXT_pipeline_properties) */
#if defined(VK_EXT_present_timing)
PFN_vkGetPastPresentationTimingEXT vkGetPastPresentationTimingEXT;
PFN_vkGetSwapchainTimeDomainPropertiesEXT vkGetSwapchainTimeDomainPropertiesEXT;
PFN_vkGetSwapchainTimingPropertiesEXT vkGetSwapchainTimingPropertiesEXT;
PFN_vkSetSwapchainPresentTimingQueueSizeEXT vkSetSwapchainPresentTimingQueueSizeEXT;
#endif /* defined(VK_EXT_present_timing) */
#if defined(VK_EXT_private_data)
PFN_vkCreatePrivateDataSlotEXT vkCreatePrivateDataSlotEXT;
PFN_vkDestroyPrivateDataSlotEXT vkDestroyPrivateDataSlotEXT;
PFN_vkGetPrivateDataEXT vkGetPrivateDataEXT;
PFN_vkSetPrivateDataEXT vkSetPrivateDataEXT;
#endif /* defined(VK_EXT_private_data) */
#if defined(VK_EXT_sample_locations)
PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;
#endif /* defined(VK_EXT_sample_locations) */
#if defined(VK_EXT_shader_module_identifier)
PFN_vkGetShaderModuleCreateInfoIdentifierEXT vkGetShaderModuleCreateInfoIdentifierEXT;
PFN_vkGetShaderModuleIdentifierEXT vkGetShaderModuleIdentifierEXT;
#endif /* defined(VK_EXT_shader_module_identifier) */
#if defined(VK_EXT_shader_object)
PFN_vkCmdBindShadersEXT vkCmdBindShadersEXT;
PFN_vkCreateShadersEXT vkCreateShadersEXT;
PFN_vkDestroyShaderEXT vkDestroyShaderEXT;
PFN_vkGetShaderBinaryDataEXT vkGetShaderBinaryDataEXT;
#endif /* defined(VK_EXT_shader_object) */
#if defined(VK_EXT_swapchain_maintenance1)
PFN_vkReleaseSwapchainImagesEXT vkReleaseSwapchainImagesEXT;
#endif /* defined(VK_EXT_swapchain_maintenance1) */
#if defined(VK_EXT_tooling_info)
PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT;
#endif /* defined(VK_EXT_tooling_info) */
#if defined(VK_EXT_transform_feedback)
PFN_vkCmdBeginQueryIndexedEXT vkCmdBeginQueryIndexedEXT;
PFN_vkCmdBeginTransformFeedbackEXT vkCmdBeginTransformFeedbackEXT;
PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT;
PFN_vkCmdDrawIndirectByteCountEXT vkCmdDrawIndirectByteCountEXT;
PFN_vkCmdEndQueryIndexedEXT vkCmdEndQueryIndexedEXT;
PFN_vkCmdEndTransformFeedbackEXT vkCmdEndTransformFeedbackEXT;
#endif /* defined(VK_EXT_transform_feedback) */
#if defined(VK_EXT_validation_cache)
PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;
PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
#endif /* defined(VK_EXT_validation_cache) */
#if defined(VK_FUCHSIA_buffer_collection)
PFN_vkCreateBufferCollectionFUCHSIA vkCreateBufferCollectionFUCHSIA;
PFN_vkDestroyBufferCollectionFUCHSIA vkDestroyBufferCollectionFUCHSIA;
PFN_vkGetBufferCollectionPropertiesFUCHSIA vkGetBufferCollectionPropertiesFUCHSIA;
PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA vkSetBufferCollectionBufferConstraintsFUCHSIA;
PFN_vkSetBufferCollectionImageConstraintsFUCHSIA vkSetBufferCollectionImageConstraintsFUCHSIA;
#endif /* defined(VK_FUCHSIA_buffer_collection) */
#if defined(VK_FUCHSIA_external_memory)
PFN_vkGetMemoryZirconHandleFUCHSIA vkGetMemoryZirconHandleFUCHSIA;
PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA vkGetMemoryZirconHandlePropertiesFUCHSIA;
#endif /* defined(VK_FUCHSIA_external_memory) */
#if defined(VK_FUCHSIA_external_semaphore)
PFN_vkGetSemaphoreZirconHandleFUCHSIA vkGetSemaphoreZirconHandleFUCHSIA;
PFN_vkImportSemaphoreZirconHandleFUCHSIA vkImportSemaphoreZirconHandleFUCHSIA;
#endif /* defined(VK_FUCHSIA_external_semaphore) */
#if defined(VK_FUCHSIA_imagepipe_surface)
PFN_vkCreateImagePipeSurfaceFUCHSIA vkCreateImagePipeSurfaceFUCHSIA;
#endif /* defined(VK_FUCHSIA_imagepipe_surface) */
#if defined(VK_GGP_stream_descriptor_surface)
PFN_vkCreateStreamDescriptorSurfaceGGP vkCreateStreamDescriptorSurfaceGGP;
#endif /* defined(VK_GGP_stream_descriptor_surface) */
#if defined(VK_GOOGLE_display_timing)
PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;
PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
#endif /* defined(VK_GOOGLE_display_timing) */
#if defined(VK_HUAWEI_cluster_culling_shader)
PFN_vkCmdDrawClusterHUAWEI vkCmdDrawClusterHUAWEI;
PFN_vkCmdDrawClusterIndirectHUAWEI vkCmdDrawClusterIndirectHUAWEI;
#endif /* defined(VK_HUAWEI_cluster_culling_shader) */
#if defined(VK_HUAWEI_invocation_mask)
PFN_vkCmdBindInvocationMaskHUAWEI vkCmdBindInvocationMaskHUAWEI;
#endif /* defined(VK_HUAWEI_invocation_mask) */
#if defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2
PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;
#endif /* defined(VK_HUAWEI_subpass_shading) && VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION >= 2 */
#if defined(VK_HUAWEI_subpass_shading)
PFN_vkCmdSubpassShadingHUAWEI vkCmdSubpassShadingHUAWEI;
#endif /* defined(VK_HUAWEI_subpass_shading) */
#if defined(VK_INTEL_performance_query)
PFN_vkAcquirePerformanceConfigurationINTEL vkAcquirePerformanceConfigurationINTEL;
PFN_vkCmdSetPerformanceMarkerINTEL vkCmdSetPerformanceMarkerINTEL;
PFN_vkCmdSetPerformanceOverrideINTEL vkCmdSetPerformanceOverrideINTEL;
PFN_vkCmdSetPerformanceStreamMarkerINTEL vkCmdSetPerformanceStreamMarkerINTEL;
PFN_vkGetPerformanceParameterINTEL vkGetPerformanceParameterINTEL;
PFN_vkInitializePerformanceApiINTEL vkInitializePerformanceApiINTEL;
PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL;
PFN_vkReleasePerformanceConfigurationINTEL vkReleasePerformanceConfigurationINTEL;
PFN_vkUninitializePerformanceApiINTEL vkUninitializePerformanceApiINTEL;
#endif /* defined(VK_INTEL_performance_query) */
#if defined(VK_KHR_acceleration_structure)
PFN_vkBuildAccelerationStructuresKHR vkBuildAccelerationStructuresKHR;
PFN_vkCmdBuildAccelerationStructuresIndirectKHR vkCmdBuildAccelerationStructuresIndirectKHR;
PFN_vkCmdBuildAccelerationStructuresKHR vkCmdBuildAccelerationStructuresKHR;
PFN_vkCmdCopyAccelerationStructureKHR vkCmdCopyAccelerationStructureKHR;
PFN_vkCmdCopyAccelerationStructureToMemoryKHR vkCmdCopyAccelerationStructureToMemoryKHR;
PFN_vkCmdCopyMemoryToAccelerationStructureKHR vkCmdCopyMemoryToAccelerationStructureKHR;
PFN_vkCmdWriteAccelerationStructuresPropertiesKHR vkCmdWriteAccelerationStructuresPropertiesKHR;
PFN_vkCopyAccelerationStructureKHR vkCopyAccelerationStructureKHR;
PFN_vkCopyAccelerationStructureToMemoryKHR vkCopyAccelerationStructureToMemoryKHR;
PFN_vkCopyMemoryToAccelerationStructureKHR vkCopyMemoryToAccelerationStructureKHR;
PFN_vkCreateAccelerationStructureKHR vkCreateAccelerationStructureKHR;
PFN_vkDestroyAccelerationStructureKHR vkDestroyAccelerationStructureKHR;
PFN_vkGetAccelerationStructureBuildSizesKHR vkGetAccelerationStructureBuildSizesKHR;
PFN_vkGetAccelerationStructureDeviceAddressKHR vkGetAccelerationStructureDeviceAddressKHR;
PFN_vkGetDeviceAccelerationStructureCompatibilityKHR vkGetDeviceAccelerationStructureCompatibilityKHR;
PFN_vkWriteAccelerationStructuresPropertiesKHR vkWriteAccelerationStructuresPropertiesKHR;
#endif /* defined(VK_KHR_acceleration_structure) */
#if defined(VK_KHR_android_surface)
PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
#endif /* defined(VK_KHR_android_surface) */
#if defined(VK_KHR_bind_memory2)
PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;
#endif /* defined(VK_KHR_bind_memory2) */
#if defined(VK_KHR_buffer_device_address)
PFN_vkGetBufferDeviceAddressKHR vkGetBufferDeviceAddressKHR;
PFN_vkGetBufferOpaqueCaptureAddressKHR vkGetBufferOpaqueCaptureAddressKHR;
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vkGetDeviceMemoryOpaqueCaptureAddressKHR;
#endif /* defined(VK_KHR_buffer_device_address) */
#if defined(VK_KHR_calibrated_timestamps)
PFN_vkGetCalibratedTimestampsKHR vkGetCalibratedTimestampsKHR;
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR vkGetPhysicalDeviceCalibrateableTimeDomainsKHR;
#endif /* defined(VK_KHR_calibrated_timestamps) */
#if defined(VK_KHR_cooperative_matrix)
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;
#endif /* defined(VK_KHR_cooperative_matrix) */
#if defined(VK_KHR_copy_commands2)
PFN_vkCmdBlitImage2KHR vkCmdBlitImage2KHR;
PFN_vkCmdCopyBuffer2KHR vkCmdCopyBuffer2KHR;
PFN_vkCmdCopyBufferToImage2KHR vkCmdCopyBufferToImage2KHR;
PFN_vkCmdCopyImage2KHR vkCmdCopyImage2KHR;
PFN_vkCmdCopyImageToBuffer2KHR vkCmdCopyImageToBuffer2KHR;
PFN_vkCmdResolveImage2KHR vkCmdResolveImage2KHR;
#endif /* defined(VK_KHR_copy_commands2) */
#if defined(VK_KHR_copy_memory_indirect)
PFN_vkCmdCopyMemoryIndirectKHR vkCmdCopyMemoryIndirectKHR;
PFN_vkCmdCopyMemoryToImageIndirectKHR vkCmdCopyMemoryToImageIndirectKHR;
#endif /* defined(VK_KHR_copy_memory_indirect) */
#if defined(VK_KHR_create_renderpass2)
PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR;
PFN_vkCmdEndRenderPass2KHR vkCmdEndRenderPass2KHR;
PFN_vkCmdNextSubpass2KHR vkCmdNextSubpass2KHR;
PFN_vkCreateRenderPass2KHR vkCreateRenderPass2KHR;
#endif /* defined(VK_KHR_create_renderpass2) */
#if defined(VK_KHR_deferred_host_operations)
PFN_vkCreateDeferredOperationKHR vkCreateDeferredOperationKHR;
PFN_vkDeferredOperationJoinKHR vkDeferredOperationJoinKHR;
PFN_vkDestroyDeferredOperationKHR vkDestroyDeferredOperationKHR;
PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR;
PFN_vkGetDeferredOperationResultKHR vkGetDeferredOperationResultKHR;
#endif /* defined(VK_KHR_deferred_host_operations) */
#if defined(VK_KHR_descriptor_update_template)
PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;
#endif /* defined(VK_KHR_descriptor_update_template) */
#if defined(VK_KHR_device_group)
PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;
PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
#endif /* defined(VK_KHR_device_group) */
#if defined(VK_KHR_device_group_creation)
PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;
#endif /* defined(VK_KHR_device_group_creation) */
#if defined(VK_KHR_display)
PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
#endif /* defined(VK_KHR_display) */
#if defined(VK_KHR_display_swapchain)
PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
#endif /* defined(VK_KHR_display_swapchain) */
#if defined(VK_KHR_draw_indirect_count)
PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR;
PFN_vkCmdDrawIndirectCountKHR vkCmdDrawIndirectCountKHR;
#endif /* defined(VK_KHR_draw_indirect_count) */
#if defined(VK_KHR_dynamic_rendering)
PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR;
PFN_vkCmdEndRenderingKHR vkCmdEndRenderingKHR;
#endif /* defined(VK_KHR_dynamic_rendering) */
#if defined(VK_KHR_dynamic_rendering_local_read)
PFN_vkCmdSetRenderingAttachmentLocationsKHR vkCmdSetRenderingAttachmentLocationsKHR;
PFN_vkCmdSetRenderingInputAttachmentIndicesKHR vkCmdSetRenderingInputAttachmentIndicesKHR;
#endif /* defined(VK_KHR_dynamic_rendering_local_read) */
#if defined(VK_KHR_external_fence_capabilities)
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;
#endif /* defined(VK_KHR_external_fence_capabilities) */
#if defined(VK_KHR_external_fence_fd)
PFN_vkGetFenceFdKHR vkGetFenceFdKHR;
PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
#endif /* defined(VK_KHR_external_fence_fd) */
#if defined(VK_KHR_external_fence_win32)
PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
#endif /* defined(VK_KHR_external_fence_win32) */
#if defined(VK_KHR_external_memory_capabilities)
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;
#endif /* defined(VK_KHR_external_memory_capabilities) */
#if defined(VK_KHR_external_memory_fd)
PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;
#endif /* defined(VK_KHR_external_memory_fd) */
#if defined(VK_KHR_external_memory_win32)
PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR;
PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR;
#endif /* defined(VK_KHR_external_memory_win32) */
#if defined(VK_KHR_external_semaphore_capabilities)
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
#endif /* defined(VK_KHR_external_semaphore_capabilities) */
#if defined(VK_KHR_external_semaphore_fd)
PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
#endif /* defined(VK_KHR_external_semaphore_fd) */
#if defined(VK_KHR_external_semaphore_win32)
PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR;
PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR;
#endif /* defined(VK_KHR_external_semaphore_win32) */
#if defined(VK_KHR_fragment_shading_rate)
PFN_vkCmdSetFragmentShadingRateKHR vkCmdSetFragmentShadingRateKHR;
PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR vkGetPhysicalDeviceFragmentShadingRatesKHR;
#endif /* defined(VK_KHR_fragment_shading_rate) */
#if defined(VK_KHR_get_display_properties2)
PFN_vkGetDisplayModeProperties2KHR vkGetDisplayModeProperties2KHR;
PFN_vkGetDisplayPlaneCapabilities2KHR vkGetDisplayPlaneCapabilities2KHR;
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
PFN_vkGetPhysicalDeviceDisplayProperties2KHR vkGetPhysicalDeviceDisplayProperties2KHR;
#endif /* defined(VK_KHR_get_display_properties2) */
#if defined(VK_KHR_get_memory_requirements2)
PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;
#endif /* defined(VK_KHR_get_memory_requirements2) */
#if defined(VK_KHR_get_physical_device_properties2)
PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
#endif /* defined(VK_KHR_get_physical_device_properties2) */
#if defined(VK_KHR_get_surface_capabilities2)
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;
#endif /* defined(VK_KHR_get_surface_capabilities2) */
#if defined(VK_KHR_line_rasterization)
PFN_vkCmdSetLineStippleKHR vkCmdSetLineStippleKHR;
#endif /* defined(VK_KHR_line_rasterization) */
#if defined(VK_KHR_maintenance1)
PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;
#endif /* defined(VK_KHR_maintenance1) */
#if defined(VK_KHR_maintenance10)
PFN_vkCmdEndRendering2KHR vkCmdEndRendering2KHR;
#endif /* defined(VK_KHR_maintenance10) */
#if defined(VK_KHR_maintenance3)
PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;
#endif /* defined(VK_KHR_maintenance3) */
#if defined(VK_KHR_maintenance4)
PFN_vkGetDeviceBufferMemoryRequirementsKHR vkGetDeviceBufferMemoryRequirementsKHR;
PFN_vkGetDeviceImageMemoryRequirementsKHR vkGetDeviceImageMemoryRequirementsKHR;
PFN_vkGetDeviceImageSparseMemoryRequirementsKHR vkGetDeviceImageSparseMemoryRequirementsKHR;
#endif /* defined(VK_KHR_maintenance4) */
#if defined(VK_KHR_maintenance5)
PFN_vkCmdBindIndexBuffer2KHR vkCmdBindIndexBuffer2KHR;
PFN_vkGetDeviceImageSubresourceLayoutKHR vkGetDeviceImageSubresourceLayoutKHR;
PFN_vkGetImageSubresourceLayout2KHR vkGetImageSubresourceLayout2KHR;
PFN_vkGetRenderingAreaGranularityKHR vkGetRenderingAreaGranularityKHR;
#endif /* defined(VK_KHR_maintenance5) */
#if defined(VK_KHR_maintenance6)
PFN_vkCmdBindDescriptorSets2KHR vkCmdBindDescriptorSets2KHR;
PFN_vkCmdPushConstants2KHR vkCmdPushConstants2KHR;
#endif /* defined(VK_KHR_maintenance6) */
#if defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor)
PFN_vkCmdPushDescriptorSet2KHR vkCmdPushDescriptorSet2KHR;
PFN_vkCmdPushDescriptorSetWithTemplate2KHR vkCmdPushDescriptorSetWithTemplate2KHR;
#endif /* defined(VK_KHR_maintenance6) && defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer)
PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT vkCmdBindDescriptorBufferEmbeddedSamplers2EXT;
PFN_vkCmdSetDescriptorBufferOffsets2EXT vkCmdSetDescriptorBufferOffsets2EXT;
#endif /* defined(VK_KHR_maintenance6) && defined(VK_EXT_descriptor_buffer) */
#if defined(VK_KHR_map_memory2)
PFN_vkMapMemory2KHR vkMapMemory2KHR;
PFN_vkUnmapMemory2KHR vkUnmapMemory2KHR;
#endif /* defined(VK_KHR_map_memory2) */
#if defined(VK_KHR_performance_query)
PFN_vkAcquireProfilingLockKHR vkAcquireProfilingLockKHR;
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
PFN_vkReleaseProfilingLockKHR vkReleaseProfilingLockKHR;
#endif /* defined(VK_KHR_performance_query) */
#if defined(VK_KHR_pipeline_binary)
PFN_vkCreatePipelineBinariesKHR vkCreatePipelineBinariesKHR;
PFN_vkDestroyPipelineBinaryKHR vkDestroyPipelineBinaryKHR;
PFN_vkGetPipelineBinaryDataKHR vkGetPipelineBinaryDataKHR;
PFN_vkGetPipelineKeyKHR vkGetPipelineKeyKHR;
PFN_vkReleaseCapturedPipelineDataKHR vkReleaseCapturedPipelineDataKHR;
#endif /* defined(VK_KHR_pipeline_binary) */
#if defined(VK_KHR_pipeline_executable_properties)
PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR;
PFN_vkGetPipelineExecutablePropertiesKHR vkGetPipelineExecutablePropertiesKHR;
PFN_vkGetPipelineExecutableStatisticsKHR vkGetPipelineExecutableStatisticsKHR;
#endif /* defined(VK_KHR_pipeline_executable_properties) */
#if defined(VK_KHR_present_wait)
PFN_vkWaitForPresentKHR vkWaitForPresentKHR;
#endif /* defined(VK_KHR_present_wait) */
#if defined(VK_KHR_present_wait2)
PFN_vkWaitForPresent2KHR vkWaitForPresent2KHR;
#endif /* defined(VK_KHR_present_wait2) */
#if defined(VK_KHR_push_descriptor)
PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
#endif /* defined(VK_KHR_push_descriptor) */
#if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
PFN_vkCmdTraceRaysIndirect2KHR vkCmdTraceRaysIndirect2KHR;
#endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_ray_tracing_pipeline)
PFN_vkCmdSetRayTracingPipelineStackSizeKHR vkCmdSetRayTracingPipelineStackSizeKHR;
PFN_vkCmdTraceRaysIndirectKHR vkCmdTraceRaysIndirectKHR;
PFN_vkCmdTraceRaysKHR vkCmdTraceRaysKHR;
PFN_vkCreateRayTracingPipelinesKHR vkCreateRayTracingPipelinesKHR;
PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
PFN_vkGetRayTracingShaderGroupHandlesKHR vkGetRayTracingShaderGroupHandlesKHR;
PFN_vkGetRayTracingShaderGroupStackSizeKHR vkGetRayTracingShaderGroupStackSizeKHR;
#endif /* defined(VK_KHR_ray_tracing_pipeline) */
#if defined(VK_KHR_sampler_ycbcr_conversion)
PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;
#endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
#if defined(VK_KHR_shared_presentable_image)
PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
#endif /* defined(VK_KHR_shared_presentable_image) */
#if defined(VK_KHR_surface)
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
#endif /* defined(VK_KHR_surface) */
#if defined(VK_KHR_swapchain)
PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
PFN_vkQueuePresentKHR vkQueuePresentKHR;
#endif /* defined(VK_KHR_swapchain) */
#if defined(VK_KHR_swapchain_maintenance1)
PFN_vkReleaseSwapchainImagesKHR vkReleaseSwapchainImagesKHR;
#endif /* defined(VK_KHR_swapchain_maintenance1) */
#if defined(VK_KHR_synchronization2)
PFN_vkCmdPipelineBarrier2KHR vkCmdPipelineBarrier2KHR;
PFN_vkCmdResetEvent2KHR vkCmdResetEvent2KHR;
PFN_vkCmdSetEvent2KHR vkCmdSetEvent2KHR;
PFN_vkCmdWaitEvents2KHR vkCmdWaitEvents2KHR;
PFN_vkCmdWriteTimestamp2KHR vkCmdWriteTimestamp2KHR;
PFN_vkQueueSubmit2KHR vkQueueSubmit2KHR;
#endif /* defined(VK_KHR_synchronization2) */
#if defined(VK_KHR_timeline_semaphore)
PFN_vkGetSemaphoreCounterValueKHR vkGetSemaphoreCounterValueKHR;
PFN_vkSignalSemaphoreKHR vkSignalSemaphoreKHR;
PFN_vkWaitSemaphoresKHR vkWaitSemaphoresKHR;
#endif /* defined(VK_KHR_timeline_semaphore) */
#if defined(VK_KHR_video_decode_queue)
PFN_vkCmdDecodeVideoKHR vkCmdDecodeVideoKHR;
#endif /* defined(VK_KHR_video_decode_queue) */
#if defined(VK_KHR_video_encode_queue)
PFN_vkCmdEncodeVideoKHR vkCmdEncodeVideoKHR;
PFN_vkGetEncodedVideoSessionParametersKHR vkGetEncodedVideoSessionParametersKHR;
PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;
#endif /* defined(VK_KHR_video_encode_queue) */
#if defined(VK_KHR_video_queue)
PFN_vkBindVideoSessionMemoryKHR vkBindVideoSessionMemoryKHR;
PFN_vkCmdBeginVideoCodingKHR vkCmdBeginVideoCodingKHR;
PFN_vkCmdControlVideoCodingKHR vkCmdControlVideoCodingKHR;
PFN_vkCmdEndVideoCodingKHR vkCmdEndVideoCodingKHR;
PFN_vkCreateVideoSessionKHR vkCreateVideoSessionKHR;
PFN_vkCreateVideoSessionParametersKHR vkCreateVideoSessionParametersKHR;
PFN_vkDestroyVideoSessionKHR vkDestroyVideoSessionKHR;
PFN_vkDestroyVideoSessionParametersKHR vkDestroyVideoSessionParametersKHR;
PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR vkGetPhysicalDeviceVideoCapabilitiesKHR;
PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR vkGetPhysicalDeviceVideoFormatPropertiesKHR;
PFN_vkGetVideoSessionMemoryRequirementsKHR vkGetVideoSessionMemoryRequirementsKHR;
PFN_vkUpdateVideoSessionParametersKHR vkUpdateVideoSessionParametersKHR;
#endif /* defined(VK_KHR_video_queue) */
#if defined(VK_KHR_wayland_surface)
PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif /* defined(VK_KHR_wayland_surface) */
#if defined(VK_KHR_win32_surface)
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif /* defined(VK_KHR_win32_surface) */
#if defined(VK_KHR_xcb_surface)
PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif /* defined(VK_KHR_xcb_surface) */
#if defined(VK_KHR_xlib_surface)
PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif /* defined(VK_KHR_xlib_surface) */
#if defined(VK_MVK_ios_surface)
PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK;
#endif /* defined(VK_MVK_ios_surface) */
#if defined(VK_MVK_macos_surface)
PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
#endif /* defined(VK_MVK_macos_surface) */
#if defined(VK_NN_vi_surface)
PFN_vkCreateViSurfaceNN vkCreateViSurfaceNN;
#endif /* defined(VK_NN_vi_surface) */
#if defined(VK_NVX_binary_import)
PFN_vkCmdCuLaunchKernelNVX vkCmdCuLaunchKernelNVX;
PFN_vkCreateCuFunctionNVX vkCreateCuFunctionNVX;
PFN_vkCreateCuModuleNVX vkCreateCuModuleNVX;
PFN_vkDestroyCuFunctionNVX vkDestroyCuFunctionNVX;
PFN_vkDestroyCuModuleNVX vkDestroyCuModuleNVX;
#endif /* defined(VK_NVX_binary_import) */
#if defined(VK_NVX_image_view_handle)
PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;
#endif /* defined(VK_NVX_image_view_handle) */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3
PFN_vkGetImageViewHandle64NVX vkGetImageViewHandle64NVX;
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 3 */
#if defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2
PFN_vkGetImageViewAddressNVX vkGetImageViewAddressNVX;
#endif /* defined(VK_NVX_image_view_handle) && VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION >= 2 */
#if defined(VK_NV_acquire_winrt_display)
PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV;
PFN_vkGetWinrtDisplayNV vkGetWinrtDisplayNV;
#endif /* defined(VK_NV_acquire_winrt_display) */
#if defined(VK_NV_clip_space_w_scaling)
PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;
#endif /* defined(VK_NV_clip_space_w_scaling) */
#if defined(VK_NV_cluster_acceleration_structure)
PFN_vkCmdBuildClusterAccelerationStructureIndirectNV vkCmdBuildClusterAccelerationStructureIndirectNV;
PFN_vkGetClusterAccelerationStructureBuildSizesNV vkGetClusterAccelerationStructureBuildSizesNV;
#endif /* defined(VK_NV_cluster_acceleration_structure) */
#if defined(VK_NV_compute_occupancy_priority)
PFN_vkCmdSetComputeOccupancyPriorityNV vkCmdSetComputeOccupancyPriorityNV;
#endif /* defined(VK_NV_compute_occupancy_priority) */
#if defined(VK_NV_cooperative_matrix)
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
#endif /* defined(VK_NV_cooperative_matrix) */
#if defined(VK_NV_cooperative_matrix2)
PFN_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV;
#endif /* defined(VK_NV_cooperative_matrix2) */
#if defined(VK_NV_cooperative_vector)
PFN_vkCmdConvertCooperativeVectorMatrixNV vkCmdConvertCooperativeVectorMatrixNV;
PFN_vkConvertCooperativeVectorMatrixNV vkConvertCooperativeVectorMatrixNV;
PFN_vkGetPhysicalDeviceCooperativeVectorPropertiesNV vkGetPhysicalDeviceCooperativeVectorPropertiesNV;
#endif /* defined(VK_NV_cooperative_vector) */
#if defined(VK_NV_copy_memory_indirect)
PFN_vkCmdCopyMemoryIndirectNV vkCmdCopyMemoryIndirectNV;
PFN_vkCmdCopyMemoryToImageIndirectNV vkCmdCopyMemoryToImageIndirectNV;
#endif /* defined(VK_NV_copy_memory_indirect) */
#if defined(VK_NV_coverage_reduction_mode)
PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
#endif /* defined(VK_NV_coverage_reduction_mode) */
#if defined(VK_NV_cuda_kernel_launch)
PFN_vkCmdCudaLaunchKernelNV vkCmdCudaLaunchKernelNV;
PFN_vkCreateCudaFunctionNV vkCreateCudaFunctionNV;
PFN_vkCreateCudaModuleNV vkCreateCudaModuleNV;
PFN_vkDestroyCudaFunctionNV vkDestroyCudaFunctionNV;
PFN_vkDestroyCudaModuleNV vkDestroyCudaModuleNV;
PFN_vkGetCudaModuleCacheNV vkGetCudaModuleCacheNV;
#endif /* defined(VK_NV_cuda_kernel_launch) */
#if defined(VK_NV_device_diagnostic_checkpoints)
PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;
#endif /* defined(VK_NV_device_diagnostic_checkpoints) */
#if defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2))
PFN_vkGetQueueCheckpointData2NV vkGetQueueCheckpointData2NV;
#endif /* defined(VK_NV_device_diagnostic_checkpoints) && (defined(VK_VERSION_1_3) || defined(VK_KHR_synchronization2)) */
#if defined(VK_NV_device_generated_commands)
PFN_vkCmdBindPipelineShaderGroupNV vkCmdBindPipelineShaderGroupNV;
PFN_vkCmdExecuteGeneratedCommandsNV vkCmdExecuteGeneratedCommandsNV;
PFN_vkCmdPreprocessGeneratedCommandsNV vkCmdPreprocessGeneratedCommandsNV;
PFN_vkCreateIndirectCommandsLayoutNV vkCreateIndirectCommandsLayoutNV;
PFN_vkDestroyIndirectCommandsLayoutNV vkDestroyIndirectCommandsLayoutNV;
PFN_vkGetGeneratedCommandsMemoryRequirementsNV vkGetGeneratedCommandsMemoryRequirementsNV;
#endif /* defined(VK_NV_device_generated_commands) */
#if defined(VK_NV_device_generated_commands_compute)
PFN_vkCmdUpdatePipelineIndirectBufferNV vkCmdUpdatePipelineIndirectBufferNV;
PFN_vkGetPipelineIndirectDeviceAddressNV vkGetPipelineIndirectDeviceAddressNV;
PFN_vkGetPipelineIndirectMemoryRequirementsNV vkGetPipelineIndirectMemoryRequirementsNV;
#endif /* defined(VK_NV_device_generated_commands_compute) */
#if defined(VK_NV_external_compute_queue)
PFN_vkCreateExternalComputeQueueNV vkCreateExternalComputeQueueNV;
PFN_vkDestroyExternalComputeQueueNV vkDestroyExternalComputeQueueNV;
PFN_vkGetExternalComputeQueueDataNV vkGetExternalComputeQueueDataNV;
#endif /* defined(VK_NV_external_compute_queue) */
#if defined(VK_NV_external_memory_capabilities)
PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
#endif /* defined(VK_NV_external_memory_capabilities) */
#if defined(VK_NV_external_memory_rdma)
PFN_vkGetMemoryRemoteAddressNV vkGetMemoryRemoteAddressNV;
#endif /* defined(VK_NV_external_memory_rdma) */
#if defined(VK_NV_external_memory_win32)
PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
#endif /* defined(VK_NV_external_memory_win32) */
#if defined(VK_NV_fragment_shading_rate_enums)
PFN_vkCmdSetFragmentShadingRateEnumNV vkCmdSetFragmentShadingRateEnumNV;
#endif /* defined(VK_NV_fragment_shading_rate_enums) */
#if defined(VK_NV_low_latency2)
PFN_vkGetLatencyTimingsNV vkGetLatencyTimingsNV;
PFN_vkLatencySleepNV vkLatencySleepNV;
PFN_vkQueueNotifyOutOfBandNV vkQueueNotifyOutOfBandNV;
PFN_vkSetLatencyMarkerNV vkSetLatencyMarkerNV;
PFN_vkSetLatencySleepModeNV vkSetLatencySleepModeNV;
#endif /* defined(VK_NV_low_latency2) */
#if defined(VK_NV_memory_decompression)
PFN_vkCmdDecompressMemoryIndirectCountNV vkCmdDecompressMemoryIndirectCountNV;
PFN_vkCmdDecompressMemoryNV vkCmdDecompressMemoryNV;
#endif /* defined(VK_NV_memory_decompression) */
#if defined(VK_NV_mesh_shader)
PFN_vkCmdDrawMeshTasksIndirectNV vkCmdDrawMeshTasksIndirectNV;
PFN_vkCmdDrawMeshTasksNV vkCmdDrawMeshTasksNV;
#endif /* defined(VK_NV_mesh_shader) */
#if defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count))
PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV;
#endif /* defined(VK_NV_mesh_shader) && (defined(VK_VERSION_1_2) || defined(VK_KHR_draw_indirect_count) || defined(VK_AMD_draw_indirect_count)) */
#if defined(VK_NV_optical_flow)
PFN_vkBindOpticalFlowSessionImageNV vkBindOpticalFlowSessionImageNV;
PFN_vkCmdOpticalFlowExecuteNV vkCmdOpticalFlowExecuteNV;
PFN_vkCreateOpticalFlowSessionNV vkCreateOpticalFlowSessionNV;
PFN_vkDestroyOpticalFlowSessionNV vkDestroyOpticalFlowSessionNV;
PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV vkGetPhysicalDeviceOpticalFlowImageFormatsNV;
#endif /* defined(VK_NV_optical_flow) */
#if defined(VK_NV_partitioned_acceleration_structure)
PFN_vkCmdBuildPartitionedAccelerationStructuresNV vkCmdBuildPartitionedAccelerationStructuresNV;
PFN_vkGetPartitionedAccelerationStructuresBuildSizesNV vkGetPartitionedAccelerationStructuresBuildSizesNV;
#endif /* defined(VK_NV_partitioned_acceleration_structure) */
#if defined(VK_NV_ray_tracing)
PFN_vkBindAccelerationStructureMemoryNV vkBindAccelerationStructureMemoryNV;
PFN_vkCmdBuildAccelerationStructureNV vkCmdBuildAccelerationStructureNV;
PFN_vkCmdCopyAccelerationStructureNV vkCmdCopyAccelerationStructureNV;
PFN_vkCmdTraceRaysNV vkCmdTraceRaysNV;
PFN_vkCmdWriteAccelerationStructuresPropertiesNV vkCmdWriteAccelerationStructuresPropertiesNV;
PFN_vkCompileDeferredNV vkCompileDeferredNV;
PFN_vkCreateAccelerationStructureNV vkCreateAccelerationStructureNV;
PFN_vkCreateRayTracingPipelinesNV vkCreateRayTracingPipelinesNV;
PFN_vkDestroyAccelerationStructureNV vkDestroyAccelerationStructureNV;
PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV;
PFN_vkGetRayTracingShaderGroupHandlesNV vkGetRayTracingShaderGroupHandlesNV;
#endif /* defined(VK_NV_ray_tracing) */
#if defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2
PFN_vkCmdSetExclusiveScissorEnableNV vkCmdSetExclusiveScissorEnableNV;
#endif /* defined(VK_NV_scissor_exclusive) && VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION >= 2 */
#if defined(VK_NV_scissor_exclusive)
PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;
#endif /* defined(VK_NV_scissor_exclusive) */
#if defined(VK_NV_shading_rate_image)
PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;
PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
#endif /* defined(VK_NV_shading_rate_image) */
#if defined(VK_OHOS_external_memory)
PFN_vkGetMemoryNativeBufferOHOS vkGetMemoryNativeBufferOHOS;
PFN_vkGetNativeBufferPropertiesOHOS vkGetNativeBufferPropertiesOHOS;
#endif /* defined(VK_OHOS_external_memory) */
#if defined(VK_OHOS_surface)
PFN_vkCreateSurfaceOHOS vkCreateSurfaceOHOS;
#endif /* defined(VK_OHOS_surface) */
#if defined(VK_QCOM_tile_memory_heap)
PFN_vkCmdBindTileMemoryQCOM vkCmdBindTileMemoryQCOM;
#endif /* defined(VK_QCOM_tile_memory_heap) */
#if defined(VK_QCOM_tile_properties)
PFN_vkGetDynamicRenderingTilePropertiesQCOM vkGetDynamicRenderingTilePropertiesQCOM;
PFN_vkGetFramebufferTilePropertiesQCOM vkGetFramebufferTilePropertiesQCOM;
#endif /* defined(VK_QCOM_tile_properties) */
#if defined(VK_QCOM_tile_shading)
PFN_vkCmdBeginPerTileExecutionQCOM vkCmdBeginPerTileExecutionQCOM;
PFN_vkCmdDispatchTileQCOM vkCmdDispatchTileQCOM;
PFN_vkCmdEndPerTileExecutionQCOM vkCmdEndPerTileExecutionQCOM;
#endif /* defined(VK_QCOM_tile_shading) */
#if defined(VK_QNX_external_memory_screen_buffer)
PFN_vkGetScreenBufferPropertiesQNX vkGetScreenBufferPropertiesQNX;
#endif /* defined(VK_QNX_external_memory_screen_buffer) */
#if defined(VK_QNX_screen_surface)
PFN_vkCreateScreenSurfaceQNX vkCreateScreenSurfaceQNX;
PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX vkGetPhysicalDeviceScreenPresentationSupportQNX;
#endif /* defined(VK_QNX_screen_surface) */
#if defined(VK_VALVE_descriptor_set_host_mapping)
PFN_vkGetDescriptorSetHostMappingVALVE vkGetDescriptorSetHostMappingVALVE;
PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vkGetDescriptorSetLayoutHostMappingInfoVALVE;
#endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
#if (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control))
PFN_vkCmdSetDepthClampRangeEXT vkCmdSetDepthClampRangeEXT;
#endif /* (defined(VK_EXT_depth_clamp_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clamp_control)) */
#if (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object))
PFN_vkCmdBindVertexBuffers2EXT vkCmdBindVertexBuffers2EXT;
PFN_vkCmdSetCullModeEXT vkCmdSetCullModeEXT;
PFN_vkCmdSetDepthBoundsTestEnableEXT vkCmdSetDepthBoundsTestEnableEXT;
PFN_vkCmdSetDepthCompareOpEXT vkCmdSetDepthCompareOpEXT;
PFN_vkCmdSetDepthTestEnableEXT vkCmdSetDepthTestEnableEXT;
PFN_vkCmdSetDepthWriteEnableEXT vkCmdSetDepthWriteEnableEXT;
PFN_vkCmdSetFrontFaceEXT vkCmdSetFrontFaceEXT;
PFN_vkCmdSetPrimitiveTopologyEXT vkCmdSetPrimitiveTopologyEXT;
PFN_vkCmdSetScissorWithCountEXT vkCmdSetScissorWithCountEXT;
PFN_vkCmdSetStencilOpEXT vkCmdSetStencilOpEXT;
PFN_vkCmdSetStencilTestEnableEXT vkCmdSetStencilTestEnableEXT;
PFN_vkCmdSetViewportWithCountEXT vkCmdSetViewportWithCountEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object))
PFN_vkCmdSetDepthBiasEnableEXT vkCmdSetDepthBiasEnableEXT;
PFN_vkCmdSetLogicOpEXT vkCmdSetLogicOpEXT;
PFN_vkCmdSetPatchControlPointsEXT vkCmdSetPatchControlPointsEXT;
PFN_vkCmdSetPrimitiveRestartEnableEXT vkCmdSetPrimitiveRestartEnableEXT;
PFN_vkCmdSetRasterizerDiscardEnableEXT vkCmdSetRasterizerDiscardEnableEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state2)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object))
PFN_vkCmdSetAlphaToCoverageEnableEXT vkCmdSetAlphaToCoverageEnableEXT;
PFN_vkCmdSetAlphaToOneEnableEXT vkCmdSetAlphaToOneEnableEXT;
PFN_vkCmdSetColorBlendEnableEXT vkCmdSetColorBlendEnableEXT;
PFN_vkCmdSetColorBlendEquationEXT vkCmdSetColorBlendEquationEXT;
PFN_vkCmdSetColorWriteMaskEXT vkCmdSetColorWriteMaskEXT;
PFN_vkCmdSetDepthClampEnableEXT vkCmdSetDepthClampEnableEXT;
PFN_vkCmdSetLogicOpEnableEXT vkCmdSetLogicOpEnableEXT;
PFN_vkCmdSetPolygonModeEXT vkCmdSetPolygonModeEXT;
PFN_vkCmdSetRasterizationSamplesEXT vkCmdSetRasterizationSamplesEXT;
PFN_vkCmdSetSampleMaskEXT vkCmdSetSampleMaskEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3)) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object))
PFN_vkCmdSetTessellationDomainOriginEXT vkCmdSetTessellationDomainOriginEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && (defined(VK_KHR_maintenance2) || defined(VK_VERSION_1_1))) || (defined(VK_EXT_shader_object)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback))
PFN_vkCmdSetRasterizationStreamEXT vkCmdSetRasterizationStreamEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_transform_feedback)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_transform_feedback)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization))
PFN_vkCmdSetConservativeRasterizationModeEXT vkCmdSetConservativeRasterizationModeEXT;
PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT vkCmdSetExtraPrimitiveOverestimationSizeEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_conservative_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_conservative_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable))
PFN_vkCmdSetDepthClipEnableEXT vkCmdSetDepthClipEnableEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_enable)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_enable)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations))
PFN_vkCmdSetSampleLocationsEnableEXT vkCmdSetSampleLocationsEnableEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_sample_locations)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_sample_locations)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced))
PFN_vkCmdSetColorBlendAdvancedEXT vkCmdSetColorBlendAdvancedEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_blend_operation_advanced)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_blend_operation_advanced)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex))
PFN_vkCmdSetProvokingVertexModeEXT vkCmdSetProvokingVertexModeEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_provoking_vertex)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_provoking_vertex)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization))
PFN_vkCmdSetLineRasterizationModeEXT vkCmdSetLineRasterizationModeEXT;
PFN_vkCmdSetLineStippleEnableEXT vkCmdSetLineStippleEnableEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_line_rasterization)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_line_rasterization)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control))
PFN_vkCmdSetDepthClipNegativeOneToOneEXT vkCmdSetDepthClipNegativeOneToOneEXT;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_EXT_depth_clip_control)) || (defined(VK_EXT_shader_object) && defined(VK_EXT_depth_clip_control)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling))
PFN_vkCmdSetViewportWScalingEnableNV vkCmdSetViewportWScalingEnableNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_clip_space_w_scaling)) || (defined(VK_EXT_shader_object) && defined(VK_NV_clip_space_w_scaling)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle))
PFN_vkCmdSetViewportSwizzleNV vkCmdSetViewportSwizzleNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_viewport_swizzle)) || (defined(VK_EXT_shader_object) && defined(VK_NV_viewport_swizzle)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color))
PFN_vkCmdSetCoverageToColorEnableNV vkCmdSetCoverageToColorEnableNV;
PFN_vkCmdSetCoverageToColorLocationNV vkCmdSetCoverageToColorLocationNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_fragment_coverage_to_color)) || (defined(VK_EXT_shader_object) && defined(VK_NV_fragment_coverage_to_color)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples))
PFN_vkCmdSetCoverageModulationModeNV vkCmdSetCoverageModulationModeNV;
PFN_vkCmdSetCoverageModulationTableEnableNV vkCmdSetCoverageModulationTableEnableNV;
PFN_vkCmdSetCoverageModulationTableNV vkCmdSetCoverageModulationTableNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_framebuffer_mixed_samples)) || (defined(VK_EXT_shader_object) && defined(VK_NV_framebuffer_mixed_samples)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image))
PFN_vkCmdSetShadingRateImageEnableNV vkCmdSetShadingRateImageEnableNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_shading_rate_image)) || (defined(VK_EXT_shader_object) && defined(VK_NV_shading_rate_image)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test))
PFN_vkCmdSetRepresentativeFragmentTestEnableNV vkCmdSetRepresentativeFragmentTestEnableNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_representative_fragment_test)) || (defined(VK_EXT_shader_object) && defined(VK_NV_representative_fragment_test)) */
#if (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode))
PFN_vkCmdSetCoverageReductionModeNV vkCmdSetCoverageReductionModeNV;
#endif /* (defined(VK_EXT_extended_dynamic_state3) && defined(VK_NV_coverage_reduction_mode)) || (defined(VK_EXT_shader_object) && defined(VK_NV_coverage_reduction_mode)) */
#if (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control))
PFN_vkGetImageSubresourceLayout2EXT vkGetImageSubresourceLayout2EXT;
#endif /* (defined(VK_EXT_host_image_copy)) || (defined(VK_EXT_image_compression_control)) */
#if (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state))
PFN_vkCmdSetVertexInputEXT vkCmdSetVertexInputEXT;
#endif /* (defined(VK_EXT_shader_object)) || (defined(VK_EXT_vertex_input_dynamic_state)) */
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template)))
PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
#endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && (defined(VK_VERSION_1_1) || defined(VK_KHR_descriptor_update_template))) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
#endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
/* VOLK_GENERATE_PROTOTYPES_C */

#endif /* VOLK_IN_LOADERS_CLOTH */

#ifdef __GNUC__
#	pragma GCC visibility pop
#endif

#ifdef __cplusplus
} // extern "C" / namespace volk
#endif
/* clang-format on */
