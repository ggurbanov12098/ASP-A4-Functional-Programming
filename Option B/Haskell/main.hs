main :: IO ()
main = do
    customStringInput <- getLine
    let n = read customStringInput :: Int
    print $ playGame [1..n] 0

playGame :: [Int] -> Int -> Int
playGame [x] _ = x
playGame nums step = playGame newNums (step + 1)
  where
    positions = [1..]
    toDelete pos
      | step `mod` 3 == 0 = pos `mod` 2 == 0
      | step `mod` 3 == 1 = pos `mod` 2 == 1
      | step `mod` 3 == 2 = pos `mod` 3 == 0
    newNums = [num | (num, pos) <- zip nums positions, not (toDelete pos)]