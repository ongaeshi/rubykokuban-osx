def setup
  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  @image = Image.load("sample.png")
  
  @image2 = Image.load("sample.png")

  @image3 = Image.load("sample.png").resize(40, 40)

  @crop_bang_image = Image.load("sample.png").crop!(10, 10, 50, 50)
  
  @crop_image = @image.crop(10, 10, 50, 50)
  
  @rotate_image = Image.load("sample.png").rotate90

  @mirror_image = Image.load("sample.png").mirror(false, true)

end

def update
    @image.rotate90 if Input.mouse_press?(0)
    @image2.rotate90(-1) if Input.mouse_down?(2)
end

def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
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
  @image3.draw(200, 100)

  description "crop!", 300, 100
  set_color(255, 255, 255)
  @crop_bang_image.draw(300, 100)

  description "crop", 400, 100
  set_color(255, 255, 255)
  @crop_image.draw(400, 100)

  description("rotate90", 500, 100)
  set_color(255, 255, 255)
  @rotate_image.draw(500, 100)

  description("mirror", 0, 200)
  set_color(255, 255, 255)
  @mirror_image.draw(0, 200)



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
