Q1 [how-to-sparsely-checkout-only-one-single-file-from-a-git-repository](https://stackoverflow.com/questions/2466735/how-to-sparsely-checkout-only-one-single-file-from-a-git-repository/2466755#2466755)

可以拉取单个文件，但是 `git status` 时将会提示 repo 不完整，不能实现单个文件的更新和提交。
~~~
$ git clone -n git://path/to/the_repo.git --depth 1
$ cd the_repo
$ git checkout HEAD name_of_file
~~~

Q2 Git 仓库完整迁移（code+log）

[git clone --mirror和git clone --bare之间的区别是什么](https://www.imooc.com/wenda/detail/579025)
~~~Python
$ git clone --bare <旧的 git 地址>  # 在当前目录下产生一个 xxx.git 的文件夹，任何远程分支（在克隆的远程中）和其他引用都被完全忽略。
$ cd xxx.git  # 推送裸版本库到新的地址
$ git push --mirror <新的 git 地址>
$ rm xxx.git # 是否删掉无影响，只是说明它没有用了而已
$ git clone <新的 git 地址>  # 代码迁移就成功了，接下来就可以使用新的地址了
~~~


Q3 如果本地仓库已经存在提交，在 push 到远程仓库之前需要先 pull 更新到远端最新版本，但远端又有新的提交，为了避免 merge 操作，可以使用 git rebase 命令使提交更顺滑。

~~~bash
# Step 1：在合并远程分支之前，将本地提交 rebase 到远程分支的基础之上
git pull --rebase origin master
# Step 2：出现冲突，解决完冲突后
git add .
git rebase --continue
# Step 3：push 本地仓库到远程
git push origin master
~~~

Q4 合并提交：整理本地多个提交历史，保持提交整洁

使用 git rebase 合并多个连续提交

例如，下列命令将会打开一个交互式界面，列出最近 3 个提交记录：

~~~bash
git rebase -i HEAD~3
~~~