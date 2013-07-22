# -*- coding: utf-8 -*-
def setup
  set_window_size(640, 768)
  # set_window_pos(0, 0)

  @shapes = []
  @shapes << Circle.new(Pos.new(320, 200))

  set_background(255, 255, 255)
  
  Console.init(20, 560)
end

def update
  @shapes.each {|s| s.update}
end

def draw
  @shapes.each {|s| s.draw}

  Console.draw

  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
  text(DebugInfo.window, 10, 30)
  text(DebugInfo.mouse, 10, 45)
end

# ----------------------------------------------------------

class Pos < Struct.new(:x, :y)
  def lengh_square(ax, ay)
    (x - ax)**2 + (y - ay)**2
  end
end

class Circle
  def initialize(pos)
    @pos = pos
    @dragged = false
  end

  def update
    Console.p(@pos)

    if !@dragged
      if Input.mouse_press?(0)
        # ドラッグ位置のずれ補正が必要
        @dragged = true if (@pos.lengh_square(Input.mouse_x, Input.mouse_y) < 50**2)
      end
    else
      if !Input.mouse_down?(0)
        @dragged = false
      else
        @pos.x = Input.mouse_x
        @pos.y = Input.mouse_y
      end
    end
  end
  
  def draw
    set_fill
    set_color(87, 25, 122)
    circle(@pos.x, @pos.y, 50)
  end
end

# class Draggable
#   def initialize(pos, radius)
#   end

#   def start?(x, y)
#   end
  
# end

class Console
  def self.init(x, y, width = 600, height = 190, line_num = 13)
    @x = x
    @y = y
    @width = width
    @height = height
    @line_num = line_num
    @text = ""
  end

  def self.p(*args)
    @text = args.map{|obj| obj.inspect }.join("\n") + "\n" + @text
  end

  def self.draw
    @text = @text.split("\n")[0, @line_num].join("\n")
    
    set_fill
    set_color(255, 255, 255)
    rect(@x, @y, @width, @height)

    set_no_fill
    set_color(0, 0, 0)
    rect(@x, @y, @width, @height)

    text(@text, @x + 10, @y + 20)
  end
end

