
#include "OgreHeadlessTextureManager.h"
#include "OgreLogManager.h"

namespace Ogre
{
    HeadlessTextureManager::HeadlessTextureManager() :
        TextureManager()
    {
        LogManager::getSingleton().logMessage("HeadlessTextureManager ctor", Ogre::LML_TRIVIAL);

        ResourceGroupManager::getSingleton()._registerResourceManager(mResourceType, this);
    }

    Resource *HeadlessTextureManager::createImpl( const String& name, ResourceHandle handle, const String& group, bool isManual, ManualResourceLoader* loader, const NameValuePairList* createParams )
    {
        OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, 
            String("HeadlessTextureManager cannot create resources. HeadlessRenderSystem is intended for headless operation which does not require textures."),
            "HeadlessTextureManager::createImpl");
        return 0;
    }
}
