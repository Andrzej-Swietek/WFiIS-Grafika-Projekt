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
```


In Visual Studio Set:
```
Tools -> NuGet Package Manager -> Package Manager Console 
```

Paste Follwoing:

```
Install-Package "vcpkg.C.Users.[YOUR YOUERNAME].vcpkg" -Source "C:\Users\[YOUR YOUERNAME]\vcpkg"
```

```powershell
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
