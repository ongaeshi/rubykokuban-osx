def setup
  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  @hue = 0
end

def update
  @hue += 1
  @hue = 0 if @hue >= 255
end

def draw
  x = 10; y = 50
  description("Color.new", x, y)
  c = Color.new(128, 128, 128)
  set_color(c.r, c.g, c.b)
  circle(x + 32, y + 32, 32)

  x = 110; y = 50
  description("Color.hex", x, y)
  set_color(Color.hex(0xD27EB3))
  circle(x + 32, y + 32, 32)

  x = 210; y = 50
  description("Color.hsb", x, y)
  set_color(Color.hsb(@hue, 200, 255))
  circle(x + 32, y + 32, 32)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
end

# ----------------------------------------------------------

def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

