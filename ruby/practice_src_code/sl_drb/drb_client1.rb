#---
# Excerpted from "Programming Ruby 1.9 and 2.0",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/ruby4 for more book information.
#---
require 'drb'

class Listener
  include DRbUndumped

  def update(value)
    puts value
  end
end

DRb.start_service
counter = DRbObject.new(nil, "druby://localhost:9001")

listener = Listener.new
counter.add_observer(listener)
counter.run

