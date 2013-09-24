def setup
  set_window_size(640, 480)
  set_background(255, 255, 255)

  # Console.init(0, 0)
  set_fill

  @image_org = Image.load("sample.png")
  @image = @image_org.clone

  # (0...@image.width).each do |x|
  #   (0...@image.height).each do |y|
  #     c = @image.color(x, y)
  #     b = c.brightness
  #     @image.set_color(x, y, Color.new(b, b, b, c.a))
  #   end
  # end

  @image.each_pixels do |x, y|
    c = self.color(x, y)        # Can't '@image.color(x, y)'. Why?
    b = c.brightness
    self.set_color(x, y, Color.new(b, b, b, c.a))
  end

  @image.update
end

def draw
  # Draw image
  x = 10; y = 50
  description("original", x, y)
  set_color(Color::White)
  @image_org.draw(x, y)

  x = 110; y = 50
  description("gray", x, y)
  set_color(Color::White)
  # (1..10).each do |x|
  #   (0...@image.width).each do |x|
  #     (0...@image.height).each do |y|
  #       c = @image.color(x, y)
  #       b = c.brightness
  #       @image.set_color(x, y, Color.new(b, b, b, c.a))
  #     end
  #   end
  # end
  (1..10).each do |x|
    @image.each_pixels do |x, y, c|
      b = c.brightness
      set_color(x, y, Color.new(b, b, b, c.a))
    end
  end
  @image.update
  @image.draw(x, y)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
end

# ----------------------------------------------------------
def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

  

