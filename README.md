Headless Ogre Render System
===========================

This is a headless [Ogre3D] rendering system implementation.

Use Case
--------

This plugin is useful only in a very spesific use case, when you don't have
the need to initialize `Ogre::Root` or to create a rendering window.

In particular it can be used on a headless server that uses Ogre for it's
`Ogre::SceneManager` and the scene nodes provided by it. Optionally you can
also load meshes with `Ogre::MeshManager`.

How to use
----------

You can access the `Ogre::HardwareBufferManager` singleton and load Meshes via
`Ogre::MeshManager` normally to Ogre. This default hardware buffer manager is
created and destroyed by this plugins. Loading meshes can be useful for example
on a headless server for physics.

You can access the `Ogre::TextureManager` singleton but cannot use it for anything sensible.
This singleton of `Ogre::HeadlessTextureManager` is created and destroyed by this plugin.

The following operations are not allowed when using this plugins. Some of these will throw
an `Ogre::Exception` with a message explaining the situation.

* Don't invoke `Ogre::Root::initialize()` or create a rendering window. Throws exception.
* Don't invoke `Ogre::Root::setRenderSystem()` with this plugins ptr.
* Don't load textures to Ogre, this will end up in `Ogre::HeadlessTextureManager::createImpl()`. Throws exception.
* Don't try to render with `Ogre::Root::renderOneFrame`, `Ogre::Root::startRendering` etc. This will crash your application.
* Don't try to use `Ogre::GpuProgramManager`, it will be null. However `Ogre::HighLevelGpuProgramManager` is initialized in `Ogre::Root` constructor.

Building
--------

The `CMakeLists.txt` conforms to Ogre >=1.7 CMake macros and is ready to
be included into your Ogre build.

```
cd ogre-src/RenderSystems
git clone https://github.com/jonnenauha/ogre-headless-renderer.git Headless
```

Open `ogre-src/RenderSystems/CMakeLists.txt`and add `add_subdirectory (Headless)`
to the bottom the the file. Now run Ogre CMake again and build.

License
-------

This plugin is licensed under [Apache 2.0], see the `LICENSE` for full details.


[Ogre3D]: http://www.ogre3d.org/ "Ogre3D"
[Apache 2.0]: http://www.apache.org/licenses/LICENSE-2.0.txt "Apache 2.0 license"
