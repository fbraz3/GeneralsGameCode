# AI Coding Agent Instructions

## Project Overview

**GeneralsGameCode** - Cross-platform port of Command & Conquer: Generals/Zero Hour. Modernized from VC6/C++98 to modern C++20 with comprehensive macOS/Linux compatibility.

**🎯 Current Status**: Phase 19 - Runtime Debugging and Stabilization. **FIRST EXECUTABLE ACHIEVED** with segmentation fault resolved!

## Architecture & Critical Patterns

### Directory Structure
- **Core/**: Shared engine (50MB+ compiled libraries)
  - `win32_compat.h` (2,262+ lines) - **Primary compatibility layer**
  - `Libraries/Source/WWVegas/WW3D2/` - 3D graphics engine  
  - `Libraries/Source/debug/` - Cross-platform debug system
- **GeneralsMD/**: Zero Hour expansion - **PRIMARY TARGET** 
- **Generals/**: Original game - secondary target  

### Build System Commands
```bash
# Primary workflow - ALWAYS use vc6 preset for retail compatibility
cmake --preset vc6
cmake --build build/vc6 --target z_generals -j 4  # Main target (STABLE)
cmake --build build/vc6 --target g_generals -j 4  # Secondary (STABLE)

# Test core libraries independently
cmake --build build/vc6 --target ww3d2 wwlib wwmath
```

### Running & Debugging with Game Assets
**CRITICAL**: Game requires original Command & Conquer assets to run properly
```bash
# Setup assets directory (one-time setup)
mkdir -p $HOME/Downloads/generals
cp ./build/vc6/GeneralsMD/generalszh $HOME/Downloads/generals/

# Copy game assets (Data/, Maps/, etc.) to $HOME/Downloads/generals/
# Assets from original game installation required for proper initialization

# Debug with lldb (recommended for crash investigation)
cd $HOME/Downloads/generals && lldb -s /path/to/debug_script.lldb generalszh

# Direct execution (shows printf debug output)
cd $HOME/Downloads/generals && ./generalszh
```

**Debug Workflow**: Always test in asset-rich environment for accurate runtime behavior

### Cross-Platform Compatibility Strategy
**Essential Pattern**: `#ifdef _WIN32` conditional compilation throughout
- Windows APIs isolated in `win32_compat.h` 
- POSIX alternatives for macOS/Linux
- 200+ Windows functions replaced (HeapAlloc→malloc, wsprintf→snprintf, etc.)
- **Never break Windows compatibility** - all original code paths preserved

## Critical Development Issues (RESOLVED)

### ✅ Memory Corruption Protection (Phase 19 Resolution)
**Root Cause**: AsciiString initialization with corrupted pointers (0x7)
```cpp
// IMPLEMENTED - Corrupted pointer detection in AsciiString::validate()
if (m_data && ((uintptr_t)m_data < 0x1000)) {
    // Reset corrupted pointer to null
    AsciiString* self = const_cast<AsciiString*>(this);
    self->m_data = nullptr;
}
```
**Pattern**: Proactive validation prevents crashes from memory corruption

### ✅ Cross-Platform LocalFileSystem (Phase 19 Resolution)
**Pattern**: Conditional platform-specific subsystem selection
```cpp
// In Win32GameEngine.h
#ifdef _WIN32
    m_localFileSystem = new Win32LocalFileSystem;
#else
    m_localFileSystem = new StdLocalFileSystem;
#endif
```

### DirectX Interface Harmonization (Ongoing)
**Pattern**: Consistent `IDirect3DTexture8*` usage across Core/Generals/GeneralsMD
- Files: `dx8wrapper.cpp`, `texture.h`, `d3d8.h` in both Generals and GeneralsMD
- **Issue**: `CORE_IDirect3DTexture8` vs `IDirect3DTexture8` naming conflicts
- **Solution**: Unified typedef pattern in compatibility headers

## Development Workflows

### Error Resolution Priority
1. **Runtime Stability** - Test executable functionality with assets
2. **Root Cause Investigation** - Investigate why AsciiString gets corrupted pointers
3. **Memory Protection** - Extend protective validation to other core classes  
4. **Graphics Pipeline** - Verify W3D rendering works correctly

### Testing Strategy
- **Asset-Dependent Testing**: Always test with original game assets in `$HOME/Downloads/generals`
- **Memory Safety**: Current protective fixes ensure stability during investigation
- **Cross-Platform**: Test macOS builds regularly (`#ifdef _WIN32` guards)
- **Retail Compatibility**: Always test with `RTS_BUILD_OPTION_DEBUG=OFF`

### Memory Management Patterns
**Critical**: Game uses custom memory pools extensively
```cpp
MEMORY_POOL_GLUE_WITH_USERLOOKUP_CREATE(ClassName, "PoolName")
// Generates operator new/delete with pool allocation
// Used in 100+ classes across DataChunk.h, Player.h, modules, etc.
```
**Never modify** pool macros - they maintain exact retail memory layout

## Key Integration Points

### Graphics Pipeline
- **W3D Engine**: 25MB compiled graphics libraries (libww3d2.a)
- **DirectX8→OpenGL**: Compatibility via `dx8wrapper.cpp` abstraction
- **Texture Management**: `TextureBaseClass` hierarchy with DirectX interfaces

### Platform-Specific Files
- **Windows**: Native DirectX, all original functionality preserved
- **macOS**: OpenGL rendering, POSIX APIs via win32_compat.h  
- **Cross-Platform**: Conditional compilation, no platform-specific branches

### Runtime Debugging Infrastructure
- **LLDB Integration**: `scripts/debug_script.lldb` for systematic crash investigation
- **Asset Environment**: Required `$HOME/Downloads/generals` with original game data
- **Memory Validation**: Protective checks for corrupted pointers across string classes
- **Example debug command**:
```bash
# Note: replace $REPO_PATH with actual path to repository
cd $HOME/Downloads/generals && lldb -s $REPO_PATH/scripts/debug_script.lldb generalszh
```

## Essential Files for AI Context
- `MACOS_PORT.md` - Detailed progress tracking and error analysis
- `NEXT_STEPS.md` - Current phase status and remaining work  
- `Core/Libraries/Source/WWVegas/WW3D2/win32_compat.h` - All platform abstractions
- `Core/GameEngine/Source/Common/System/AsciiString.cpp` - Memory corruption fixes
- `CMakePresets.json` - Build configurations (use "vc6" preset)

**Current Focus**: Root cause investigation of memory corruption while maintaining runtime stability through protective validation

**Compilation tip**: Use `-j 4` (half available cores) to avoid system overload during builds