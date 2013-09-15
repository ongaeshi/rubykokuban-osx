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
  # image
  set_color(255, 255, 255)
  @image.draw(100, 100)

  set_color(128, 255, 128)
  @image2.draw(100 + 50, 200)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
  text(DebugInfo.window, 10, 30)
  text(DebugInfo.mouse, 10, 45)
end

# ----------------------------------------------------------

def test_rand
  srand
  srand(10)
  p rand()
  p rand(100)
  # p rand(100..200)
end
