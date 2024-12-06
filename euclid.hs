import System.Environment (getArgs)
import Numeric.Natural (Natural)

gcd_simple :: Natural -> Natural -> Natural
gcd_simple 0 0 = 0
gcd_simple a 0 = a
gcd_simple a b =  gcd_simple b' (a' `mod` b')
    where
        -- Ignore argument order
        a' = max a b
        b' = min a b

gcdFold :: [Natural] -> Natural
gcdFold = foldr (gcd_simple) 0

coprimes :: Natural -> Natural -> Bool
coprimes a b = (gcd_simple a b) == 1

-- Euler phi function - naive, innefficient implementation
eulerPhi :: Natural -> Natural
eulerPhi n = foldr (inc) 0 [1..n]
    where
        inc m acc = if coprimes n m then acc + 1 else acc

handleArgs :: [String] -> String
handleArgs args = case length args of 
    0 -> "Usage: Provide arbitrary natural numbers to find GCD of"
    _ -> show $ gcdFold $ map (stringToNat) args
    where
        stringToNat s = (read s) :: Natural

main :: IO ()
main = getArgs >>= putStrLn . handleArgs

