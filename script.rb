require "csv"

CSV.open("plik2.csv", "wb") do |csv|
    for i in 1..100
        tab = []
        [0, 25, 50, 75, 95, 99, 99.7, 100].each do |percent|
            [10000, 50000, 100000, 500000, 1000000].each do |size|
                tab << `./sorting_algorithms #{percent} #{size} #{percent == 100 ? "reverse" : ""}`.chomp.to_i
            end
        end
        csv << tab
        puts "Linijka myk #{i}"
    end
end