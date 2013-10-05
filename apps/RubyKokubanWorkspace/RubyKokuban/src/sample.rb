def setup
  set_window_size(640, 480)
  set_background(255, 255, 255)
  set_fill

  @image = Image.load("sample.png")

  @image_gray = @image.clone
  @image_gray.each_pixels do |x, y|
    c = @image_gray.color(x, y)
    b = c.brightness
    @image_gray.set_color(x, y, Color.new(b, b, b, c.a))
  end
  @image_gray.update

  @mosaic_power = 1
end

def update
  @mosaic_power -= 0.05
  @mosaic_power = 16 if @mosaic_power < 1

  if Input.mouse_down?(0)
    @screenshotter ||= ScreenShotter.new(30)
    @screenshotter.update
  end
end

def draw
  x = 510; y = 50
  description("set_background_test", x, y)
  set_background(Color::Color::DarkSeaGreen)
  # set_background(128, 128, 128)

  # Draw image
  x = 10; y = 50
  description("original", x, y)
  set_color(Color::White)
  @image.draw(x, y)

  x = 110; y = 50
  description("gray", x, y)
  set_color(Color::White)
  @image_gray.draw(x, y)

  x = 210; y = 50
  description("mosaic", x, y)
  power = @mosaic_power
  @image.each_pixels(power, power) do |i, j|
    set_color(@image.color(i, j))
    rect(x + i, y + j, power, power)
  end

  x = 310; y = 50
  description("dotting", x, y)
  @image.each_pixels(4, 4) do |i, j|
    set_color(@image.color(i + 2, j + 2))
    circle(x + i + 2, y + j + 2, 2)
  end

  x = 410; y = 50
  description("set_color_test", x, y)
  set_color(255, 0, 0, 64)
  circle(x + 10, y + 10, 10)  

  set_color(Color::Blue, 128)
  circle(x + 20, y + 10, 10)  

  set_color(33, 32, 110, 128)
  circle(x + 30, y + 10, 10)  

  x = 10; y = 150
  description("set_color_hex_test", x, y)

  set_color_hex(0xF3C759)
  rect(x, y + 10, 40, 40)

  set_color_hex(0x3DB680, 200)
  rect(x + 20, y + 10, 40, 40)

  set_color_hex(0xDA6272, 100)
  rect(x + 40, y + 10, 40, 40)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
end

# ----------------------------------------------------------
def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

class ScreenShotter
  def initialize(interval = 30)
    @index    = 0
    @frame    = 0
    @interval = interval
  end

  def update
    if @frame % @interval == 0
      Image.grab_screen.save("screenshot#{@index.to_s}.png")
      @index += 1
    end
    @frame += 1
  end
end

