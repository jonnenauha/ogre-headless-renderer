
#pragma once

#include "OgreHeadlessFwd.h"
#include "OgreTextureManager.h"

namespace Ogre
{
    class HeadlessTextureManager : public TextureManager
    {

    public:
        HeadlessTextureManager();
        
        PixelFormat getNativeFormat(TextureType type, PixelFormat format, int usage) { return Ogre::PF_UNKNOWN; }

        bool isHardwareFilteringSupported(TextureType ttype, PixelFormat format, int usage,
                                          bool preciseFormatOnly = false) { return false; }
    protected:
        Resource *createImpl(const String& name, ResourceHandle handle, const String& group, 
                             bool isManual, ManualResourceLoader* loader, 
                             const NameValuePairList* createParams);
                             
        
    };
}
