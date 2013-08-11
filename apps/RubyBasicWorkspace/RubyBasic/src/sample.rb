RADIUS = 100
SPEED  = 1

def setup
  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  @y = RADIUS
  @speed = SPEED

  Console.init(20, 260, 600, 200)

  test_rand
end

def update
  @y += @speed
  @speed *= -1.0 if @y > 480 - RADIUS || @y < RADIUS

  # p 1
  # p(nil)
  p("abcdeffgABCDEFG!#$%'&('&')()0(=)~|", @y, {a: 1, b: 2}) if Input.mouse_down?(0)
  Console.clear if Input.mouse_down?(2)
end

def draw
  # text
  set_color(0, 0, 0)
  text("Hello world!", 268, 251)

  # shape
  set_fill
  set_line_width(1)
  set_color(150, 195, 17)
  circle(150, @y, RADIUS)

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
  text(DebugInfo.window, 10, 30)
  text(DebugInfo.mouse, 10, 45)

  # Console
  Console.draw
end

# ----------------------------------------------------------

def test_rand
  srand
  srand(10)
  p rand()
  p rand(100)
  # p rand(100..200)
end
