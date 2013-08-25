
#include "OgreHeadlessApi.h"
#include "OgreHeadlessPlugin.h"
#include "OgreHeadlessRenderSystem.h"
#include "OgreRoot.h"

namespace Ogre
{
    const String sPluginName = "Headless RenderSystem";

    HeadlessPlugin::HeadlessPlugin() : 
        mRenderSystem(0)
    {
    }

    const String& HeadlessPlugin::getName() const
    {
        return sPluginName;
    }

    void HeadlessPlugin::install()
    {
        LogManager::getSingleton().logMessage("HeadlessPlugin::install", Ogre::LML_TRIVIAL);
        
        mRenderSystem = new HeadlessRenderSystem();
        Root::getSingleton().addRenderSystem(mRenderSystem);
    }

    void HeadlessPlugin::uninstall()
    {
        if (mRenderSystem)
            delete mRenderSystem;
        mRenderSystem = 0;
    }

    void HeadlessPlugin::initialise()
    {
    }

    void HeadlessPlugin::shutdown()
    {
    }
}

#ifndef OGRE_STATIC_LIB

namespace Ogre
{
    static HeadlessPlugin *plugin;

    extern "C" void _OgreHeadlessExport dllStartPlugin(void) throw()
    {
        plugin = new HeadlessPlugin();
        Root::getSingleton().installPlugin(plugin);
    }

    extern "C" void _OgreHeadlessExport dllStopPlugin(void)
    {
        Root::getSingleton().uninstallPlugin(plugin);
        delete plugin;
    }
}

#endif
