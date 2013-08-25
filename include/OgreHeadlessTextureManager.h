
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
