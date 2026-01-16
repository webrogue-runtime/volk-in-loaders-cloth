# VOLK in Loader's Cloth

This repo is a fork of [volk](https://github.com/zeux/volk).

## Purpose

VOLK in Loader's Cloth (or VILC for short) is made to act as [Vulkan Loader](https://github.com/KhronosGroup/Vulkan-Loader) by providing Vulkan functions without the need to call vkGetInstanceProcAddr and vkGetDeviceProcAddr.
In contrast to original VOLK, VILC acts as a drop-in replacement of Vulkan Loader, so you don't need to `#include "volk.h"` or call functions like `volkInitialize`.


This fork has been developed for [Webrogue](https://github.com/webrogue-runtime/webrogue), but should be replaced with Vulkan Loader as soon as it is ported to Webrogue.

## Limitations

Only one `VkInstance` and one `VkDevice` can exist.
Vulkan layers are unsupported and not likely to be supported in this fork.
While VILC adds some time overhead, it is probably lower than that from the Vulkan Loader.
