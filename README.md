# 3DViewer v1.0
Implementation of 3DViewer v1.0.



A wireframe model is a model of an object in 3D graphics, which is a set of vertices and edges that defines the shape of the displayed polyhedral object in three-dimensional space.


### .Obj file format for representing the definition of 3D objects

.Obj file is a geometry definition file format first developed by Wavefront Technologies. The file format is open and accepted by many 3D graphics application vendors.

The .obj file format is a simple data format that represents only three-dimensional geometry, specifically the position of each vertex, the UV of each texture coordinate vertex, vertex normals and the faces that define each polygon as a list of vertices and texture vertices. Obj coordinates have no units, but Obj files can contain scale information in a readable comment line.

The example of .obj file format:
```
  # List of geometric vertices, with (x, y, z [,w]) coordinates, w is optional and defaults to 1.0.
  v 0.123 0.234 0.345 1.0
  v ...
  ...
  # Texture coordinates (u, [,v ,w]), w is optional and default to 0.
  vt 0.500 -1.352 [0.234]
  vt ...
  ...
  # Normals (x,y,z)
  vn 0.707 0.000 0.707
  vn ...
  ...
  # Parameter space vertices (u [,v] [,w])
  vn 0.707 0.000 0.707
  vn ...
  ...
  # Polygonal face element
  f v1 v2 v3
  f ...
  ...
  # Group
  g Group1
  ...
  # Object
  o Object1
  ```



#### Translation

Translation matrix in uniform two-dimensional coordinates
```
1 0 a
0 1 b
0 0 1
```

where _a_ and _b_ are the values on _x_ and _y_ by which the source point should be moved. Thus, to move a point, you must multiply the translation matrix by it.
```
x1     1 0 a     x 
y1  =  0 1 b    y
1      0 0 1     1
```

where _x_ and _y_ are the original coordinates of the point and _x1_ and _y1_ are the resulting coordinates of the new point after translation.

#### Rotation

Clockwise rotation matrix in uniform two-dimensional coordinates
```
cos(a)  sin(a) 0
-sin(a) cos(a) 0
0       0      1
```

where _a_ is the rotation angle in two-dimensional space. To get the coordinates of the new point it is necessary to multiply the rotation matrix by the original point in the same way as the translation matrix
```
x1     cos(a)  sin(a) 0     x 
y1  =  -sin(a) cos(a) 0    y
1      0       0      1     1
```

#### Scaling

Scaling matrix in uniform two-dimensional coordinates
```
a 0 0
0 b 0
0 0 1
```

where _a_ and _b_ are the scaling factors for the OX and OY axes respectively. Obtaining coordinates of a new point is similar to the cases described above.


## 3DViewer

Program to visualise 3D wireframe models:

- The program must be developed in C language of C11 standard using gcc compiler. You can use any additional QT libraries and modules
- The program code must be located in the src folder
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests, gcov. Installation directory could be arbitrary, except the building one
- The program must be developed according to the principles of structured programming
- When writing code it is necessary to follow the Google style
- Prepare full coverage of modules related to model loading and affine transformations with unit-tests
- There should be only one model on the screen at a time
- The program must provide the ability to:
    - Load a wireframe model from an obj file (vertices and surfaces list support only).
    - Translate the model by a given distance in relation to the X, Y, Z axes.
    - Rotate the model by a given angle relative to its X, Y, Z axes.
    - Scale the model by a given value.
- GUI implementation, based on any GUI library with API for C89/C99/C11 <br/>
  * For Linix: GTK+, CEF, Qt<br/>
  * For Mac: GTK+, Nuklear, raygui, microui, libagar, libui, IUP, LCUI, CEF, Qt
- The graphical user interface must contain:
    - A button to select the model file and a field to output its name.
    - A visualisation area for the wireframe model.
    - Button/buttons and input fields for translating the model.
    - Button/buttons and input fields for rotating the model.
    - Button/buttons and input fields for scaling the model.
    - Information about the uploaded model - file name, number of vertices and edges.
- The program must correctly process and allow user to view models with details up to 100, 1000, 10,000, 100,000, 1,000,000  vertices without freezing (a freeze is an interface inactivity of more than 0.5 seconds)

## Settings

- The program must allow customizing the type of projection (parallel and central)
- The program must allow setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
- The program must allow choosing the background color
- Settings must be saved between program restarts

## Record

- The program must allow saving the captured (rendered) images as bmp and jpeg files.
- The program must allow recording small screencasts by a special button - the current custom affine transformation of the loaded object into gif-animation (640x480, 10fps, 5s)
