# DSA Mastery — Claude Code setup

A self-contained DSA learning system run by **Kera**, your mentor. Claude Code reads
the state files at the start of each session and writes your progress back at the end,
so nothing is ever lost to a forgotten save.

## What's in here
- `CLAUDE.md` — the operating manual. **Auto-loaded every session** — you don't paste it anywhere.
- `CURRICULUM.md` — the dependency-ordered path with a concrete problem ladder per pattern.
- `PROGRESS.md` — your live tracker (mastery levels, schedule, session log).
- `PATTERN_JOURNAL.md` — your growing "when you see ___ → consider ___" recognition guide.
- `MISTAKE_JOURNAL.md` — root-cause log + scheduled re-tests.
- `REVISION_QUEUE.md` — date-stamped spaced repetition.
- `.claude/commands/` — your slash commands (below).
- `solutions/` — where your code goes.

## One-time setup
You need Node.js installed (you already have it). Then:

```bash
# 1. Install Claude Code (if you haven't)
npm install -g @anthropic-ai/claude-code

# 2. Put this folder's contents at the root of your dsa folder, then:
cd /path/to/dsa

# 3. Make it a git repo — the commit history becomes your progress log
git init
git add -A
git commit -m "init: DSA mastery system"

# 4. Launch the mentor
claude
```

On the **first** launch, `PROGRESS.md` is empty, so Kera runs a short diagnostic and
will ask three things: your **primary coding language**, your **weekly hours**, and your
**start date**. Answer those and it builds your real schedule.

## Daily loop
- **Start:** run `claude`, then type `/continue`. Kera reads your state, shows the
  dashboard, folds in anything due for revision, and picks up where you left off.
- **During:** solve problems into `solutions/`. Use `STUCK` to get exactly one hint
  level at a time. Use `/drill` to train pattern recognition.
- **End:** type **`/endsession`**. This is the one habit that matters — it writes your
  progress to the files and commits. (Kera also updates files as you go, but
  `/endsession` guarantees a clean save + commit.)

## Commands
| Command | What it does |
|---|---|
| `/continue` | Resume from your current topic; fold in due revisions. |
| `/dashboard` | Show mastery %, current topic, what's due, schedule status. |
| `/revise` | Closed-book, interleaved spaced-repetition session. |
| `/drill` | Mixed set — name the pattern only, no coding. Builds recognition. |
| `/interview` | Realistic mock interview with a hire/no-hire verdict. |
| `/logmistake` | Log the current mistake with root cause + a scheduled re-test. |
| `/endsession` | Save all state files and commit. **Do this every session.** |
| `STUCK` | Advance the hint ladder by one level (not a slash command — just type it). |

> Slash commands here use the `.claude/commands/` format. The newer
> `.claude/skills/<name>/SKILL.md` format also works if you prefer to migrate later;
> both create `/command` shortcuts.

## The three rules that make this work
1. **End every session with `/endsession`** (or your progress sits only in chat).
2. **"Solved" = accepted on LeetCode**, not "looks right." Kera can run code locally,
   but the judge is the final word.
3. **Volume still matters.** This organizes the grind and stops you forgetting — it
   doesn't replace the ~150–300 problems to your goal.
