def setup
  set_window_size(640, 480)
  set_window_pos(1150, 100)     # @todo Delete at sample
  set_background(255, 255, 255)
  # set_fill
end

def update
end

def draw
  colorbar(0, 0, Color::White, 'White')
  colorbar(1, 0, Color::Black, 'Black')
  colorbar(2, 0, Color::Gray,  'Gray')
  colorbar(3, 0, Color::Red,   'Red')
  colorbar(4, 0, Color::Green, 'Green')
end

# ----------------------------------------------------------

def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

def assert(val)
  raise if !val
end

def colorbar(ix, iy, color, text)
  x = ix * 50
  y = iy * 50

  set_color(0, 0, 0)
  text(text, x + 5, y + 15)

  set_color(color)
  # rect(x, y, 50, 50)
  rect(x + 5, y + 20, 40, 30)
end
  

