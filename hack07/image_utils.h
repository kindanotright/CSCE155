/**
 * Author: Megan Bogatz
 * 2023-10-12
*/
/**
 * A structure that represents a single pixel value using
 * the RGB (red-blue-green) color model.  Each integer
 * value is in the range [0, 255].
 */
typedef struct {
  int red;
  int green;
  int blue;
} Pixel;
 
/**
 * Loads an image file specified by the given file path/name.
 * The height and width are indicated in the two pass-by-reference variables.
 * The image is returned as a two-dimensional array of Pixel values
 * of dimension (height x width) where the pixel at [0][0] corresponds to
 * the top-left most pixel value.
 */
Pixel **loadImage(const char *filePath, int *height, int *width);
 
/**
 * Saves the given image (which is assumed to have the same format as in
 * loadImage() and is of the given height x width) to the file specified
 * by the given path/name.
 */
void saveImage(const char *filePath, Pixel **image, int height, int width);
 
/**
 * Creates a deep copy of the given image.
 */
Pixel ** copyImage(Pixel **image, int height, int width);
 
/**
 * Flips the given image horizontally in-place.
 */
void flipHorizontal(Pixel **image, int height, int width);
 
/**
 * Flips the given image vertiacally in-place.
 */
void flipVertical(Pixel **image, int height, int width);
 
/**
 * Rotates the given image 90 degrees clockwise and returns a new rotated image.
 * The original image remains unaltered.
 */
Pixel ** rotateClockwise(Pixel **image, int height, int width)
