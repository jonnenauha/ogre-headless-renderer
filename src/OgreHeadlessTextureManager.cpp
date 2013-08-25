
/* Copyright 2013 Jonne Nauha / jonne@adminotech.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
