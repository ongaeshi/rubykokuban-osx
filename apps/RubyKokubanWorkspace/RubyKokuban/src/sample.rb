def setup
  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  @image  = Image.load("sample.png")
  @image2 = Image.load("sample.png")
end

def update
  @image.rotate90 if Input.mouse_press?(0)
  @image2.rotate90(-1) if Input.mouse_down?(2)
end

def draw
  # Draw image
  x = 10; y = 100
  description("draw(x, y)", x, y)
  set_color(255, 255, 255)
  @image.draw(x, y)

  x = 110; y = 100
  description("blend color", x, y)
  set_color(128, 255, 128)
  @image2.draw(x, y)

  x = 210; y = 100
  description("resize", x, y)
  set_color(255, 255, 255)
  @resize_image = @image.clone.resize(40, 40) unless @resize_image
  @resize_image.draw(x, y)

  x = 310; y = 100
  description "crop!", x, y
  set_color(255, 255, 255)
  @crop_bang_image = @image.clone.crop!(10, 10, 30, 30) unless @crop_bang_image
  @crop_bang_image.draw(x, y)

  x = 410; y = 100
  description "crop", x, y
  set_color(255, 255, 255)
  @crop_image = @image.crop(10, 10, 30, 30) unless @crop_image
  @crop_image.draw(x, y)

  x = 510; y = 100
  description("rotate90", x, y)
  set_color(255, 255, 255)
  @rotate_image = @image.clone.rotate90 unless @rotate_image
  @rotate_image.draw(x, y)

  x = 10; y = 200
  description("mirror", x, y)
  set_color(255, 255, 255)
  @mirror_image = @image.clone.mirror(false, true) unless @mirror_image
  @mirror_image.draw(x, y)

  x = 110; y = 200
  description("clone", x, y)
  set_color(255, 255, 255)
  @clone_image = @mirror_image.clone.resize(80, 64) unless @clone_image
  @clone_image.draw(x, y)

  x = 200; y = 200
  description("draw(x,y,w,h)", x, y)
  set_color(255, 255, 255)
  @image.draw(x, y, 80, 80)

  x = 340; y = 200
  description("draw_sub", x, y)
  set_color(255, 255, 255)
  @image.draw_sub(x + 32, y,      32, 32,  0,  0)
  @image.draw_sub(x + 32, y + 32, 32, 32, 32,  0)
  @image.draw_sub(x,      y + 32, 32, 32,  0, 32)
  @image.draw_sub(x,      y,      32, 32, 32, 32)

  x = 440; y = 200
  description("draw_sub2", x, y)
  set_color(255, 255, 255)
  @image.draw_sub(x + 32, y,      32, 32,  0,  0, 12, 12)
  @image.draw_sub(x + 32, y + 32, 32, 32, 32,  0, 12, 12)
  @image.draw_sub(x,      y + 32, 32, 32,  0, 32, 12, 12)
  @image.draw_sub(x,      y,      32, 32, 32, 32, 12, 12)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
  text("width: #{@image.width}, height: #{@image.height}", 10, 50)
end

# ----------------------------------------------------------

def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

