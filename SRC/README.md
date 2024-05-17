# Vector Rasterizer
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,cpp,c,visualstudio,svg" />
  </a>
</p>

## Development Set Up

In Visual Studio


### Dependencies Install

```powershell
cd .\vcpkg
.\vcpkg.exe integrate project
.\vcpkg.exe install tinyxml2
.\vcpkg.exe integrate install
```

### Include Directories
```
Properties -> Configuration Properties -> C/C++ -> General -> Additional Include Directories
```

Set Value:
```
$(ProjectDir)/Figures/include;$(ProjectDir)/GUI/include;$(ProjectDir)/Panels/include;$(ProjectDir)/Utils/include;
```
