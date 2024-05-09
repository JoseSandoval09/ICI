public void processImage() {
    int width = this.getImage().getWidth();
    int height = this.getImage().getHeight();
    int i, j;
    int[][] pixels = new int[width][height];

    this.convertToGrayscale();

    BufferedImage temp = this.getImage();

    for(i = 0; i < width; i++) {
      for(j = 0; j < height; j++) {
        Color color = new Color(this.getImage().getRGB(i, j));
        pixels[i][j] = color.getRed();
      }
    }

    for(i = 0; i < (width - 2); i++) {
      for (j = 0; j < (height - 2); j++) {
        int pixelX = (pixels[i][j] * this.filterX[0][0]) + (pixels[i + 1][j] * this.filterX[0][1]) + (pixels[i + 2][j] * this.filterX[0][2]) +
          (pixels[i][j + 1] * this.filterX[1][0]) + (pixels[i + 1][j + 1] * this.filterX[1][1]) + (pixels[i + 2][j + 1] * this.filterX[1][2]) +
          (pixels[i][j + 2] * this.filterX[2][0]) + (pixels[i + 1][j + 2] * this.filterX[2][1]) + (pixels[i + 2][j + 2] * this.filterX[2][2]);

        int pixelY = (pixels[i][j] * this.filterY[0][0]) + (pixels[i + 1][j] * this.filterY[0][1]) + (pixels[i + 2][j] * this.filterY[0][2]) +
          (pixels[i][j + 1] * this.filterY[1][0]) + (pixels[i + 1][j + 1] * this.filterY[1][1]) + (pixels[i + 2][j + 1] * this.filterY[1][2]) +
          (pixels[i][j + 2] * this.filterY[2][0]) + (pixels[i + 1][j + 2] * this.filterY[2][1]) + (pixels[i + 2][j + 2] * this.filterY[2][2]);

        int pixel = (int) Math.sqrt(pixelX * pixelX + pixelY * pixelY);

        if(pixel < 0) {
          pixels[i][j] = 0;
        }
        else if(pixel > 255) {
          pixels[i][j] = 255;
        }
        else {
          pixels[i][j] = pixel;
        }
      }
    }

    for(i = 0; i < width; i++) {
      for(j = 0; j < height; j++) {
        Color color = new Color(pixels[i][j], pixels[i][j], pixels[i][j]);
        int rgb = color.getRGB();
        temp.setRGB(i, j, rgb);
      }
    }

    this.setImage(temp);
  }
  public void applyPrewitt() {
    int[][] filterX = {
      { -1, 0, 1 },
      { -1, 0, 1 },
      { -1, 0, 1 }
    };
    int[][] filterY = {
      { -1, -1, -1 },
      { 0, 0, 0 },
      { 1, 1, 1 }
    };

    this.setConvolutionMatrix(filterX, filterY);
    this.processImage();
  }
}
int[][] filterX = {
    { 1, 0 },
    { 0, -1 }
  };
  int[][] filterY = {
    { 0, 1 },
    { -1, 0 }
  };
//
  