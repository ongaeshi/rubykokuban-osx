module Console2
  # FONT_HEIGHT = 13 # can't use CONSTANT at inner block
  @font_height = 13 

  def self.init(x, y, width = 600, height = 190)
    @x = x
    @y = y
    @width = width
    @height = height
    @line_num = (height / @font_height).to_i
    @text = []
    # p @line_num
  end

  def self.p(*arg)
    if arg.instance_of?(Array)
      @text += arg.map{|obj| obj.inspect }
    else
      @text << arg.inspect
    end
    arg
  end

  def self.draw
    @text = @text[@text.length - @line_num, @line_num] if @text.length > @line_num
    
    set_fill
    set_color(255, 255, 255)
    rect(@x, @y, @width, @height)

    set_no_fill
    set_color(0, 0, 0)
    rect(@x, @y, @width, @height)

    @text.each_with_index do |text, index|
      text(text, @x + 5, @y + @font_height + @font_height * index)
    end
  end

  def self.clear
    @text = []
  end
end

module Kernel
  alias org_p p

  def self.p(*args)
    org_p(*args)
    Console2.p(*args)
  end
end

RADIUS = 100
SPEED  = 1

def setup

  set_window_size(640, 480)
  # set_window_pos(0, 0)
  set_background(255, 255, 255)

  @y = RADIUS
  @speed = SPEED

  Console2.init(20, 0, 600, 400)

  test_rand
end

def update
  @y += @speed
  @speed *= -1.0 if @y > 480 - RADIUS || @y < RADIUS

  p 1
  p(nil)
  p("abcdeffgABCDEFG!#$%'&('&')()0(=)~|", @y, {a: 1, b: 2}) if Input.mouse_down?(0)
  Console2.clear if Input.mouse_down?(2)
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
  Console2.draw
end

# ----------------------------------------------------------

def test_rand
  srand
  srand(10)
  # p rand()
  p rand(100).inspect
  Console2.p rand(100).inspect
  # Console2.p(rand(100).inspect)
  # p rand(100..200)
end
