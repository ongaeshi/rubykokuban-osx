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
