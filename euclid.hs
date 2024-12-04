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

coprimes :: Natural -> Natural -> Bool
coprimes a b = (gcd a b) == 1

-- Cardinality of {0 < i < n | gcd(i,n) == 0}
numCoprimesOfBase :: Natural -> Natural
numCoprimesOfBase n = foldr (inc) 0 [1..n]
    where
        inc m acc = if coprimes n m then acc + 1 else acc

handleArgs :: [String] -> String
handleArgs args = case length args of 
    0 -> "Usage: Provide arbitrary natural numbers to find GCD of"
    n -> show $ gcdFold $ map (stringToNat) args
    where
        stringToNat s = (read s) :: Natural

main = getArgs >>= putStrLn . handleArgs

