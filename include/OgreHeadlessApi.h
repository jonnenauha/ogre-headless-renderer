
#pragma once

#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32) && !defined(__MINGW32__) && !defined(OGRE_STATIC_LIB)
#	ifdef RenderSystem_Headless_EXPORTS
#		define _OgreHeadlessExport __declspec(dllexport)
#	else
#       if defined(__MINGW32__)
#           define _OgreHeadlessExport
#       else
#    		define _OgreHeadlessExport __declspec(dllimport)
#       endif
#	endif
#elif defined (OGRE_GCC_VISIBILITY)
#    define _OgreHeadlessExport  __attribute__ ((visibility("default")))
#else
#    define _OgreHeadlessExport
#endif
