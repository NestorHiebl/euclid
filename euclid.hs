import System.Environment
import Prelude hiding (gcd)
import Numeric.Natural

gcd :: Natural -> Natural -> Natural
gcd 0 0 = 0
gcd a 0 = a
gcd a b =  gcd b' (a' `mod` b')
    where
        -- Ignore argument order
        a' = max a b
        b' = min a b

gcdFold = foldr (gcd) 0

handleArgs :: [String] -> String
handleArgs args = case length args of 
    0 -> "Usage: Provide arbitrary natural numbers to find GCD of"
    n -> show $ gcdFold $ map (stringToNat) args
    where
        stringToNat s = (read s) :: Natural

main = getArgs >>= putStrLn . handleArgs

