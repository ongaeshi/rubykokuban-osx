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
end

def draw
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

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
end

# ----------------------------------------------------------
def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

  

