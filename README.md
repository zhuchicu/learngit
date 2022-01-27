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
