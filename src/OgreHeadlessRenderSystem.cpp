
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

#include "OgreHeadlessRenderSystem.h"
#include "OgreHeadlessTextureManager.h"

#include "OgreDefaultHardwareBufferManager.h"

namespace Ogre
{
    HeadlessRenderSystem::HeadlessRenderSystem() :
        RenderSystem(),
        mTextureManager(0),
        mHardwareBufferManager(0)
    {
        LogManager::getSingleton().logMessage("HeadlessRenderSystem ctor", Ogre::LML_TRIVIAL);

        reinitialise();
    }
    
    HeadlessRenderSystem::~HeadlessRenderSystem()
    {
        LogManager::getSingleton().logMessage("HeadlessRenderSystem dtor", Ogre::LML_TRIVIAL);

        shutdown();
    }
   
    const String& HeadlessRenderSystem::getName(void) const
    {
        static String renderSystemName("Headless Rendering Subsystem");
        return renderSystemName;
    }

    RenderWindow* HeadlessRenderSystem::_initialise(bool autoCreateWindow, const String& windowTitle)
    {
        OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, 
            String("HeadlessRenderSystem cannot be initialized. This indicates Ogre::Root::initialize() was called and you are about to create a rendering window. ") +
            String("This rendering plugin is for headless operation only."),
            "HeadlessRenderSystem::_initialise");
        return 0;
    }

    void HeadlessRenderSystem::reinitialise()
    {
        LogManager::getSingleton().logMessage("HeadlessRenderSystem::reinitialise", Ogre::LML_TRIVIAL);

        shutdown();

        mTextureManager = OGRE_NEW HeadlessTextureManager();
        mHardwareBufferManager = OGRE_NEW DefaultHardwareBufferManager();
    }

    void HeadlessRenderSystem::shutdown(void)
    {
        if (!mTextureManager && !mHardwareBufferManager)
            return;

        LogManager::getSingleton().logMessage("HeadlessRenderSystem::shutdown", Ogre::LML_TRIVIAL);

        if (mTextureManager)
            OGRE_DELETE mTextureManager;
        mTextureManager = 0;
        if (mHardwareBufferManager)
            OGRE_DELETE mHardwareBufferManager;
        mHardwareBufferManager = 0;
    }

    ConfigOptionMap& HeadlessRenderSystem::getConfigOptions(void)
    {
        return mHeadlessOptions;
    }

    RenderWindow* HeadlessRenderSystem::_createRenderWindow(const String &name, unsigned int width, unsigned int height, bool fullScreen, const NameValuePairList *miscParams)
    {
        OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, 
            "HeadlessRenderSystem cannot create rendering windows. This rendering plugin is for headless operation only.",
            "HeadlessRenderSystem::_createRenderWindow");
        return 0;
    }

    bool HeadlessRenderSystem::_createRenderWindows(const RenderWindowDescriptionList& renderWindowDescriptions, RenderWindowList& createdWindows)
    {
        OGRE_EXCEPT(Exception::ERR_RENDERINGAPI_ERROR, 
            "HeadlessRenderSystem cannot create rendering windows. This rendering plugin is for headless operation only.",
            "HeadlessRenderSystem::_createRenderWindows");
        return false;
    }
}
