/* Contains and returns the projection matrix
 * switching between orthogonal and perspective
 * zoom */

#ifndef THE_FOURTH_AGE_PROJECTION_H
#define THE_FOURTH_AGE_PROJECTION_H

#define NEAREST 0.0f
#define FAREST  1.0f
#define FOV_3D  90.0f

/* Includes the math library to be able to make vector and matrix calculations */
#include "../../libs/maths/quasar/matrix/mat4.h"

/* For debug log. */
#include <stdio.h>

/* Contains the matrix mode. 0 = Orthogonal, 1 = Perspective */
int     mode;

/* The matrices to be returned and calculated */
mat4    projPerspectiveMatrix;
mat4    projOrthogonalMatrix;

/* Current FOV to be changed by zooming */
float   fov;

/* To save the aspect ratio of the resolution */
float   aspectRatio;

/* Initializes variables and matrices to default; to be called at start of program */
void    PRJ_initProjection      (float  aspRat);

/* Changes mode to 0 */
void    PRJ_setOrthogonal       ();

/* Changes mode to 1 */
void    PRJ_setPerspective      ();

/* Changes FOV on zoom, only if mode = 0 */
void    PRJ_zoom                (float  yoffset);

/* Returns the current projection matrix only if mode = 0 */
mat4    PRJ_returnProjection    ();

#endif //THE_FOURTH_AGE_PROJECTION_H
