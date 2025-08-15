# Automatic Credits System

This document explains how the automatic credits system implemented in the game build process works.

## How It Works

### 1. Automatic Credits Generation

During the weekly-release process, the system automatically:

- Executes the `scripts/generate-credits.py` script
- Collects all unique contributors from the Git repository using `git log`
- Removes duplicates and automation/bot names
- Generates a `Credits.ini` file in the correct format for the game

### 2. Build Integration

The `Credits.ini` file is automatically:

- Generated during the build process
- Copied to `build/{preset}/{game}/Data/INI/Credits.ini`
- Included in build artifacts
- Packaged in final releases as `Data/INI/Credits.ini`

### 3. Credits.ini File Format

The generated file follows the format expected by the game:

```ini
[Credits]
ScrollRate = 2
ScrollRateEveryFrames = 2
ScrollDown = true
TitleColor = 255 255 255 255
MinorTitleColor = 200 200 255 255
NormalColor = 180 180 180 255

Style = TITLE
Text = "TheSuperHackers Team"

Blank =

Style = MINORTITLE
Text = "Developed by:"

Blank =

Style = NORMAL
Text = "Contributor Name"
```

### 4. Supported Style Types

- `TITLE`: Main title (largest, most prominent)
- `MINORTITLE`: Subtitles (medium)
- `NORMAL`: Normal text (contributor names)
- `COLUMN`: Column text
- `Blank`: Blank line

### 5. How to View Credits

In the game, credits will be displayed on the credits screen with:
- Automatic scrolling from bottom to top
- "TheSuperHackers Team" as main title
- List of all repository contributors
- Automatic formatting with different font styles

### 6. Customization

To modify the credits format, edit the `scripts/generate-credits.py` script:

- Change colors: modify `TitleColor`, `MinorTitleColor`, `NormalColor` variables
- Modify scroll speed: adjust `ScrollRate` and `ScrollRateEveryFrames`
- Add custom sections: modify the `generate_credits_ini()` function
- Filter contributors: adjust the logic in `get_git_contributors()`

### 7. Manual Execution

To generate the Credits.ini file manually:

```bash
cd /path/to/GeneralsGameCode
python3 scripts/generate-credits.py
```

This will create a `Credits.ini` file in the current directory.

### 8. CI/CD Integration

The system is fully integrated with GitHub Actions workflows:

- **build-toolchain.yml**: Generates Credits.ini during build
- **weekly-release.yml**: Includes the file in release packages

### 9. Current Contributors

The system found and will automatically include all unique repository contributors, including:
- Felipe Keller Braz, xezon, Mauller, Felipe Braz, fbraz3, Caball009
- And all other 33+ project contributors

### 10. Release Structure

Releases now include:
```
generals-fbraz3-{version}.zip
├── GeneralsV.exe
├── W3DViewV.exe
├── WorldBuilderV.exe
└── Data/
    └── INI/
        └── Credits.ini

generalszh-fbraz3-{version}.zip
├── GeneralsZHv.exe
├── W3DViewZHv.exe
├── WorldBuilderZHv.exe
└── Data/
    └── INI/
        └── Credits.ini
```

## File Locations

- **Generator script**: `scripts/generate-credits.py`
- **Generated file**: `Credits.ini` (project root during build)
- **Game location**: `Data\INI\Credits.ini`
- **Modified workflows**:
  - `.github/workflows/build-toolchain.yml`
  - `.github/workflows/weekly-release.yml`
