
#pragma once

#include "OgreHeadlessFwd.h"
#include "OgrePlugin.h"

namespace Ogre
{
    class HeadlessPlugin : public Plugin
    {

    public:
        HeadlessPlugin();

        const String& getName() const;
        
        void install();
        void uninstall();

        void initialise();
        void shutdown();
        
    private:
        HeadlessRenderSystem *mRenderSystem;
    };
}
