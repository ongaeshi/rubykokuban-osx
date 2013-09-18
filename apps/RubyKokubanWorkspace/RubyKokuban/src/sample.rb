def setup
  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  color = Color.new(1, 2, 3)
  p color.r, color.g, color.b, color.a

  @image  = Image.load("sample.png")
  @image2 = Image.load("sample.png")
end

def update
  @image.rotate90 if Input.mouse_press?(0)
  @image2.rotate90(-1) if Input.mouse_down?(2)
  @screen_image = Image.grab_screen(50, 90, 80, 80)

  # if Input.mouse_press?(2)
  #   Image.grab_screen(0, 0, window_width, window_height).save("screenshot.png")
  # end
end

def draw
  x = 10; y = 100
  description("Color.hex", x, y)
  c = Color.hex(0xD27EB3)
  set_color(c.r, c.g, c.b)
  circle(x + 32, y + 32, 32)

  x = 110; y = 100
  description("Color.hsb", x, y)
  c = Color.hsb(25, 255, 120)
  set_color(c.r, c.g, c.b)
  circle(x + 32, y + 32, 32)

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

