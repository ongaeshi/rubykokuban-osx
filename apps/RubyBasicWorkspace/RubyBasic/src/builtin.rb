module DebugInfo
  def self.fps
    "#{format("%3.2f", get_frame_rate)} fps"
  end

  def self.window
    "window_pos: (#{window_pos_x}, #{window_pos_y}), size: (#{window_width}, #{window_height})"
  end

  def self.mouse
    str = "mouse: "
    str += format("(%4d, %4d)", Input.mouse_x, Input.mouse_y)

    # press?
    str += " press?: "
    str += (0..2).map {|v|
      Input.mouse_press?(v) ? '1' : '0'
    }.join('')

    # down?
    str += " down?: "
    str += (0..2).map {|v|
      Input.mouse_down?(v) ? '1' : '0'
    }.join('')

    # release?
    str += " release?: "
    str += (0..2).map {|v|
      Input.mouse_release?(v) ? '1' : '0'
    }.join('')

    str
  end
end

module Console
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
