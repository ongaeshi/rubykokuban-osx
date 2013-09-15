def setup
  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  @image = Image.load("sample.png")
  @image2 = Image.load("sample.png")
end

def update
  @image.rotate90 if Input.mouse_press?(0)
  @image2.rotate90(-1) if Input.mouse_down?(2)
end

def draw
  # image
  description("normal", 0, 100)
  set_color(255, 255, 255)
  @image.draw(0, 100)

  description("blend color", 100, 100)
  set_color(128, 255, 128)
  @image2.draw(100, 100)

  description("resize", 200, 100)
  set_color(255, 255, 255)
  @resize_image = Image.load("sample.png").resize(40, 40) unless @resize_image
  @resize_image.draw(200, 100)

  description "crop!", 300, 100
  set_color(255, 255, 255)
  @crop_bang_image = Image.load("sample.png").crop!(10, 10, 30, 30) unless @crop_bang_image
  @crop_bang_image.draw(300, 100)

  description "crop", 400, 100
  set_color(255, 255, 255)
  @crop_image = @image.crop(10, 10, 30, 30) unless @crop_image
  @crop_image.draw(400, 100)

  description("rotate90", 500, 100)
  set_color(255, 255, 255)
  @rotate_image = Image.load("sample.png").rotate90 unless @rotate_image
  @rotate_image.draw(500, 100)

  description("mirror", 0, 200)
  set_color(255, 255, 255)
  @mirror_image = Image.load("sample.png").mirror(false, true) unless @mirror_image
  @mirror_image.draw(0, 200)

  description("clone", 100, 200)
  set_color(255, 255, 255)
  @clone_image = @mirror_image.clone.resize(80, 64) unless @clone_image
  @clone_image.draw(100, 200)

  x = 200; y = 200
  description("draw(x,y,w,h)", x, y)
  set_color(255, 255, 255)
  @image.draw(x, y, 80, 80)

  x = 330; y = 200
  description("draw_sub", x, y)
  set_color(255, 255, 255)
  @image.draw_sub(x + 32, y,      32, 32,  0,  0)
  @image.draw_sub(x + 32, y + 32, 32, 32, 32,  0)
  @image.draw_sub(x,      y + 32, 32, 32,  0, 32)
  @image.draw_sub(x,      y,      32, 32, 32, 32)

  x = 430; y = 200
  description("draw_sub2", x, y)
  set_color(255, 255, 255)
  @image.draw_sub(x + 32, y,      32, 32,  0,  0, 12, 12)
  @image.draw_sub(x + 32, y + 32, 32, 32, 32,  0, 12, 12)
  @image.draw_sub(x,      y + 32, 32, 32,  0, 32, 12, 12)
  @image.draw_sub(x,      y,      32, 32, 32, 32, 12, 12)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
  text(DebugInfo.window, 10, 30)
  text(DebugInfo.mouse, 10, 45)
  text("width: #{@image.width}, height: #{@image.height}", 10, 70)
end

# ----------------------------------------------------------

def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

