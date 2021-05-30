echo "git add " 
git add .
echo "Enter the commit :"
read commit
echo "git commit"
git commit -m "$commit"
git push -u
