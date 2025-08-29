#pragma once

#ifndef _WIN32

// DirectX 8 compatibility header for non-Windows systems
#include "win32_compat.h"
#include <cstdint>

// Windows API types needed by DirectX
typedef struct {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

typedef struct {
    LONG x;
    LONG y;
} POINT;

// Basic DirectX types
typedef void* LPDIRECT3D8;
typedef void* LPDIRECT3DDEVICE8;
typedef void* LPDIRECT3DTEXTURE8;
typedef void* LPDIRECT3DSURFACE8;
typedef void* LPDIRECT3DVERTEXBUFFER8;
typedef void* LPDIRECT3DINDEXBUFFER8;
typedef void* LPDIRECT3DSWAPCHAIN8;
typedef void* IDirect3DSwapChain8;

// DirectX color type
typedef uint32_t D3DCOLOR;

// Constants
#define D3D_OK 0x00000000L
#define CONST const

// DirectX enums and constants
typedef enum {
    D3DFMT_UNKNOWN = 0,
    D3DFMT_R3G3B2 = 27,
    D3DFMT_A8R8G8B8 = 21,
    D3DFMT_X8R8G8B8 = 22,
    D3DFMT_R5G6B5 = 23,
    D3DFMT_X1R5G5B5 = 24,
    D3DFMT_A1R5G5B5 = 25,
    D3DFMT_A4R4G4B4 = 26,
    D3DFMT_DXT1 = 827611204,
    D3DFMT_DXT3 = 827611220,
    D3DFMT_DXT5 = 894720068
} D3DFORMAT;

typedef enum {
    D3DPOOL_DEFAULT = 0,
    D3DPOOL_MANAGED = 1,
    D3DPOOL_SYSTEMMEM = 2,
    D3DPOOL_SCRATCH = 3
} D3DPOOL;

typedef enum {
    D3DUSAGE_RENDERTARGET = 0x00000001L,
    D3DUSAGE_DEPTHSTENCIL = 0x00000002L,
    D3DUSAGE_DYNAMIC = 0x00000200L,
    D3DUSAGE_WRITEONLY = 0x00000008L
} D3DUSAGE;

// DirectX FVF constants
#define D3DFVF_RESERVED0        0x001
#define D3DFVF_POSITION_MASK    0x00E
#define D3DFVF_XYZ              0x002
#define D3DFVF_XYZRHW           0x004
#define D3DFVF_XYZB1            0x006
#define D3DFVF_XYZB2            0x008
#define D3DFVF_XYZB3            0x00A
#define D3DFVF_XYZB4            0x00C
#define D3DFVF_XYZB5            0x00E
#define D3DFVF_NORMAL           0x010
#define D3DFVF_PSIZE            0x020
#define D3DFVF_DIFFUSE          0x040
#define D3DFVF_SPECULAR         0x080
#define D3DFVF_TEXCOUNT_MASK    0xF00
#define D3DFVF_TEXCOUNT_SHIFT   8
#define D3DFVF_TEX0             0x000
#define D3DFVF_TEX1             0x100
#define D3DFVF_TEX2             0x200
#define D3DFVF_TEX3             0x300
#define D3DFVF_TEX4             0x400
#define D3DFVF_TEX5             0x500
#define D3DFVF_TEX6             0x600
#define D3DFVF_TEX7             0x700
#define D3DFVF_TEX8             0x800

// Additional FVF texture coordinate size macros
#define D3DFVF_TEXTUREFORMAT1 0
#define D3DFVF_TEXTUREFORMAT2 1
#define D3DFVF_TEXTUREFORMAT3 2
#define D3DFVF_TEXTUREFORMAT4 3
#define D3DFVF_TEXCOORDSIZE1(CoordIndex) (D3DFVF_TEXTUREFORMAT1 << (CoordIndex*2 + 16))
#define D3DFVF_TEXCOORDSIZE2(CoordIndex) (D3DFVF_TEXTUREFORMAT2 << (CoordIndex*2 + 16))
#define D3DFVF_TEXCOORDSIZE3(CoordIndex) (D3DFVF_TEXTUREFORMAT3 << (CoordIndex*2 + 16))
#define D3DFVF_TEXCOORDSIZE4(CoordIndex) (D3DFVF_TEXTUREFORMAT4 << (CoordIndex*2 + 16))

// DirectX constants
#define D3DDP_MAXTEXCOORD 8

// Transform state types
typedef enum {
    D3DTS_WORLD = 256,
    D3DTS_VIEW = 2,
    D3DTS_PROJECTION = 3,
    D3DTS_TEXTURE0 = 16,
    D3DTS_TEXTURE1 = 17,
    D3DTS_TEXTURE2 = 18,
    D3DTS_TEXTURE3 = 19,
    D3DTS_TEXTURE4 = 20,
    D3DTS_TEXTURE5 = 21,
    D3DTS_TEXTURE6 = 22,
    D3DTS_TEXTURE7 = 23
} D3DTRANSFORMSTATETYPE;

// Render state types
typedef enum {
    D3DRS_ZENABLE = 7,
    D3DRS_FILLMODE = 8,
    D3DRS_SHADEMODE = 9,
    D3DRS_ZWRITEENABLE = 14,
    D3DRS_ALPHATESTENABLE = 15,
    D3DRS_LASTPIXEL = 16,
    D3DRS_SRCBLEND = 19,
    D3DRS_DESTBLEND = 20,
    D3DRS_CULLMODE = 22,
    D3DRS_ZFUNC = 23,
    D3DRS_ALPHAREF = 24,
    D3DRS_ALPHAFUNC = 25,
    D3DRS_DITHERENABLE = 26,
    D3DRS_ALPHABLENDENABLE = 27,
    D3DRS_FOGENABLE = 28,
    D3DRS_SPECULARENABLE = 29,
    D3DRS_FOGCOLOR = 34,
    D3DRS_FOGTABLEMODE = 35,
    D3DRS_FOGSTART = 36,
    D3DRS_FOGEND = 37,
    D3DRS_FOGDENSITY = 38,
    D3DRS_RANGEFOGENABLE = 48,
    D3DRS_STENCILENABLE = 52,
    D3DRS_STENCILFAIL = 53,
    D3DRS_STENCILZFAIL = 54,
    D3DRS_STENCILPASS = 55,
    D3DRS_STENCILFUNC = 56,
    D3DRS_STENCILREF = 57,
    D3DRS_STENCILMASK = 58,
    D3DRS_STENCILWRITEMASK = 59,
    D3DRS_TEXTUREFACTOR = 60,
    D3DRS_WRAP0 = 128,
    D3DRS_LIGHTING = 137,
    D3DRS_AMBIENT = 139,
    D3DRS_FOGVERTEXMODE = 140,
    D3DRS_COLORVERTEX = 141,
    D3DRS_LOCALVIEWER = 142,
    D3DRS_NORMALIZENORMALS = 143,
    D3DRS_DIFFUSEMATERIALSOURCE = 145,
    D3DRS_SPECULARMATERIALSOURCE = 146,
    D3DRS_AMBIENTMATERIALSOURCE = 147,
    D3DRS_EMISSIVEMATERIALSOURCE = 148,
    D3DRS_VERTEXBLEND = 151,
    D3DRS_CLIPPLANEENABLE = 152
} D3DRENDERSTATETYPE;

// Texture stage state types
typedef enum {
    D3DTSS_COLOROP = 1,
    D3DTSS_COLORARG1 = 2,
    D3DTSS_COLORARG2 = 3,
    D3DTSS_ALPHAOP = 4,
    D3DTSS_ALPHAARG1 = 5,
    D3DTSS_ALPHAARG2 = 6,
    D3DTSS_BUMPENVMAT00 = 7,
    D3DTSS_BUMPENVMAT01 = 8,
    D3DTSS_BUMPENVMAT10 = 9,
    D3DTSS_BUMPENVMAT11 = 10,
    D3DTSS_TEXCOORDINDEX = 11,
    D3DTSS_BUMPENVLSCALE = 22,
    D3DTSS_BUMPENVLOFFSET = 23,
    D3DTSS_TEXTURETRANSFORMFLAGS = 24,
    D3DTSS_COLORARG0 = 26,
    D3DTSS_ALPHAARG0 = 27,
    D3DTSS_RESULTARG = 28,
    D3DTSS_CONSTANT = 32
} D3DTEXTURESTAGESTATETYPE;

// DirectX structures
typedef struct {
    float x, y, z, rhw;
    DWORD color;
    float tu, tv;
} D3DTLVERTEX;

typedef struct {
    DWORD Width;
    DWORD Height;
    DWORD Levels;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
} D3DSURFACE_DESC;

typedef struct {
    void* pBits;
    int Pitch;
} D3DLOCKED_RECT;

// Matrix structure from d3dx8math.h
typedef struct {
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
} D3DMATRIX;

// DirectX light structure
typedef struct {
    DWORD Type;
    float Diffuse[4];
    float Specular[4];
    float Ambient[4];
    float Position[3];
    float Direction[3];
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
} D3DLIGHT8;

// DirectX viewport structure
typedef struct {
    DWORD X;
    DWORD Y;
    DWORD Width;
    DWORD Height;
    float MinZ;
    float MaxZ;
} D3DVIEWPORT8;

// DirectX material structure
typedef struct {
    float Diffuse[4];
    float Ambient[4];
    float Specular[4];
    float Emissive[4];
    float Power;
} D3DMATERIAL8;

// DirectX caps structure (simplified)
typedef struct {
    DWORD DeviceType;
    DWORD AdapterOrdinal;
    DWORD Caps;
    DWORD MaxTextureWidth;
    DWORD MaxTextureHeight;
    DWORD MaxSimultaneousTextures;
    DWORD VertexShaderVersion;
    DWORD PixelShaderVersion;
} D3DCAPS8;

// DirectX adapter identifier
typedef struct {
    char Driver[512];
    char Description[512];
    DWORD VendorId;
    DWORD DeviceId;
    DWORD SubSysId;
    DWORD Revision;
    DWORD WHQLLevel;
} D3DADAPTER_IDENTIFIER8;

// Forward declarations
struct IDirect3DBaseTexture8;
struct IDirect3DVertexBuffer8;
struct IDirect3DIndexBuffer8;
struct IDirect3DTexture8;

// DirectX interface types
struct IDirect3D8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
    virtual int QueryInterface(void*, void**) { return 0; }
};

struct IDirect3DDevice8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
    virtual int QueryInterface(void*, void**) { return 0; }
    
    // DirectX 8 Device methods - stub implementations
    virtual int LightEnable(DWORD index, BOOL enable) { return D3D_OK; }
    virtual int SetRenderState(D3DRENDERSTATETYPE state, DWORD value) { return D3D_OK; }
    virtual int SetTexture(DWORD stage, IDirect3DBaseTexture8* texture) { return D3D_OK; }
    virtual int SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value) { return D3D_OK; }
    virtual int SetTransform(D3DTRANSFORMSTATETYPE state, const D3DMATRIX* matrix) { return D3D_OK; }
    virtual int GetTransform(D3DTRANSFORMSTATETYPE state, D3DMATRIX* matrix) { return D3D_OK; }
    virtual int SetMaterial(const D3DMATERIAL8* material) { return D3D_OK; }
    virtual int GetMaterial(D3DMATERIAL8* material) { return D3D_OK; }
    virtual int SetLight(DWORD index, const D3DLIGHT8* light) { return D3D_OK; }
    virtual int GetLight(DWORD index, D3DLIGHT8* light) { return D3D_OK; }
    virtual int SetViewport(const D3DVIEWPORT8* viewport) { return D3D_OK; }
    virtual int GetViewport(D3DVIEWPORT8* viewport) { return D3D_OK; }
    virtual int Clear(DWORD count, const void* rects, DWORD flags, D3DCOLOR color, float z, DWORD stencil) { return D3D_OK; }
    virtual int BeginScene() { return D3D_OK; }
    virtual int EndScene() { return D3D_OK; }
    virtual int Present(const void* src_rect, const void* dest_rect, void* dest_window_override, const void* dirty_region) { return D3D_OK; }
    virtual int SetVertexShader(DWORD handle) { return D3D_OK; }
    virtual int GetVertexShader(DWORD* handle) { return D3D_OK; }
    virtual int SetPixelShader(DWORD handle) { return D3D_OK; }
    virtual int GetPixelShader(DWORD* handle) { return D3D_OK; }
    virtual int DrawPrimitive(DWORD primitive_type, DWORD start_vertex, DWORD primitive_count) { return D3D_OK; }
    virtual int DrawIndexedPrimitive(DWORD type, DWORD min_index, DWORD num_vertices, DWORD start_index, DWORD primitive_count) { return D3D_OK; }
    virtual int CreateVertexBuffer(DWORD length, DWORD usage, DWORD fvf, D3DPOOL pool, IDirect3DVertexBuffer8** vertex_buffer) { return D3D_OK; }
    virtual int CreateIndexBuffer(DWORD length, DWORD usage, D3DFORMAT format, D3DPOOL pool, IDirect3DIndexBuffer8** index_buffer) { return D3D_OK; }
    virtual int CreateTexture(DWORD width, DWORD height, DWORD levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, IDirect3DTexture8** texture) { return D3D_OK; }
    virtual int SetStreamSource(DWORD stream_number, IDirect3DVertexBuffer8* stream_data, DWORD stride) { return D3D_OK; }
    virtual int SetIndices(IDirect3DIndexBuffer8* index_data, DWORD base_vertex_index) { return D3D_OK; }
    
    // Additional methods for compatibility
    virtual int SetVertexShaderConstant(DWORD reg, const void* data, DWORD count) { return D3D_OK; }
    virtual int SetPixelShaderConstant(DWORD reg, const void* data, DWORD count) { return D3D_OK; }
    virtual int SetClipPlane(DWORD index, const float* plane) { return D3D_OK; }
    virtual int CopyRects(IDirect3DSurface8* source_surface, const RECT* source_rects, DWORD num_rects, IDirect3DSurface8* dest_surface, const POINT* dest_points) { return D3D_OK; }
};

struct IDirect3DBaseTexture8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
    virtual int QueryInterface(void*, void**) { return 0; }
};

struct IDirect3DTexture8 : public IDirect3DBaseTexture8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
};

struct IDirect3DSurface8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
    virtual int QueryInterface(void*, void**) { return 0; }
};

struct IDirect3DVertexBuffer8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
    virtual int QueryInterface(void*, void**) { return 0; }
};

struct IDirect3DIndexBuffer8 {
    virtual int AddRef() { return 1; }
    virtual int Release() { return 0; }
    virtual int QueryInterface(void*, void**) { return 0; }
};

// Stub functions
inline void* Direct3DCreate8(unsigned int) { return nullptr; }

#else
// On Windows, include the real DirectX headers
#include <d3d8.h>
#endif // !_WIN32
