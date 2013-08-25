
#pragma once

#include "OgreHeadlessFwd.h"
#include "OgreRenderSystem.h"

namespace Ogre
{
    class HeadlessRenderSystem : public RenderSystem
    {

    public:
        HeadlessRenderSystem();
        ~HeadlessRenderSystem();

        const String& getName(void) const;
        
        RenderWindow* _initialise(bool autoCreateWindow, const String& windowTitle = "OGRE Render Window");
        void reinitialise(void);
        void shutdown(void);
        
        /// Ogre::RenderSystem high level overrides

        ConfigOptionMap& getConfigOptions(void);
        void setConfigOption(const String &name, const String &value) {}

        String validateConfigOptions(void) { return ""; }

		RenderSystemCapabilities* createRenderSystemCapabilities() const { return 0; }
		void initialiseFromRenderSystemCapabilities(RenderSystemCapabilities* caps, RenderTarget* primary) {}
        
        void setAmbientLight(float r, float g, float b) {}
        void setShadingType(ShadeOptions so) {}
        void setLightingEnabled(bool enabled) {}

		RenderWindow* _createRenderWindow(const String &name, unsigned int width, unsigned int height, 
			                              bool fullScreen, const NameValuePairList *miscParams = 0);
		bool _createRenderWindows(const RenderWindowDescriptionList& renderWindowDescriptions, 
			                      RenderWindowList& createdWindows);
        void destroyRenderWindow(RenderWindow* pWin) {}

		DepthBuffer* _createDepthBufferFor(RenderTarget *renderTarget) { return 0; }
		virtual MultiRenderTarget* createMultiRenderTarget(const String & name) { return 0; }

        String getErrorDescription(long errorNumber) const { return ""; }
        VertexElementType getColourVertexElementType(void) const { return Ogre::VET_FLOAT1; }
        void setNormaliseNormals(bool normalise) {}
        
        /// Ogre::RenderSystem low level overrides
        
        void _useLights(const LightList& lights, unsigned short limit) {}
		bool areFixedFunctionLightsInViewSpace() const { return true; }
        void _setWorldMatrix(const Matrix4 &m) {}
        void _setViewMatrix(const Matrix4 &m) {}
        void _setProjectionMatrix(const Matrix4 &m) {}

        void _setSurfaceParams(const ColourValue &ambient, const ColourValue &diffuse, const ColourValue &specular,
                               const ColourValue &emissive, Real shininess, TrackVertexColourType tracking) {}

		void _setPointParameters(Real size, bool attenuationEnabled, Real constant, Real linear, Real quadratic, Real minSize, Real maxSize) {}
		void _setPointSpritesEnabled(bool enabled) {}
		
        void _setTexture(size_t unit, bool enabled, const TexturePtr &tex) {}
        void _setTextureCoordSet(size_t stage, size_t index) {}
        void _setTextureCoordCalculation(size_t stage, TexCoordCalcMethod m, const Frustum* frustum = 0) {}
        void _setTextureBlendMode(size_t stage, const LayerBlendModeEx& bm) {}
        void _setTextureAddressingMode(size_t stage, const TextureUnitState::UVWAddressingMode& uvw) {}
        void _setTextureBorderColour(size_t stage, const ColourValue& colour) {}
		void _setTextureMipmapBias(size_t unit, float bias) {}
        void _setTextureMatrix(size_t stage, const Matrix4& xform) {}

        void _setSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor, SceneBlendOperation op) {}
		void _setSeparateSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor, 
		                               SceneBlendFactor sourceFactorAlpha, SceneBlendFactor destFactorAlpha, 
		                               SceneBlendOperation op, SceneBlendOperation alphaOp) {}
		void _setSceneBlendingOperation(SceneBlendOperation op) {}
		void _setSeparateSceneBlendingOperation(SceneBlendOperation op, SceneBlendOperation alphaOp) {}
        void _setAlphaRejectSettings(CompareFunction func, unsigned char value, bool alphaToCoverage) {}

        void _setViewport(Viewport *vp) {}

        void _beginFrame(void) {}
        void _render(const RenderOperation& op) {}
        void _endFrame(void) {}

        void _setCullingMode(CullingMode mode) {}
        void _setDepthBufferParams(bool depthTest = true, bool depthWrite = true, CompareFunction depthFunction = CMPF_LESS_EQUAL) {}
        void _setDepthBufferCheckEnabled(bool enabled = true) {}
        void _setDepthBufferWriteEnabled(bool enabled = true) {}
        void _setDepthBufferFunction(CompareFunction func = CMPF_LESS_EQUAL) {}
        void _setDepthBias(float constantBias, float slopeScaleBias) {}
        void _setColourBufferWriteEnabled(bool red, bool green, bool blue, bool alpha) {}
        void _setFog(FogMode mode, const ColourValue& colour, Real density, Real start, Real end) {}

        void _convertProjectionMatrix(const Matrix4& matrix, Matrix4& dest, bool forGpuProgram = false) {}
        void _makeProjectionMatrix(const Radian& fovy, Real aspect, Real nearPlane, Real farPlane, 
                                   Matrix4& dest, bool forGpuProgram = false) {}
        void _makeProjectionMatrix(Real left, Real right, Real bottom, Real top, 
                                   Real nearPlane, Real farPlane, Matrix4& dest, bool forGpuProgram = false) {}
		void _makeOrthoMatrix(const Radian& fovy, Real aspect, Real nearPlane, Real farPlane, 
                              Matrix4& dest, bool forGpuProgram = false) {}

        void _applyObliqueDepthProjection(Matrix4& matrix, const Plane& plane, bool forGpuProgram) {}

        void setClipPlane(ushort index, Real A, Real B, Real C, Real D) {}
        void setClipPlanesImpl(const PlaneList& clipPlanes) {}
        void enableClipPlane (ushort index, bool enable) {}

        void _setPolygonMode(PolygonMode level) {}

        void setStencilCheckEnabled(bool enabled) {}
        void setStencilBufferParams(CompareFunction func = CMPF_ALWAYS_PASS, 
                                    uint32 refValue = 0, uint32 compareMask = 0xFFFFFFFF, uint32 writeMask = 0xFFFFFFFF,
			                        StencilOperation stencilFailOp = SOP_KEEP, 
                                    StencilOperation depthFailOp = SOP_KEEP,
                                    StencilOperation passOp = SOP_KEEP, 
                                    bool twoSidedOperation = false) {}

        void _setTextureUnitFiltering(size_t unit, FilterType ftype, FilterOptions filter) {}
		void _setTextureUnitCompareFunction(size_t unit, CompareFunction function) {}
		void _setTextureUnitCompareEnabled(size_t unit, bool compare) {}
		void _setTextureLayerAnisotropy(size_t unit, unsigned int maxAnisotropy) {}
		void setVertexDeclaration(VertexDeclaration* decl) {}
		void setVertexBufferBinding(VertexBufferBinding* binding) {}

        void bindGpuProgram(GpuProgram* prg) {}
        void unbindGpuProgram(GpuProgramType gptype) {}
		void bindGpuProgramParameters(GpuProgramType gptype, GpuProgramParametersSharedPtr params, uint16 variabilityMask) {}
		void bindGpuProgramPassIterationParameters(GpuProgramType gptype) {}

        void setScissorTest(bool enabled, size_t left = 0, size_t top = 0, size_t right = 800, size_t bottom = 600) {}
        void clearFrameBuffer(unsigned int buffers, const ColourValue& colour = ColourValue::Black, Real depth = 1.0f, unsigned short stencil = 0) {}
        HardwareOcclusionQuery* createHardwareOcclusionQuery(void) { return 0; }
        Real getHorizontalTexelOffset(void) { return 0.0f; }
        Real getVerticalTexelOffset(void) { return 0.0f; }
        Real getMinimumDepthInputValue(void) { return 0.0f; }
        Real getMaximumDepthInputValue(void) { return 0.0f; }

        void registerThread() {}
        void unregisterThread() {}
        void preExtraThreadsStarted() {}
        void postExtraThreadsStarted() {}

        void _setRenderTarget(RenderTarget *target) {}

        unsigned int getDisplayMonitorCount() const { return 1; }

        void beginProfileEvent(const String &eventName) {}
        void endProfileEvent(void) {}
        void markProfileEvent(const String &event) {}
        bool hasAnisotropicMipMapFilter() const { return false; }

        void getCustomAttribute(const String& name, void* pData) {}
        
    private:
        ConfigOptionMap mHeadlessOptions;
        
        HeadlessTextureManager *mTextureManager;
        DefaultHardwareBufferManager *mHardwareBufferManager;
    };
}
