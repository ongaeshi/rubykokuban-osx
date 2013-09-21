def setup
  set_window_size(640, 480)
  set_window_pos(1150, 100)
  set_background(255, 255, 255)

  @hue = 0
  @rate = 0
end

def ease_in(t)
  v = 3.0 * t ** 3 - 2.0 * t ** 2
  (v > 0.0) ? v : -v
end

def ease_out(t)
  1.0 - ease_in(1.0 - t)
end

def update
  @hue += 1
  @hue = 0 if @hue >= 255

  @rate += 0.01
  @rate = 0.0 if @rate >= 1.0
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
  
  x = 310; y = 50
  description("clone", x, y)
  clone_color = c.clone
  clone_color.r = 180
  clone_color.g = 90
  clone_color.b = 180
  clone_color.a = 128
  set_color(c)
  circle(x, y + 32, 32)
  set_color(clone_color)
  circle(x + 32, y + 32, 32)

  x = 410; y = 50
  description("to_hex", x, y)
  c = Color.new(100, 255, 0)
  set_color(0, 0, 0)
  text("(#{c.r},#{c.g},#{c.b})", x, y + 25)
  text("0x#{c.to_hex.to_s(16)}", x, y + 50)

  x = 10; y = 150
  description("base", x, y)
  c = Color.hex(0x3DB680)
  set_color(c)
  circle(x + 32, y + 32, 32)

  x = 110; y = 150
  description("invert", x, y)
  set_color(c.invert)
  circle(x + 32, y + 32, 32)

  x = 210; y = 150
  description("normalize", x, y)
  set_color(c.normalize)
  circle(x + 32, y + 32, 32)

  x = 310; y = 150
  description("lerp(white, #{@rate})", x, y)
  set_color(c.lerp(Color.new(255, 255, 255), @rate))
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

