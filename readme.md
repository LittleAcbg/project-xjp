# Project-xjp (Codeforces)

运行方式：

```bash
. xjp.sh
```

按提示操作即可，先输入 Section、Division，再输入随机种子即可开始。

## Section 1: Contest mode

有 10\*10\*6、15\*15\*10、20\*20\*12、30\*30\*15 四档。30\*30\*15 为隐藏档，输入 `0` 来进入。

接着输入 Interaction prob，表示出现交互题的概率是百分之多少，如果只想要传统题可以输入 `0`。

按上下左右键并 `<Enter>` 来移动，`0` 提交评测，`quit` 退出，`=` 暂停计时器（同时会隐藏题目）。

## Section 2: Training mode

有 10\*10、15\*15、20\*20、30\*30 四档。30\*30 为隐藏档，输入 `0` 来进入。

无限题目，无限时间，统计连续 AC 表现。

`quit` 退出，`skip` 跳过题目，没有实现暂停功能。

每题只有一次提交机会，若 WA 则会显示正确答案。

## Section 3: Interaction Training

题目会有两个不同的混淆项，例如 `己已已己已巳己己`。

所有操作与 Section 2: Training mode 一致。

## Section 4: Duel

> 开发中，暂不开放\
> 2026.05.23 立项

双方对战，找到对方隐藏的错别字。已经搜查过的点会变成错别字标记。

## 自定义题目

对于 Section 2 与 Section 1 的传统题，你只需要改变 `xjp.settings` 中的内容，每行一组两个字符串表示题目，至少一组。有自动排列。

对于 Section 3 与 Section 1 的交互题，你只需要改变 `interaction.settings` 中的内容，每行一组三个字符串表示题目，至少一组。有自动排列。

对于 Section 4，你只需要改变 `duel.settings` 中的内容，每行一组三个字符串表示题目，**至少两组**。三个字符串依次作为题面、答案和混淆项，无自动排列，不同顺序须输入多组。

题目中不能有空格或空串，空格为分隔符，**每行的字符串须互不相同**。

# Changelog

### 2026.05.25

> xjp-v1.1.2-linux

修复了一些代码细节，并进行了本文档细节的调整。

### 2026.05.24

> xjp-v1.1.0-linux

在 Section 1: Contest mode 中加入交互题支持。

相应地调整了本文档。

在本文档的 Changelog 部分加入了版本信息。

### 2026.05.23

> xjp-v1.1-alpha-linux (Pre-release)

Section 4: Duel 立项。功能：两玩家对战，找到对方隐藏的错别字。

Section 3: Interaction Training 完成。

相应地调整了本文档。

### 2026.05.22

> xjp-v1.0.0-linux

更新了 Codeforces 的 UI，现在要选择 Section 而不是用 `-1` 代表 Training。并进行了一些细节的调整。

Section 3: Interaction 立项。功能：有两个不同的混淆项。

相应地调整了本文档。

### 2026.05.20

添加了 Training mode，包含正确答案显示，帮助你更好地训练！

将退出指令从 `:aq` 改为 `quit`。

修复了 `xjp.settings` 中出现特殊字符 `"`、`\` 会编译错误的问题。

`xjp.settings` 不再需要结束符。

进行了一些本文档的文本修缮。

### 2026.05.19

现在 WA 后还可以再次提交。

### 2026.05.15

Project-xjp 正式启动！目前功能：自定义题目，暂停计时器。